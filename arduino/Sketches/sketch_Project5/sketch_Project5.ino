#include <Servo.h>
Servo myServo;
int const potPin = A0; 
int potVal;
int angle;


void setup() {
  myServo.attach(11);
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);
  for(int i = 25; i < 170; i++){
    myServo.write(15*i);
   digitalWrite(2,LOW);
    delay(180);
    if(i%2 == 0){
      digitalWrite(2,HIGH);
      delay(180);
      
  }
  }
}
