const int rPin = 11;
const int gPin = 10;
const int bPin = 9;

const int rSensor = A0;
const int gSensor = A2;
const int bSensor = A3;

int rVal = 0;
int gVal = 0;
int bVal = 0;

int rSenVal = 0;
int bSenVal = 0;
int gSenVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  for(int i = 255; i>0; i--){
    for(int j = 255; j>0; j--){
      for(int k = 255; k>0; k--){
        analogWrite(rPin, i);
        analogWrite(gPin, j);
        analogWrite(bPin, k);
      }
    }
  }
}
