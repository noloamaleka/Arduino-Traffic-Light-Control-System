#include <WiFi.h>
#include <esp_now.h>

#define RXp2 16
#define TXp2 17

// Change the signature to include esp_now_recv_info
void onDataReceive(const esp_now_recv_info* sender, const uint8_t* data, int data_len);

void setup() {
    Serial.begin(115200);          // Serial Monitor for ESP32
    Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2); // Initialize Serial2 with specified pins

    // Initialize WiFi in STA mode
    WiFi.mode(WIFI_STA);
    
    // Initialize ESP-NOW
    if (esp_now_init() == ESP_OK) {
        Serial.println("ESP-NOW Initialized successfully");
    } else {
        Serial.println("ESP-NOW Initialization failed");
        ESP.restart();
    }

    // Set up a callback function to handle incoming messages
    esp_now_register_recv_cb(onDataReceive);
}

void loop() {
    // No need for continuous operations in loop()
}

// Callback function to handle received data
void onDataReceive(const esp_now_recv_info* sender, const uint8_t *data, int data_len) {
    String signal = String((char*)data, data_len); // Convert received data to String
    Serial2.println(signal); // Forward signal to Arduino
    Serial.println("Received: " + signal); // Print to Serial Monitor for debugging
}
