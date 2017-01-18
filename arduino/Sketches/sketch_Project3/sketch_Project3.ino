const int sensorPin = A0;
const float bTempr = 25.0;

void setup() {
  Serial.begin(9600); //open a serial port
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
 int sensorVal = analogRead(sensorPin);
 
 Serial.println("Sensor Value: ");
 Serial.print(sensorVal);
 //convert ADC reading to voltage
 float voltage = (sensorVal/1024.0) * 5;
 Serial.println("Voltage: ");
 Serial.print(voltage);
 Serial.print(", degrees C: ");
 //convert voltage to temp
 float tempr = (voltage - .5) * 100;
 Serial.print(tempr);
 
 if(tempr < bTempr){
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
 }
 else if(tempr >= bTempr && tempr < bTempr+2){
   digitalWrite(2,HIGH);
   digitalWrite(3,LOW);
   digitalWrite(4,LOW);
 }
 else if(tempr >= bTempr+2 && tempr < bTempr+4){
   digitalWrite(2,HIGH);
   digitalWrite(3,HIGH);
   digitalWrite(4,LOW);
 }
 else if(tempr >= bTempr+4){
   digitalWrite(2,HIGH);
   digitalWrite(3,HIGH);
   digitalWrite(4,HIGH);
 }
 delay(1);

 
}
