//char blueToothVal;           //value sent over via bluetooth
char lastValue;              //stores last state of device (on/off)
int led1 = A1;
int led2 = A2;
int led3 = A3;
int led4 = A4;
int led5 = A5;

void setup()
{
 Serial.begin(9600); 
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);
 pinMode(led5,OUTPUT);
}
 
void loop()
{
  if(Serial.available() > 0)
  {//if there is data being recieved
   int blueToothVal=Serial.read(); //read it

    switch(blueToothVal){
      case 'A':
        digitalWrite(led1,HIGH);
        Serial.println(blueToothVal);
        Serial.println(F("LED 1 is on"));
        break;
      case 'B':
        digitalWrite(led1,LOW);
        Serial.println(blueToothVal);
        Serial.println(F("LED 1 is off"));
        break;
      case 'C':
        digitalWrite(led2,HIGH);
        Serial.println(blueToothVal);
        Serial.println(F("LED 2 is on"));
        break;
      case 'D':
        digitalWrite(led2,LOW);
        Serial.println(blueToothVal);
        Serial.println(F("LED 2 is off"));
        break;
      case 'E':
        digitalWrite(led3,HIGH);
        Serial.println(blueToothVal);
        Serial.println(F("LED 3 is on"));
        break;
      case 'F':
        digitalWrite(led3,LOW);
        Serial.println(blueToothVal);
        Serial.println(F("LED 3 is off"));
        break;
      case 'G':
        digitalWrite(led4,HIGH);
        Serial.println(blueToothVal);
        Serial.println(F("LED  4 is on"));
        break;
      case 'H':
        digitalWrite(led4,LOW);
        Serial.println(blueToothVal);
        Serial.println(F("LED 4 is off"));
        break;
      case 'I':
        digitalWrite(led5,HIGH);
        Serial.println(blueToothVal);
        Serial.println(F("LED 5 is on"));
        break;
      case 'J':
        digitalWrite(led5,LOW);
        Serial.println(blueToothVal);
        Serial.println(F("LED 5 is off"));
        break; 
    }
  }

  delay(1000);
}
