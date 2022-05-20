#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

// analogue write info
int analoguePin = 19;
const int channel = 0;
const int frequency = 5000;
const int resolution = 8;

// max analogue value
int maxVal = 138;
// max value = 255 (3.3V)
// drv2605 max value = 138 (1.8V)

int repetitions = 50;


void setup() {
  Serial.begin(115200);
  Serial.println("DRV2605 Haptic Analogue test");
  drv.begin();

  Serial.println("Enter number for control option:");
  Serial.println("1. Triangle Wave");
  Serial.println("2. Square Wave");
  Serial.println("3. Sawtooth Wave");

  
  // set analogue mode
  drv.setMode(DRV2605_MODE_PWMANALOG);

  // set LRA mode
  drv.useLRA();

  // 0.9V common mode voltage
  //drv.writeRegister8(DRV2605_REG_CONTROL1, 0x20);  
 
  // analog input
  drv.writeRegister8(DRV2605_REG_CONTROL3, 0xA3);  


  // analogue write setup
  ledcSetup(channel, frequency, resolution);
  ledcAttachPin(analoguePin, channel);
}


void loop() {  

  char user_input;
  
  while(Serial.available())
  {
    user_input = Serial.read();

    if (user_input =='1')
    {
      Serial.println();
      Serial.println("Triangle");
      for (int repeat = 0 ; repeat <= repetitions; repeat += 1) {
        Triangle();
      }
    }
    else if(user_input =='2')
    {
      Serial.println();
      Serial.println("Square");
      for (int repeat = 0 ; repeat <= repetitions; repeat += 1) {
        Square();
      }
    }
    else if(user_input =='3')
    {
      Serial.println();
      Serial.println("Sawtooth");
      for (int repeat = 0 ; repeat <= repetitions; repeat += 1) {
        Sawtooth();
      }
    }
    else
    {
      Serial.println("Invalid option");
    }
  }
}

void Triangle()
{    
  // build up
  for (int fadeValue = 0 ; fadeValue <= maxVal; fadeValue += 6) {
    ledcWrite(channel, fadeValue);
    delay(25);
  }

  // build down
  for (int fadeValue = maxVal ; fadeValue >= 0; fadeValue -= 6) {
    ledcWrite(channel, fadeValue);
    delay(25);
  } 
}

void Square()
{    
  // top
  for (int fadeValue = 0 ; fadeValue <= 1; fadeValue += 1) {
    ledcWrite(channel, maxVal);
    delay(30);
  }

  // bottom
  for (int fadeValue = maxVal ; fadeValue >= 0; fadeValue -= 6) {
    ledcWrite(channel, 0);
    delay(30);
  }
}

void Sawtooth()
{  
  for (int repeatSaw = 0 ; repeatSaw <= 5; repeatSaw += 1) {
    for (int fadeValue = 0 ; fadeValue <= maxVal; fadeValue += 6) {
      ledcWrite(channel, fadeValue);
      delay(30);
    }
    delay(100);
  }
}
