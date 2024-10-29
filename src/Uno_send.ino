int enableRightMotor = 3;
int rightMotorPin1 = 4;
int rightMotorPin2 = 5;
int enableLeftMotor = 2;
int leftMotorPin1 = 6;
int leftMotorPin2 = 7;

#define MAX_SPEED 50 // Max speed (0-255)
#define SLOW_SPEED 30 // Speed for slow down 

void setup() {
    Serial.begin(9600); // Serial Monitor for Arduino

    // Set motor pins as outputs
    pinMode(enableRightMotor, OUTPUT);
    pinMode(rightMotorPin1, OUTPUT);
    pinMode(rightMotorPin2, OUTPUT);
    pinMode(enableLeftMotor, OUTPUT);
    pinMode(leftMotorPin1, OUTPUT);
    pinMode(leftMotorPin2, OUTPUT);
}

void loop() {
    // Read from ESP32 via Serial2
    if (Serial.available()) { // Check Serial for incoming signals
        String signal = Serial.readStringUntil('\n'); // Read incoming signal
        Serial.println(signal); // Print to Serial Monitor

        // Control motors based on received signals
        if (signal.equals("MOVE FORWARD")) {
            moveForward(MAX_SPEED); // Move forward at max speed
        } else if (signal.equals("SLOW DOWN")) {
            slowDown(); // Reduce speed
        } else if (signal.equals("STOP")) {
            stopMotors(); // Stop the motors
        }
    }
}

void moveForward(int speed) {
    analogWrite(enableRightMotor, speed); // Set speed for the right motor
    digitalWrite(rightMotorPin1, HIGH); // Set the right motor direction
    digitalWrite(rightMotorPin2, LOW);
    
    analogWrite(enableLeftMotor, speed); // Set speed for the left motor
    digitalWrite(leftMotorPin1, HIGH); // Set the left motor direction
    digitalWrite(leftMotorPin2, LOW);
}

void slowDown() {
    moveForward(SLOW_SPEED); // Move forward at the slow speed
}

void stopMotors() {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
}

