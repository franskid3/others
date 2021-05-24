#define red 2
#define blue 3
int green = 4;
#define red_button 9
#define blue_button 10
#define green_button 11
#define animation_button 12

int red_state = HIGH;
int blue_state = HIGH;
int green_state = HIGH;
int animation_state = HIGH;
int red_reading, blue_reading, green_reading, animation_reading;
int red_previous = LOW;
int green_previous = LOW;
int blue_previous = LOW;
int animation_previous = LOW;
int animation;

long time = 0;
long debounce = 200;
void setup() {
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(red_button, INPUT_PULLUP);
pinMode(green_button, INPUT_PULLUP);
pinMode(blue_button, INPUT_PULLUP);
pinMode(animation_button, INPUT_PULLUP);

Serial.begin(9600);
}

void loop() {
    red_reading = digitalRead(red_button);
    blue_reading = digitalRead(blue_button);
    green_reading = digitalRead(green_button);
    animation_reading = digitalRead(animation_button);

 if(animation_reading == LOW && animation_previous == LOW && millis() - time > debounce){
      if(animation_state == LOW){
        animation_state = HIGH;
        animation = HIGH;
        time = millis();
        
        
      }else{
        animation_state = LOW;
        animation = LOW;
       // Serial.println("kkkk");
        time = millis();
        
      }
    }
     
//**********************************************************
    if(red_reading == LOW && red_previous == LOW && millis() - time > debounce){
      if(red_state == LOW){
        red_state = HIGH;
        time = millis();
       
      }else{
        red_state = LOW;
       // Serial.println("kkkk");
        
        time = millis();
      }
    }
     
 //   ********************************************************************
    if(blue_reading == LOW && blue_previous == LOW && millis() - time > debounce){
      if(blue_state == LOW){
        blue_state = HIGH;
        time = millis();
       
      }else{
        blue_state = LOW;
       // Serial.println("kkkk");
        
        time = millis();
      }
      
    }

  //  *********************************************************
    if(green_reading == LOW && green_previous == LOW && millis() - time > debounce){
      if(green_state == LOW){
        green_state = HIGH;
        time = millis();
       
      }else{
        green_state = LOW;
       // Serial.println("kkkk");
        
        time = millis();
      }
      
    }
   //************************************************************** 
   digitalWrite(green, green_state);
   digitalWrite(blue, blue_state);
   digitalWrite(red, red_state);
   
      green_previous = green_reading;   
      red_previous = red_reading;
      blue_previous = blue_reading;
    //  ***********************************
      
       
        if(animation == HIGH){
        digitalWrite(red, HIGH);
        digitalWrite(blue, LOW);
        digitalWrite(green, LOW);
        delay(18);
        digitalWrite(red, LOW);
        digitalWrite(blue, HIGH);
        digitalWrite(green, LOW);
        delay(18);
        digitalWrite(red, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(green, HIGH);
        delay(18);
        ///////////////////////////
        digitalWrite(red, HIGH);
        digitalWrite(blue, HIGH);
        digitalWrite(green, LOW);
        delay(18);
        digitalWrite(red, HIGH);
        digitalWrite(blue, LOW);
        digitalWrite(green, HIGH);
       delay(18);
        digitalWrite(red, LOW);
        digitalWrite(blue, HIGH);
        digitalWrite(green, HIGH);
        delay(18);
        digitalWrite(red, HIGH);
        digitalWrite(blue, HIGH);
        digitalWrite(green, HIGH);
        delay(18);
        digitalWrite(red, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(green, LOW);
        delay(18);
       // Serial.println("animation ON");
        }
         digitalWrite(red, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(green, LOW);
       // Serial.println("animation OFF");
       animation_previous = animation_reading;
       
}
