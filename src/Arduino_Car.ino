
// Motor pins
int motor1Pin1 = 4;  // PWM pin
int motor1Pin2 = 7;  // Digital pin
int enable1Pin = 2;  // PWM pin

int motor2Pin1 = 5; // PWM pin
int motor2Pin2 = 6; // Digital pin
int enable2Pin = 3;  // PWM pin

void setup() {
  Serial.begin(115200); // Start serial communication with ESP32

  // Motor pins setup
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    Serial.println(command.length());
    command.trim();
    
    Serial.println(command);
    Serial.println(command.length());
    if (command == "forward") {
      Serial.println("IN forward method");
      moveForward();
    } 
    else if (command == "left") {
      turnLeft();
    } 
    else if (command == "right") {
      turnRight();
    } 
    else if (command == "stop") {
      stopMotors();
    }
    else if (command.startsWith("speed:")) {
      int speed = command.substring(6).toInt();
      setMotorSpeed(speed);
    }
  }
}

void moveForward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void turnRight() {
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW); 
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);   
}

void setMotorSpeed(int speed) {
  analogWrite(enable1Pin, speed);
  analogWrite(enable2Pin, speed);
}
