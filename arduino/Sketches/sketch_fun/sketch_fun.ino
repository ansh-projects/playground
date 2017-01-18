//phototransistor
int senVal;
int senLow = 1023;
int senHigh = 0;
int photoPin = A0;

//RGB LED
int rPin = 9;
int gPin = 10;
int bPin = 11;

int dbug = 2; //Debug LED
const int ledPin = 13; //onboard LED
int switchState = 0; //button

void setup(){ 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(dbug,OUTPUT); 
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  digitalWrite(ledPin,HIGH);
  
  //phototransistor config
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
  int photoSet = map(senVal, senLow, senHigh, 0, 255);
  analogWrite(rPin, photoSet)

