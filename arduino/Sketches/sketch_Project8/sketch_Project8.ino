#include "pitches.h"
const int switchPin = 8;
unsigned long prevTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 257143;


//Alarm Song
#define melodyPin 9
//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

void setup() {
  Serial.begin(9600);

  pinMode(9, OUTPUT);//buzzer
  pinMode(13, OUTPUT);//led indicator when singing a note

  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currTime = millis();
  if (currTime - prevTime > interval) {
    prevTime = currTime;
    digitalWrite(led, HIGH);
    led++;
    if (led == 8) {
      digitalWrite(led, HIGH);
      delay(interval / 10);

      while (switchState == prevSwitchState) {
        switchState = digitalRead(switchPin);
        if (switchState != prevSwitchState) {
          break;
        }
        //sing the tunes

        for (int i = 8; i >= 0; i--) {
          delay(50);
          digitalWrite(i, LOW);
        }
        switchState = digitalRead(switchPin);
        for (int i = 8; i >= 0; i--) {
          delay(50);
          digitalWrite(i, HIGH);
        }
        for (int i = 8; i >= 0; i--) {
          digitalWrite(i, LOW);
        }

        delay(2000);
        switchState = digitalRead(switchPin);
        if (switchState != prevSwitchState) {
          break;
        }
        sing(1);
        delay(2000);
        switchState = digitalRead(switchPin);
      }
    }
  }

  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    noTone(9);
    for (int i = 8; i >= 0; i--) {
      delay(50);
      digitalWrite(i, LOW);
    }
    led = 2;
    prevTime = currTime;
  }
  prevSwitchState = switchState;

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

/*
  Arduino Mario Bros Tunes
  With Piezo Buzzer and PWM
  by: Dipto Pratyaksa
  last updated: 31/3/13
*/
