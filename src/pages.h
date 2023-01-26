const char index_html[] PROGMEM = R"rawliteral( 
<!DOCTYPE HTML><html>
<head>
  <title>Smart Home</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <script src="./js/bootstrap.js"></script>
  <link rel="stylesheet" type="text/css" href="./css/bootstrap.css">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/css/bootstrap.min.css" integrity="sha384-xOolHFLEh07PJGoPkLv1IbcEPTNtaed2xpHsD9ESMhqIYd0nLMwNLD69Npy4HI+N" crossorigin="anonymous">
   <script src="https://cdn.jsdelivr.net/npm/jquery@3.6.1/dist/jquery.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.2/dist/js/bootstrap.bundle.min.js"></script>
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.0/css/all.css" integrity="sha384-lZN37f5QGtY3VHgisS14W3ExzMWZxybE1SJSEsQp9S+oqd12jhcu+A56Ebc1zFSJ" crossorigin="anonymous">
  <script src="https://code.jquery.com/jquery-3.6.3.min.js" integrity="sha256-pvPw+upLPUjgMXY0G+8O0xUf+/Im1MZjXxxgOcBQBXU=" crossorigin="anonymous"></script>

<style>
.switch {
  position: relative;
  display: inline-block;
  width: 40px;
  height: 20px;
}

.switch input { 
  opacity: 0;
  width: 0;
  height: 0;
}

.slider {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: #ccc;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  height: 15px;
  width: 15px;
  left: 4px;
  bottom: 2.5px;
  background-color: white;
  -webkit-transition: .4s;
  transition: .4s;
}

input:checked + .slider {
  background-color: #2196F3;
}

input:focus + .slider {
  box-shadow: 0 0 1px #2196F3;
}

input:checked + .slider:before {
  -webkit-transform: translateX(20px);
  -ms-transform: translateX(20px);
  transform: translateX(20px);
}

/* Rounded sliders */
.slider.round {
  border-radius: 20px;
}

.slider.round:before {
/*  border-radius: 50px;*/
}
  </style>

</head>
<body>
  <!-- A grey horizontal navbar that becomes vertical on small screens -->
<nav class="navbar navbar-expand-sm bg-dark navbar-dark justify-content-center">
   <!-- Toggler/collapsibe Button -->
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#collapsibleNavbar">
    <span class="navbar-toggler-icon"></span>
  </button>

  <!-- Links -->
  <div class="collapse navbar-collapse" id="collapsibleNavbar">
  <ul class="navbar-nav ">
    <form class="form-inline" action="/action_page.php">
    <input class="form-control mr-sm-2" type="text" placeholder="Search">
    <button class="btn btn-success" type="submit">Search</button>
  </form>
    <li class="nav-item">
      <a class="nav-link" href="#"><i class="fa fa-solid fa-gears" aria-hidden="true"></i>Settings</a>
    </li>
    <li class="nav-item">
      <a class="nav-link" href="#"><i class="fa fa-solid fa-bell" aria-hidden="true"></i></a>
    </li>
    <li class="nav-item">
      <a class="nav-link" href="#"><i class="fa fa-regular fa-user" aria-hidden="true"></i></a>
    </li>
    <li class="nav-item">
      <a class="nav-link" href="#" onclick="logoutButton()">Logout</a>
    </li>
  </ul>
</div>

</nav>
  <!-- <div class="topnav">
    <h1>Smart Home</h1>
  </div> -->
  <div class="container-fluid">
    <div class="row">
        <div class="col-sm-8">
          <div class="row">
            <div class="card  col-sm-12 bg-light">
              <div class="card-body ">
                <h2>Hello, Scarlett!</h2>
                <p class=" card-text"> welcome Home!, The air quality is good & fresh you can go out today.</p>
                <i class="fa fa-thermometer-three-quarters" aria-hidden="true"></i><span> +25 C</span> <span> Outdoor temperature</span>
                <h6>Fuzzy cloudy weather</h6>
              </div>
            </div>
            <div class="col-sm-12">
              <div class="row">
                <div class="m-2 p-2 col-sm-5"><span> Scarlet's Home</span> </div>
                <div class="m-2 p-2 col-sm-5"><span class="p-2 mr-4">36%</span> <i class="fa fa-thermometer-three-quarters" aria-hidden="true"></i><span class="p-2 mr-2">15.C</span> 
                  <div class="btn-group">
                    <button type="button" class="btn btn-primary">Living Room</button>
                    <button type="button" class="btn btn-primary dropdown-toggle dropdown-toggle-split" data-toggle="dropdown">
                      <span class="caret"></span>
                    </button>
                    <div class="dropdown-menu">
                      <a class="dropdown-item" href="#">Living Room</a>
                      <a class="dropdown-item" href="#">Kitchen</a>
                      <a class="dropdown-item" href="#">Dining</a>
                      <a class="dropdown-item" href="#">Kids Room</a>
                      <a class="dropdown-item" href="#">Master bedroom</a>
                    </div>
                  </div>
                </div>
                <div class="card shadow m-2 p-2 col-sm-3 ">
                  <!-- Rounded switch -->
                    <label class="switch">
                      <input type="checkbox" id="fridge" name="fridge">
                      <span class="slider round"></span>
                    </label>
                  <div class="card-body ">
                     
                    <p>Refridgerator</p>
                  </div>
                </div>
                <div class="card shadow m-2 p-2 col-sm-3 bg-info">

                   <!-- Rounded switch -->
                    <label class="switch">
                      <input type="checkbox" id ="lights" name="lights"/>
                      <span class="slider round"></span>
                    </label>
                  <div class="card-body ">
                    <i class="fa fa-lightbulb-o" aria-hidden="true"></i> <span>Lights</span>
                  </div>
                </div>
                <div class="card shadow m-2 p-2 col-sm-3 ">
                    <!-- Rounded switch -->
                    <label class="switch">
                      <input type="checkbox" id="air_conditioner" name="air_conditioner">
                      <span class="slider round"></span>
                    </label>
                  <div class="card-body ">
                    <p>Air Conditioner</p>
                  </div>
                </div>
                <div class="card  shadow m-2 p-2 col-sm-3 ">
                  <label class="switch">
                      <input type="checkbox" id="temperature" name="temperature"/>
                      <span class="slider round"></span>
                    </label>
                  <div class="card-body ">
                    
                    <p>Temperature</p>
                  </div>
                </div>
              </div>
            </div>
            <div class="card  col-sm-12 bg-light">
              <div class="card-body ">
                <h5>Air condition Settings</h5>
                <p class=" card-text">The air quality is good & fresh you can go out today.</p>
                <span> +25 C</span> <span> Indoor temperature</span>
              </div>
          </div>
          </div>
        </div>
        <div class="col-sm-4">
          <div class="card  col bg-light">
            <div class="card-header"><h4 class="card-title">My Devices</h4></div>
            <!-- <button class="button bg-light"> ON</button> -->
              <div class="card-body ">
                <div class="row">
                  <div class="card m-2 p-2 col-sm-5 bg-primary">
                   
                    <!-- Rounded switch -->
                    <label class="switch">
                      <input type="checkbox" id= "Lounge" name="lounge"/>
                      <span class="slider round"></span>
                    </label>
                      <div class="card-body ">
                        <span id="state">%STATE%</span>
                         <p class="card-title">Lounge </p>
                      </div>
                  </div>
                  <div class="card m-2 p-2 col-sm-5 bg-warning">
                   
                    <!-- Rounded switch -->
                    <label class="switch">
                      <input type="checkbox" id="Kitchen" name="kitchen"/>
                      <span class="slider round"></span>
                    </label>
                      <div class="card-body ">
                        <span id="state">%STATE%</span>
                        <p class="card-title">Kitchen</p>
                      </div>
                  </div>
                  <div class="card m-2 p-2 col-sm-5 bg-danger">
                    
                    <!-- Rounded switch -->
                    <label class="switch" >
                      <input type="checkbox" id="fridge" name="fridge">
                      <span class="slider round"></span>
                    </label>
                      <div class="card-body ">
                        <span id="state">%STATE%</span>
                        <p class="card-title">fridge</p>
                      </div>
                  </div>
                  <div class="card m-2 p-2 col-sm-5 bg-info">
                    
                    <!-- Rounded switch -->
                    <label class="switch">
                      <input type="checkbox" id="Oven" name="oven">
                      <span class="slider round"></span>
                    </label>
                      <div class="card-body ">
                        <span id="state">%STATE%</span>
                        <p class="card-title">Oven</p>
                      </div>
                  </div>
                </div>
                <div class="row">
                  <!-- <h5>Members</h5> -->
                  <div class="card m-2 p-2 col-sm-12 bg-white">
                      <div class="card-body ">
                        <h5> Weather Information</h5>
                        <div class="" id="weatherData"></div>
                      </div>
                  </div>
                  <!-- <h5> Power Consumed</h5> -->
                  <div class="card m-2 col-sm-12 bg-primary">
                      <div class="card-body ">
                        <h5>Daily Planner</h5>
                      </div>
                  </div>
                </div>
              </div>
          </div>
      </div>
    </div>
  </div>
 <!--  <div class="content">
    <div class="card">
      <h2>Output - GPIO 2</h2>
      <p class="state">state: <span id="state">%STATE%</span></p>
      <p><button id="button" class="button">Toggle</button></p>
    </div>
  </div> -->

</body>
</html>
<script>
  var gateway = `ws://${window.location.hostname}/ws`;
  var websocket;
  // weather information handling
  var url = "http://api.openweathermap.org/data/2.5/weather?q=Uganda,UG&APPID=3cec7531c28849f76b696f0a0e8f524c";
  window.addEventListener('load', onLoad);
  function initWebSocket() {
    console.log('Trying to open a WebSocket connection...');
    websocket = new WebSocket(gateway);
    websocket.onopen    = onOpen;
    websocket.onclose   = onClose;
    websocket.onmessage = onMessage; // <-- add this line
  }
  function onOpen(event) {
    console.log('Connection opened');
  }
  function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
  }
  function onMessage(event) {
    var state;
    if (event.data == "1"){
      state = "ON";
    }
    else{
      state = "OFF";
    }
    document.getElementById('state').innerHTML = state;
  }
  function onLoad(event) {
     initWebSocket();
    initButton();
    fetch(url)
    .then(function (response) {
      // JSON data response
        return response.json();
    })
    .then(function (data) {
      appendData(data);

    })
    .catch(function(err) {
      // catch errors if any
      console.log('error: ' + err);
    })

    function appendData(data) {
      var mainContainer = document.getElementById("weatherData");
      var div = document.createElement("div");
      div.innerHTML= (data["name"]+ ','+ " "+ data["sys"]["country"]+ ' '+"Cloudy"+ data["main"]["temp"]+ "*C"+ ' '+ "Feels Like "+ data["main"]["feels_like"]+ ' '+ data["weather"][0]['main']+ ' '+ data["weather"][0]["description"] + ' '+ "Humidty "+ data["main"]["humidity"]+"%"+ ' '+ data["main"]["pressure"]+ " Pa" +' '+"Visibility "+ data["visibility"]);
      // ('Json object = '+ ''+ 'Temperature: ' + data["main"]["temp"] +'Pressusre: '+ data["main"]["pressure"]+ "Humidity: " + data["main"]["humidity"]+ "Wind Speed: "+ data["wind"]["speed"]);
      mainContainer.appendChild(div);
      // for debugging
      console.log(data);
      
    }
  }
  function initButton() {
  
    $('input[name=lounge]').change(function() {
      if ($(this).is(':checked')){
        console.log("lounge is checked..");
        device1();
      }else {
        console.log("not checked");
      }
    });
    $('input[name=fridge]').change(function() {
      if ($(this).is(':checked')){
        console.log("fridge is checked..");
        device2();
      }else {
        console.log("not checked");
      }
    });
    $('input[name=oven]').change(function() {
      if ($(this).is(':checked')){
        console.log("oven is checked..");
        device3();
      }else {
        console.log("not checked");
      }
    });
    $('input[name=kitchen]').change(function() {
      if ($(this).is(':checked')){
        console.log("kitchen is checked..");
      }else {
        console.log("not checked");
        device4();
      }
    });
    $('input[name=temperature]').change(function() {
      if ($(this).is(':checked')){
        console.log("temperature is checked..");
        device5();
      }else {
        console.log("not checked");
      }
    });$('input[name=air_conditioner]').change(function() {
      if ($(this).is(':checked')){
        console.log("air_conditioner is checked..");
        device6();
      }else {
        console.log("not checked");
      }
      $('input[name=lights]').change(function() {
      if ($(this).is(':checked')){
        console.log("lights is checked..");
        device7();
      }else {
        console.log("not checked");
      }
    });
    });
    // document.getElementById('fridge').addEventListener('click', device2);
    // document.getElementById('fridge').addEventListener('click', device3);
    // document.getElementById('kitchen').addEventListener('click', device4);
  }
  function device1(){
    websocket.send('device1');
  }
  function device2(){
    websocket.send('device2');
  }
  function device3(){
    websocket.send('device3');
  }
  function device4(){
    websocket.send('device4');
  }
  function device5(){
    websocket.send('device5');
  }
  function device6(){
    websocket.send('device6');
  }
  function device7(){
    websocket.send('device7');
  }
  function device8(){
    websocket.send('device8');
  }
  function device9(){
    websocket.send('device9');
  }
  function device10(){
    websocket.send('device10');
  }
  function logoutButton() {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/logout", true);
  xhr.send();
  setTimeout(function(){ window.open("/logged-out","_self"); }, 1000);
}
</script>
)rawliteral";

const char logout_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
  <p>Logged out or <a href="/">return to homepage</a>.</p>
  <p><strong>Note:</strong> close all web browser tabs to complete the logout process.</p>
</body>
</html>
)rawliteral";