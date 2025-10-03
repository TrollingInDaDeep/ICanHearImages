#include <TimerOne.h>


/// pins
int potFreq = A0; //pin of analog potentiometer
int analogOut = A3; //pin where the signal is going out
int pwmOut = 3; //PWM pin to output wave

/// variables
int freqRead = 0; //value read by potentiometer
float outFreq = 0; //actual frequency that was dialed
float minFreq = 145000; //minimum frequency in Hz
float maxFreq = 145500; //maximum frequency in Hz


unsigned long idelay = 16666.6;
int waveState = LOW;


void setup() {
  Timer1.initialize(idelay);
  //Timer1.attachInterrupt(sendPulse);
  Timer1.attachInterrupt(togglePin);
  Serial.begin(9600);
}

void loop() {

  freqRead = map(analogRead(potFreq),0,1024,0,500);
  readSerial();
  // analogWrite(analogOut, 300);
  // digitalWrite(pwmOut, HIGH);
  
  // delayMicroseconds(idelay);
  
  // analogWrite(analogOut, 0);
  // digitalWrite(pwmOut, LOW);
  
  // delayMicroseconds(idelay);
  //Serial.println(freqRead);


  //little over 145000 hz (145khz)
}

void readSerial() {
  while (Serial.available() == 0) ; //stay in infinite while loop until something is entered in the serial monitor
  String input = Serial.readStringUntil('\n');
  idelay = input.toInt();
  Timer1.setPeriod(idelay);
  Serial.println(idelay);
}


void togglePin() {
  PINC = (1 << PC3);
}
void sendPulse() {
  if (waveState == LOW) {
    waveState = HIGH;
    analogWrite(analogOut, 300);
    digitalWrite(pwmOut, HIGH);

  } else {
    waveState = LOW;
    analogWrite(analogOut, 0);
    digitalWrite(pwmOut, LOW);
  }
}