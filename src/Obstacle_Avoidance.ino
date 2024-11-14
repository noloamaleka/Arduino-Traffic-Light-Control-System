#define Trig 12
#define Echo 13
#define ENA 5
#define ENB 6
#define IN1 3
#define IN2 4
#define IN3 2
#define IN4 7

float cm; //Distance variable
float temp; //

void setup() {
  Serial.begin(9600);

  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);  // Motor A Enable
  pinMode(ENB, OUTPUT);  // Motor B Enable

  // Enable motors without PWM (set ENA and ENB to HIGH)
  digitalWrite(ENA, HIGH);  // Motor A is enabled
  digitalWrite(ENB, HIGH);  // Motor B is enabled
}

void loop() {
  // Measure distance using ultrasonic sensor
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  temp = float(pulseIn(Echo, HIGH));
  cm = (temp * 17) / 1000;

  // Decide motor movement based on distance
  if (cm < 30 && cm > 10) {
    back();  // Move backward if distance is between 10 and 30 cm
    delay(500);
    Left();  // Turn left after moving back
    delay(200);
  }
  if (cm >= 30) {
    forward();  // Move forward if distance is greater than or equal to 30 cm
    delay(100);
  }
  if (cm < 10) {
    STOP();  // Stop motors if distance is less than 10 cm
  }

  // Print distance for debugging
  //Serial.print("Echo =");
  //Serial.print(temp);
  //Serial.print(" | | Distance = ");
  //Serial.print(cm);
  //Serial.println(" cm");
  //delay(100);
}

// Move forward
void forward() {
  // Motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor B forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Forward");
}

// Move backward
void back() {
  // Motor A backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Motor B backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}

// Turn left
void Left() {
  // Motor A backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Motor B forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Left");
}

// Turn right
void Right() {
  // Motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Motor B backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Right");
}

// Stop all motors
void STOP() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("STOP");
}
