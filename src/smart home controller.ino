#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "pages.h"

#define bulb1     32
#define bulb2     5   // works
#define bulb3     33
#define bulb4     25
#define bulb5     26
#define socket1   27
#define socket2   14
#define socket3   12
#define socket4   22
#define socket5   21

// Replace with network credentials
const char* ssid     = "yourssid";
const char* password = "yourpasswd";

// login credentials
const char* http_username = "admin";
const char* http_password = "admin";

const char* PARAM_INPUT_1 = "state";

// device ports/ pins
bool bulb1_State = 0;
bool bulb2_State = 0;
bool bulb3_State = 0;
bool bulb4_State = 0;
bool bulb5_State = 0;
bool socket1_State = 0;
bool socket2_State = 0;
bool socket3_State = 0;
bool socket4_State = 0;
bool socket5_State = 0;


//WiFiServer server(80);
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void notifyClients(bool device_state) {
  ws.textAll(String(device_state));
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    if (strcmp((char*)data, "device1") == 0) {
      bulb1_State = !bulb1_State;
      notifyClients(bulb1_State);
      Serial.print("bulb1: ");
      Serial.println(bulb1_State);
    } else if (strcmp((char*)data, "device2") == 0) {
      bulb2_State = !bulb2_State;
      notifyClients(bulb2_State);
      Serial.print("bulb2: ");
      Serial.println(bulb2_State);
    } else if (strcmp((char*)data, "device3") == 0) {
      bulb3_State = !bulb3_State;
      notifyClients(bulb3_State);
      Serial.print("bulb3: ");
      Serial.println(bulb3_State);
    } else if (strcmp((char*)data, "device4") == 0) {
      bulb4_State = !bulb4_State;
      notifyClients(bulb4_State);
      Serial.print("bulb4:");
      Serial.println(bulb4_State);
    } else if (strcmp((char*)data, "device5") == 0) {
      bulb5_State = !bulb5_State;
      notifyClients(bulb5_State);
      Serial.print("bulb5: ");
      Serial.println(bulb5_State);
    } else if (strcmp((char*)data, "device6") == 0) {
      socket1_State = !socket1_State;
      notifyClients(socket1_State);
      Serial.print("socket1: ");
      Serial.println(socket1_State);
    } else if (strcmp((char*)data, "device7") == 0) {
      socket2_State = !socket2_State;
      notifyClients(socket2_State);
      Serial.print("socket2: ");
      Serial.println(socket2_State);
    } else if (strcmp((char*)data, "device8") == 0) {
      socket3_State = !socket3_State;
      notifyClients(socket3_State);
      Serial.print("socket3: ");
      Serial.println(socket3_State);
    }  else if (strcmp((char*)data, "device8") == 0) {
      socket4_State = !socket4_State;
      notifyClients(socket4_State);
      Serial.print("socket4: ");
      Serial.println(socket4_State);
    }  else if (strcmp((char*)data, "device8") == 0) {
      socket5_State = !socket5_State;
      notifyClients(socket5_State);
      Serial.print("socket5: ");
      Serial.println(socket5_State);
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

String processor(const String& var) {
  Serial.println(var);
  if (var == "STATE") {
    if (bulb1_State) {
      return "ON";
    }
    else {
      return "OFF";
    }
  }
  return String();
}

void setup()
{
    Serial.begin(115200);
    pinMode(bulb1, OUTPUT);      // set pinMode
    pinMode(bulb2, OUTPUT);      // set pinMode
    pinMode(bulb3, OUTPUT);      // set pinMode
    pinMode(bulb4, OUTPUT);      // set pinMode
    pinMode(bulb5, OUTPUT);      // set pinMode
    pinMode(socket1, OUTPUT);      // set pinMode
    pinMode(socket2, OUTPUT);      // set pinMode
    pinMode(socket3, OUTPUT);      // set pinMode
    pinMode(socket4, OUTPUT);      // set pinMode
    pinMode(socket5, OUTPUT);      // set pinMode
    

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    initWebSocket();
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    if(!request->authenticate(http_username, http_password))
      return request->requestAuthentication();
    request->send_P(200, "text/html", index_html, processor);
  });

  server.on("/logout", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(401);
  });
   server.on("/logged-out", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", logout_html, processor);
  });
  // Send a GET request to <ESP_IP>/update?state=<inputMessage>
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    if(!request->authenticate(http_username, http_password))
      return request->requestAuthentication();
    String inputMessage;
    String inputParam;
    // GET input1 value on <ESP_IP>/update?state=<inputMessage>
    if (request->hasParam(PARAM_INPUT_1)) {
      inputMessage = request->getParam(PARAM_INPUT_1)->value();
      inputParam = PARAM_INPUT_1;
//      digitalWrite(output, inputMessage.toInt());
    }
    else {
      inputMessage = "No message sent";
      inputParam = "none";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });
  server.begin();

}

void loop(){
   ws.cleanupClients();
  digitalWrite(bulb1, bulb1_State);
//  Serial.print("Bulb1: ");
//  Serial.println(bulb1_State);
  digitalWrite(bulb2, bulb2_State);
  digitalWrite(bulb3, bulb3_State);
  digitalWrite(bulb4, bulb4_State);
  digitalWrite(bulb5, bulb5_State);
  digitalWrite(socket1, socket1_State);
  digitalWrite(socket2, socket2_State);
  digitalWrite(socket3, socket3_State);
  digitalWrite(socket4, socket4_State);
  digitalWrite(socket5, socket5_State);

}