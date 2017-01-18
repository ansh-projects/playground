const int  buttonPin = 13;    // the pin that the pushbutton is attached to
const int bluePin = 19;
const int bluePin2 = 18;

int buttonPushCounter = 0; //counter for the number of button presses
int buttonState = 0; //current state of the button
int lastButtonState = 0; //previous state of the button
void setup() {
  //LEDs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(buttonPin, INPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of pushes: ");
      Serial.print(buttonPushCounter);
    } else {
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;

  if (buttonPushCounter % 4 == 0) {
    digitalWrite(bluePin, HIGH);
  } else {
    digitalWrite(bluePin, LOW);
  }

  while (buttonState == HIGH) {
    digitalWrite(bluePin, LOW);
    digitalWrite(bluePin2, LOW);
    //LOL sequence
    //L
    buttonState = digitalRead(buttonPin);
    digitalWrite(2, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(270);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }

    //2
    buttonState = digitalRead(buttonPin);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(200);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }
    //3.1
    buttonState = digitalRead(buttonPin);
    digitalWrite(10, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(200);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }

    //3.2
    buttonState = digitalRead(buttonPin);
    digitalWrite(12, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(200);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }

    //4
    buttonState = digitalRead(buttonPin);
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(200);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }

    //O
    buttonState = digitalRead(buttonPin);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(270);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }

    //6
    buttonState = digitalRead(buttonPin);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(200);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }

    //7.1
    buttonState = digitalRead(buttonPin);
    digitalWrite(2, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(200);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }
    //7.2
    buttonState = digitalRead(buttonPin);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(12, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(200);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }

    //8
    buttonState = digitalRead(buttonPin);
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    buttonState = digitalRead(buttonPin);

    delay(200);
    for (int i = 2; i < 13; i++) {
      digitalWrite(i, LOW);
    }
  }

  while (buttonState == LOW) {
    for (int i = 12; i >= 0; i--) {
      digitalWrite(random(i, 12), HIGH);
      delay(25);
      digitalWrite(random(i, 12), LOW);
      /*
      buttonState = digitalRead(buttonPin);
      digitalWrite(i, HIGH);
      digitalWrite(bluePin, HIGH);
      delay(5);
      digitalWrite(bluePin2, LOW);
             buttonState = digitalRead(buttonPin);
      delay(45);
      digitalWrite(i,LOW);
      digitalWrite(bluePin, LOW);
      delay(5);
      digitalWrite(bluePin2, HIGH);
      delay(45);
      */
    }
    buttonState = digitalRead(buttonPin);
  }
}

