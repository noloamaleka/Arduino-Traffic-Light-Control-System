#include <RadioHead.h>

#include <RH_ASK.h>

RH_ASK rf_driver;

void setup() {
  Serial.begin(9600);
  if (!rf_driver.init()) {
    Serial.println("RF Module Init Failed");
  }
}

void loop() {
  // Simulating traffic light signals
  String trafficLightState = "green";  // Change this to "yellow" or "red" for other tests

  const char* msg;
  if (trafficLightState == "green") {
    msg = "green";
    Serial.println("Sending: GREEN");
  } else if (trafficLightState == "yellow") {
    msg = "yellow";
    Serial.println("Sending: YELLOW");
  } else if (trafficLightState == "red") {
    msg = "red";
    Serial.println("Sending: RED");
  }

  rf_driver.send((uint8_t *)msg, strlen(msg));
  rf_driver.waitPacketSent();

  // Wait for a while before sending the next signal
  delay(1000);
}
