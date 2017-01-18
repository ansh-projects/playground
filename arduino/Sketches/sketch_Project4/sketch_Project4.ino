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
  rSenVal = analogRead(rSensor);
  delay(5);
  gSenVal = analogRead(gSensor);
  delay(5);
  bSenVal = analogRead(bSensor);
  Serial.print("Raw Rensor value \t Red: ");
  Serial.print(rSenVal);
  Serial.print("\t Green: ");
  Serial.print(gSenVal);
  Serial.print("\t Blue: ");
  Serial.print(bSenVal);
  rVal = rSensor/4;
  gVal = gSensor/4;
  bVal = bSensor/4;
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(rVal);
  Serial.print("\t Green: ");
  Serial.print(gVal);
  Serial.print("\t Blue: ");
  Serial.print(bVal);
  
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
}
