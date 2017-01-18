#include <Arduino.h>


int switchState = 0;
void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == LOW) {
    //the button is not pressed
    digitalWrite(3,HIGH); //pin 3 active (Green LED)
    digitalWrite(4,LOW); // pin 4 not active (RED LED) 
    digitalWrite(5,LOW); // pin 5 not active (RED LED)
  }
  else{
    // button is pressed
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(250);
    // quarter second delay
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    delay(250); // quarter second delay
  }
}
