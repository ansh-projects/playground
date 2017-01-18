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
int color[3]; //colour storage // [0] = red, [1] = green, [2] = blue
int redState = 0; //button for red

void setup(){ 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(dbug,OUTPUT); 
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  digitalWrite(dbug, HIGH);
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
  digitalWrite(dbug, LOW);
  digitalWrite(ledPin, LOW);
  
  //randomSeed(analogRead(0));

}
void loop(){
  rPin = color[0];
  gPin = color[1];
  bPin = color[2];
  digitalWrite(dbug, LOW);
  senVal = analogRead(A0);
  int photoSet = map(senVal, senLow, senHigh, 0, 255); //range phototransistor values from 0 - 255 for colour
  redState = digitalRead(4);
  Serial.println(redState);
  int butt = analogRead(A1);
  //Serial.println(butt);
  analogWrite(rPin, photoSet);
  //red button
  if(redState == HIGH){
     digitalWrite(dbug, HIGH);
    color[0] = photoSet;
    rPin = color[0];
    gPin = 0;
    bPin = 0;
    delay(10);
  }
  else if(butt == 1023){
    digitalWrite(dbug, HIGH);
    color[2] = photoSet;
    rPin = 0;
    gPin = 0;
    bPin = color[2];
    delay(10);
  }

  else if(butt >= 690 && butt <= 700){
    digitalWrite(dbug, HIGH);
    color[1] = photoSet;
    rPin = 0;
    gPin = color[2];
    bPin = 0;
   
    delay(10);
  }
 // else if(redState == LOW && butt <= 10){
///  digitalWrite(dbug, HIGH);
//  delay(10);
//  digitalWrite(dbug, LOW);
//  delay(1000);
//  rPin = random(100,255);
//  gPin = random(100, 255);
 // bPin = random(100, 255);
    
//  }
}

