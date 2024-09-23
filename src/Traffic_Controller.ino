//Traffic light controller pins into GPIO21, GPIO22, GPIO23 on esp32
 
#define GREEN_LED  21
#define YELLOW_LED  22
#define RED_LED  23
 
void setup() {
  pinMode(GREEN_LED,OUTPUT);
  pinMode(YELLOW_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
}
 
void loop() {
  //Green light
  digitalWrite(GREEN_LED,HIGH);
  digitalWrite(YELLOW_LED,LOW);
  delay(5000); //5 second delay before switching
 
  //Yellow light
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(YELLOW_LED,HIGH);
  delay(2500); //2.5 second delay before switching
 
  //Red light
  digitalWrite(YELLOW_LED,LOW);
  digitalWrite(RED_LED,HIGH);
  delay(5000); //5 second delay delay before switching
 
  //Yellow light
  digitalWrite(RED_LED,LOW);
  digitalWrite(YELLOW_LED,HIGH);
  delay(5000); // 5 second delay before switching
}
