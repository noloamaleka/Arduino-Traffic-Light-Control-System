#include <RadioHead.h>

#include <RH_ASK.h>

RH_ASK rf_driver;

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 150

int Echo = A4;
int Trig = A5;

int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void forward() { 
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}

void left() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  Serial.println("Left");
}

void right() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
} 

int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance = Fdistance / 58;       
  return (int)Fdistance;
}

void setup() { 
  Serial.begin(9600);
  if (!rf_driver.init()) {
    Serial.println("RF Module Init Failed");
  }
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
} 

void loop() {
  uint8_t buf[10];
  uint8_t buflen = sizeof(buf);

  if (rf_driver.recv(buf, &buflen)) { 
    String receivedSignal = (char*)buf;
    Serial.print("Received: ");
    Serial.println(receivedSignal);

    if (receivedSignal == "green") {
      forward();
    } else if (receivedSignal == "yellow") {
      left();
    } else if (receivedSignal == "red") {
      stop();
    }
  }

  // Collision avoidance logic can be integrated here as well.
  middleDistance = Distance_test();

  if (middleDistance <= 20) {     
    stop();
    delay(500);                         

    rightDistance = Distance_test();
    delay(500);  
    leftDistance = Distance_test();
    delay(500);

    if (rightDistance > leftDistance) {
      right();
      delay(360);
    } else if (rightDistance < leftDistance) {
      left();
      delay(360);
    } else if ((rightDistance <= 20) || (leftDistance <= 20)) {
      back();
      delay(180);
    } else {
      forward();
    }
  } else {
    forward();
  }
  delay(1000); // Next loop iteration here
}
