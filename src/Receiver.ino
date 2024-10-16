#include <WiFi.h>
#include <esp_now.h>

#define ENA 14
#define ENB 27
#define IN1 26
#define IN2 25
#define IN3 33
#define IN4 32
#define carSpeed 150
#define slowSpeed 75  // Speed when slowing down

void forward(int speed) { 
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}

void slowDown() {
  forward(slowSpeed);  // Move forward with a reduced speed
  Serial.println("Slowing Down");
}

// Callback function to handle incoming ESP-NOW data
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  String receivedSignal = String((char*)incomingData);
  Serial.print("Received: ");
  Serial.println(receivedSignal);

  if (receivedSignal == "green") {
    forward(carSpeed);
  } else if (receivedSignal == "yellow") {
    slowDown();
  } else if (receivedSignal == "red") {
    stop();
  }
}

void setup() { 
  Serial.begin(115200);
  
  // Set GPIOs as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();

  // Initialize WiFi in STA mode
  WiFi.mode(WIFI_STA);
  
  // Initialize ESP-NOW
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESP-NOW Initialized successfully");
  } else {
    Serial.println("ESP-NOW Initialization failed");
    ESP.restart();
  }
  
  // Register the receive callback
  esp_now_register_recv_cb(OnDataRecv);
} 

void loop() {
  // Placeholder loop function, no additional processing required for receiving ESP-NOW data
}
