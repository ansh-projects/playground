int senVal;
int senLow = 1023;
int senHigh = 0;
const int ledPin = 13;

void setup(){ 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,HIGH);
  while(millis() < 5000){
    senVal= analogRead(A0);
    if(senVal > senHigh){
      senHigh = senVal;
    }
    if(senVal < senLow){
      senLow = senVal;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop(){ 
  senVal = analogRead(A0);
  int pitch = map(senVal, senLow, senHigh, 50, 4000);
  tone(8,pitch,15);
  delay(150);
}
