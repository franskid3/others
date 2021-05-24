#define in_button 9
#define out_button 8
#define fan 7
#define bulb 6

int plp = 0;

#include <Wire.h>
#include <LiquidCrystal.h>
// for I2C display
//#include <LiquidCrystal_I2C.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// for I2C display
//LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  Serial.begin(9600);
  // for I2C display
//  lcd.init(); 
  lcd.backlight();
  lcd.begin(16,2); 
  pinMode(in_button,INPUT_PULLUP);
  pinMode(out_button,INPUT_PULLUP);
  pinMode(fan,OUTPUT);
  pinMode(bulb, OUTPUT);
}

void loop() {
  int in = digitalRead(in_button);
  int out = digitalRead(out_button);

  if(in== 0){
    plp++;
    delay(500);
  }
  if(out == LOW){
    plp--;
    delay(500);
    if(plp < 0){
      plp = 0;
    }
  }

  if(plp > 0){
    Serial.println("plp are present");
    lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print (plp);
    digitalWrite(fan, LOW);
    digitalWrite(bulb, LOW);
  }else{
    Serial.println("room is empty");
    lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print (plp);
    digitalWrite(fan, HIGH);
    digitalWrite(bulb, HIGH);
  }

  Serial.println(plp);
}
