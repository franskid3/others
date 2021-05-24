/* Arduino Color Detector 
 *   
 *   I2C LCD 2/16 Serial Display 
 *   - SDA ==> Nano Pin A4  
 *   - SCL ==> Nano Pin A5
 * 
 *   Color Sensor
 *    - frequency output scaling
 *      s0          s1         
 *       L           L         = power down no output
 *       L           H         = 2%
 *       H           L         = 20%
 *       H           H         = 100% 
 *   - EO = set low to enable 
 *   
 * Developed by Marcelo Rovai - 306Apr17
 ********************************************************************************************************/
#include "stationDefines.h"

/* LCD */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Set the LCD address to 0x27; 20 chars and 4 lines (use I2C scan to confirm address)
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define I2C_ADDR 0x3F //LCD i2c stuff
void setup()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT); //out from sensor becomes input to arduino
lcd.backlight();
    // Setting frequency scaling to 100%
  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  
  Serial.begin(9600);
  lcd.init();
  // lcd.noBacklight();
  lcd.print("Smart Color Counter");
  Serial.println("MJRoBot Color Detector");
  startTiming = millis();
  
}

void loop()
{
  getColor();

  count();
  
  if (DEBUG) printData(); 
  elapsedTime = millis()-startTiming; 
  if (elapsedTime > 1000) 
  {
    showDataLCD();
    startTiming = millis();
  }
}
