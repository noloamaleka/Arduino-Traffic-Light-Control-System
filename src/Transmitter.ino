#include <WiFi.h>
#include <esp_now.h>

#define GREEN_LED  21
#define YELLOW_LED  22
#define RED_LED  23

// Receiver MAC Address 
uint8_t receiverAddress[] = {0xEC, 0x62, 0x60, 0x9C, 0xCA, 0x5C}; 

void setup() {
  // Set GPIOs as outputs
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Initialize Serial Monitor
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

  // Add peer (receiver)
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void sendTrafficSignal(const char* message) {
  esp_now_send(receiverAddress, (uint8_t *)message, strlen(message));
}

void loop() {
  // Green light
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  sendTrafficSignal("green"); // Send green signal to the receiver
  delay(5000); // 5-second delay before switching

  // Yellow light
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  sendTrafficSignal("yellow"); // Send yellow signal to the receiver
  delay(2500); // 2.5-second delay before switching

  // Red light
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  sendTrafficSignal("red"); // Send red signal to the receiver
  delay(5000); // 5-second delay before switching

  // Yellow light before switching back to green
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  sendTrafficSignal("yellow"); // Send yellow signal to the receiver
  delay(5000); // 5-second delay before switching
}
