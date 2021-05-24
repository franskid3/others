#include<Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int hours = 0; // start hours
int minutes = 1; //start min
int seconds = 5; //start seconds
 
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //<--removed- Different LCD manufacture
//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);//Pin Code for Arduino SainSmart LCD 1602 KeyPad
 
void setup() {
}
 
void loop() {
 lcd.begin();
 lcd.print("Count Down Timer ");
 
  lcd.scrollDisplayLeft();
 // wait a bit:
 delay(150);
 
 while (hours > 0 || minutes > 0 || seconds >= 0) {
 
 lcd.setCursor(4, 1);
 
 (hours < 10) ? lcd.print("0") : NULL;
 lcd.print(hours);
 lcd.print(":");
 (minutes < 10) ? lcd.print("0") : NULL;
 lcd.print(minutes);
 lcd.print(":");
 (seconds < 10) ? lcd.print("0") : NULL;
 lcd.print(seconds);
 //lcd.display();
 stepDown();
 delay(1000);
 }
}
 
void stepDown() {
 if (seconds > 0) {
 seconds -= 1;
 } else {
 if (minutes > 0) {
 seconds = 59;
 minutes -= 1;
 } else {
 if (hours > 0) {
 seconds = 59;
 minutes = 59;
 hours -= 1;
 } else {
 trigger();
 }
 }
 }
}
 
void trigger() {
 lcd.clear(); // clears the screen and buffer
 lcd.setCursor(5, 1); // set timer position on lcd for end.
 
 lcd.print("END ");
 delay(1000);
 
 //lcd.display();
}
