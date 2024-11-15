// Motor pins
int motor1Pin1 = 3;  // PWM pin
int motor1Pin2 = 4;  // Digital pin
int enable1Pin = 5;  // PWM pin

int motor2Pin1 = 2; // PWM pin
int motor2Pin2 = 7; // Digital pin
int enable2Pin = 6;  // PWM pin

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



void moveForward() {
  analogWrite(enable1Pin, 220);
  analogWrite(enable2Pin, 220);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  //setMotorSpeed(120);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW); 

  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  //setMotorSpeed(120);
}

void turnRight() {
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW); 
  //setMotorSpeed(120);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW); 
  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);   
}

void setMotorSpeed(int speed) {
  // Map speed (0-100) to PWM range (0-255)
  int pwmSpeed = map(speed, 0, 100, 0, 255);
  
  // Set PWM duty cycle for motor speed control
  analogWrite(enable1Pin, pwmSpeed);
  analogWrite(enable2Pin, pwmSpeed);
  
  // For debugging, print the speed value being set
  Serial.println("Motor speed set to: " + String(pwmSpeed)); 
}


void loop() {

    if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
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
      setMotorSpeed(speed);//speed
    }
  

    }  
  
}


