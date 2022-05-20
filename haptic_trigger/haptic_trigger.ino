#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;
const int buttonPin = 2;
int pin_SDA = 21;
int pin_SCL = 22;

void setup() {
  Serial.begin(115200);
  Serial.println("DRV test");
  
  Wire.setPins(pin_SDA, pin_SCL);
  
  drv.begin();
  drv.useLRA();
  drv.selectLibrary(6);
  
  drv.setMode(DRV2605_MODE_INTTRIG);

  pinMode(buttonPin, INPUT);
}

uint8_t effect = 56;
int buttonState = 0;

void loop() {

  // set the effect to play
  drv.setWaveform(0, effect);  // play effect
  drv.setWaveform(1, 0);       // end waveform

  // play the effect!
  drv.go();

  // wait a bit
  delay(1000);

  buttonState = digitalRead(buttonPin);
  Serial.print("Vibrate ");

  if (buttonState == HIGH) {
    effect = 56;
    Serial.println(!buttonState);
  } else {
    effect = 0;
    Serial.println(!buttonState);
  }
  if (effect > 123) effect = 1;
  
}
