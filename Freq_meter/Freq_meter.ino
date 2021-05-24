
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int input=13;
int high_time;
int low_time;
float time_period;
float freq;
float frequency;

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
Serial.begin(9600);
  
 lcd.begin (16,2); //  <<----- My LCD was 16x2

 
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home
lcd.setBacklight(HIGH);

 lcd.print("FREQUENCY METER");  
}

void loop()
{
  float vout;
  float vin;
  float volt = analogRead(A0);
 // Serial.print(volt);
  Serial.print("\n");
  delay(1000);

vout = 10000*volt/20000;


float voltage = (volt/1024)*5;

float real = voltage*52.6;

high_time=pulseIn(input,HIGH);
low_time=pulseIn(input,LOW);
time_period=high_time+low_time;
time_period=time_period/1000;
frequency=1000/time_period;




if(volt == 0){
  lcd.clear();
  lcd.setCursor(0,0);
lcd.print("FREQUENCY METER");
 lcd.setCursor (0,1);        // go to start of 2nd line
 lcd.print("0 Volt");
 lcd.setCursor (7,1);        // go to start of 2nd line
 lcd.print("0 Hz");
//  Serial.print("0");
//  Serial.print(" V");
//   Serial.print("\n 0 Hz");
   delay(5000);

}
else{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("FREQUENCY METER");
lcd.setCursor (0,1);        // go to start of 2nd line
lcd.print(real);
lcd.setCursor (5,1);
lcd.print("V");
lcd.setCursor (8,1);
lcd.print(frequency);
lcd.print(" Hz");
//delay(5000);

// 
Serial.println(real);
Serial.println(" V");

Serial.println(frequency);
Serial.println(" Hz");


}
 // Backlight on/off every 3 seconds


}
