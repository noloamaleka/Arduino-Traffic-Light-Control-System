
#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "BC STUDENTS";
const char* password = "belgiumcampus";

// Create an instance of the WebServer on port 80
WebServer server(80);

String valueString = String(0);

void handleRoot() {
  const char html[] PROGMEM = R"rawliteral(
  <!DOCTYPE HTML><html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <style>
      html {
        font-family: Helvetica;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        margin: 0;
        background-color: #20232a; /* Navy background */
      }

      body {
        text-align: center;
        padding: 20px;
        color: white;
      }

      h1 {
        font-size: 32px;
        margin-bottom: 20px;
        color: #ffffff;
      }

      .button {
        -webkit-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        background-color: #4CAF50; /* Green */
        border: none;
        color: white;
        padding: 15px 40px;
        font-size: 20px;
        margin: 10px;
        cursor: pointer;
        border-radius: 12px; /* Rounded corners */
        transition: all 0.3s ease;
        box-shadow: 0 4px 6px rgba(0,0,0,0.2); /* Button shadow */
        width: 200px; /* Set a specific width */
      }

      .buttonStop {
        background-color: red; /* Red */
      }

      .button:hover {
        background-color: #45a049; /* Darker green on hover */
        box-shadow: 0 8px 12px rgba(0, 255, 0, 0.5); /* Green glow effect */
      }

      .buttonStop:hover {
        background-color: #cc0000; /* Darker red on hover */
        box-shadow: 0 8px 12px rgba(255, 0, 0, 0.5); /* Red glow effect */
      }

      .heading {
        font-size: 24px;
        margin-top: 20px;
        color: #dddddd;
      }

      .container {
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
      }

      .button-row {
        display: flex;
        justify-content: center;
        align-items: center;
      }

      input[type="range"] {
        width: 80%;
        margin-top: 20px;
      }

      .speedText {
        font-size: 20px;
        color: #ffffff;
        margin-top: 20px;
      }

      .spacing {
        margin-top: 40px; /* Space between sections */
      }
    </style>
    <script>
      function moveForward() { fetch('/forward'); }
      function moveLeft() { fetch('/left'); }
      function stopRobot() { fetch('/stop'); }
      function moveRight() { fetch('/right'); }

      function updateMotorSpeed(pos) {
        document.getElementById('motorSpeed').innerHTML = pos;
        fetch(`/speed?value=${pos}`);
      }
    </script>
  </head>
  <body>
    <div class="container">
      <h1>V2I: Traffic Management Navigation System</h1>

      <!-- Green Button Section -->
      <div class="heading">State: Green</div>
      <div class="button-row">
        <button class="button" onclick="moveForward()">GO</button>
      </div>

      <!-- Left and Right Buttons Section -->
      <div class="button-row">
        <button class="button" onclick="moveLeft()">LEFT</button>
        <button class="button" onclick="moveRight()">RIGHT</button>
      </div>

      <!-- Red Button Section -->
      <div class="spacing">
        <div class="heading">State: Red</div>
        <div class="button-row">
          <button class="buttonStop button" onclick="stopRobot()">STOP</button>
        </div>
      </div>

      <!-- Motor Speed Section -->
      <div class="spacing">
        <div class="speedText">
          Motor Speed: <span id="motorSpeed">0</span>
        </div>
        <input type="range" min="0" max="100" step="25" id="motorSlider" oninput="updateMotorSpeed(this.value)" value="0"/>
      </div>
    </div>
  </body>
  </html>)rawliteral";
  server.send(200, "text/html", html);
}

void handleForward() {
  Serial.println("forward");
  server.send(200);
}

void handleLeft() {
  Serial.println("left");
  server.send(200);
}

void handleStop() {
  Serial.println("stop");
  server.send(200);
}

void handleRight() {
  Serial.println("right");
  server.send(200);
}

void handleSpeed() {
  if (server.hasArg("value")) {
    valueString = server.arg("value");
    int value = valueString.toInt();
    Serial.println("speed:" + String(value));
  }
  server.send(200);
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
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

  // Define routes
  server.on("/", handleRoot);
  server.on("/forward", handleForward);
  server.on("/left", handleLeft);
  server.on("/stop", handleStop);
  server.on("/right", handleRight);
  server.on("/speed", handleSpeed);

  // Start the server
  server.begin();
}

void loop() {
  server.handleClient();
}
