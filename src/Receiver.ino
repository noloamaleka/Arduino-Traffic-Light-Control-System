#include <WiFi.h>
#include <esp_now.h>

// Callback function to handle incoming ESP-NOW data
void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
  String receivedSignal = String((char*)incomingData);
  Serial.print("Received: ");
  Serial.println(receivedSignal);

  // You can add more responses here based on the signal received
  if (receivedSignal == "green") {
    Serial.println("Green signal received.");
  } else if (receivedSignal == "yellow") {
    Serial.println("Yellow signal received.");
  } else if (receivedSignal == "red") {
    Serial.println("Red signal received.");
  }
}

void setup() { 
  Serial.begin(9600);

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

