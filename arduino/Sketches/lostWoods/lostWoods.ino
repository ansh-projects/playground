#include "pitches.h"
#define melodyPin 9

const int switchPin = 8;
int switchState = 0;
int prevSwitchState = 0;

//Lost Woods melody
int melody[] = {
  NOTE_F5, NOTE_A5, NOTE_B5,  // FAB
  NOTE_F5, NOTE_A5, NOTE_B5,  //FAB
  NOTE_F5, NOTE_A5, NOTE_B5, NOTE_E6, NOTE_D6, //FABE D

  NOTE_B5, NOTE_C6, NOTE_B5, NOTE_G5, NOTE_E5, //BCBGE
  NOTE_D5, NOTE_E5, NOTE_G5, NOTE_E5, //ED*BE


  NOTE_F5, NOTE_A5, NOTE_B5,  // FAB
  NOTE_F5, NOTE_A5, NOTE_B5,  //FAB
  NOTE_F5, NOTE_A5, NOTE_B5, NOTE_E6, NOTE_D6, //FABE D

  NOTE_B5, NOTE_C5, NOTE_E6, NOTE_B5, NOTE_G5, //BCEBG
  NOTE_B5, NOTE_G5, NOTE_D5, NOTE_E5, //BGDE

  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_B5, NOTE_E5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_B5, NOTE_E5,

  NOTE_D5, NOTE_C5, 0, NOTE_F5, NOTE_E5, 0, NOTE_G5, NOTE_F5, 0,
  NOTE_A5, NOTE_G5, 0, NOTE_B5, NOTE_A5, 0, NOTE_C6, NOTE_B5, 0,
  NOTE_D6, NOTE_C6, 0, NOTE_B5, NOTE_C6, 0, NOTE_A5, NOTE_B5, 0, 0, NOTE_E6,
};
//Mario main them tempo
int tempo[] = {
  8, 8, 4, //good
  8, 8, 4, //good
  8, 8, 8, 8, 4, //good

  8, 8, 8, 8, 2, //good
  8, 8, 8, 4, //good

  8, 8, 4,//good
  8, 8, 4,//good
  8, 8, 8, 8, 4, //good

  8, 8, 8, 8, 2,
  8, 8, 8, 2,

  8, 8, 4, 8, 8, 4, 8, 8, 2,
  8, 8, 4, 8, 8, 4, 8, 8, 2,
  8, 8, 4, 8, 8, 4, 8, 8, 2,

  8, 16, 16, 8, 16, 16, 8, 16, 16,
  8, 16, 16, 8, 16, 16, 8, 16, 16,
  8, 16, 16, 16, 16, 16, 16, 2, 2, 12, 4,


};

void setup() {
  pinMode(9, OUTPUT);//buzzer
  pinMode(13, OUTPUT);//led indicator when singing a note
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  switchState = digitalRead(switchPin);
  while (switchState == HIGH) {
    sing(1);
    switchState = digitalRead(switchPin);
  }
  while (switchState == LOW) {
    switchState = digitalRead(switchPin);
    for (int i = 2; i < 8; i++) {
      digitalWrite(i, HIGH);
      delay(50);
    }
    switchState = digitalRead(switchPin);

    for (int i = 2; i < 8; i++) {
      digitalWrite(i, LOW);
      delay(50);
    }
    switchState = digitalRead(switchPin);
    for (int i = 8; i >= 2; i--) {
      digitalWrite(i, HIGH);
      delay(50);
    }
    switchState = digitalRead(switchPin);
    for (int i = 8; i >= 2; i--) {
      digitalWrite(i, LOW);
      delay(50);
    }
    switchState = digitalRead(switchPin);

  }
}
int song = 0;

void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  Serial.println(" 'Mario Theme'");
  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / tempo[thisNote];

    buzz(melodyPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    buzz(melodyPin, 0, noteDuration);

  }
}
int pin = 0;
void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  pin = random(2, 8);
  digitalWrite(pin, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(pin, LOW);
  digitalWrite(13, LOW);

}
