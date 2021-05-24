/*
 * Ambient temperature is the room temprature and the temprature of the 
 * IR camera
 * Target Temprature is the temprature of the target/heat producing item infront of the 
 * IR camera
 * 
 * the motor turn right or left depending on the direction of the heat source
 * the direction of the heat source is calculated using the servo position as guide
 * 
 * when no heat is found the motor move forward and turn 180 degres to search for heat
 * 
 * when heat is found the motor move closer to the heat source
 * 
 * when heat source is found using ultrasonic sensor to determine the distance
 * if the distance between the motor and heat source is 15cm the motor stops
 * and the buzzer is activated to notify that heat source is found
 * 
 * when heat is not present and distance between motor and an obstacle is less than  15cm
 * motor reverse and turn right at 90 degres.
 */

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>


#define I2C_ADDR 0x27
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Front Right tire
const int motorPin1  = 2;  
const int motorPin2  = 3;  
//Front Left tire
const int motorPin3  = 4; 
const int motorPin4  = 5;  
//Back Right tire
const int motorPin5  = 6; 
const int motorPin6  = 7;  
//Back Left tire
const int motorPin7  = 8; 
const int motorPin8  = 9;  

//Ultrasonic 
#define echopin  11 // echo pin
#define trigpin 12// Trigger pin
long duration, distance;

//Servo
int servoPin = 10;
Servo myservo;

//Buzzer
#define buzzer  13 

  int Temp[181]; //record temprature array
  int x;
  int maxTemp; // position of maximum temp
  int pos;//position of servo
  int i;
  int degres;   // degre of heat source
  int turntime;
  int turn;
  int heat_distance; 
  
void setup() {
  
    myservo.attach(servoPin);
    mlx.begin();
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);

    pinMode (echopin, INPUT);
    pinMode (trigpin, OUTPUT);

    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(motorPin5, OUTPUT);
    pinMode(motorPin6, OUTPUT);
    pinMode(motorPin7, OUTPUT);
    pinMode(motorPin8, OUTPUT);
    pinMode(buzzer, OUTPUT);
    
    Serial.begin(9600);
}

 void Right(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, HIGH);
    digitalWrite(motorPin5, HIGH);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, HIGH);
    digitalWrite(motorPin8, HIGH);
    Serial.println("turnning right");

    
  }

  void Left(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, HIGH);
    digitalWrite(motorPin6, HIGH);
    digitalWrite(motorPin7, HIGH);
    digitalWrite(motorPin8, LOW);
    Serial.println("turnning left");
  }

  void Forward(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    digitalWrite(motorPin5, HIGH);
    digitalWrite(motorPin6, LOW);
    digitalWrite(motorPin7, HIGH);
    digitalWrite(motorPin8, LOW);
    Serial.println("moving forward");
  }

  void Backward(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    digitalWrite(motorPin5, LOW);
    digitalWrite(motorPin6, HIGH);
    digitalWrite(motorPin7, LOW);
    digitalWrite(motorPin8, HIGH);
    Serial.println("moving Backward");
  }
  void Stop(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, HIGH);
    digitalWrite(motorPin5, HIGH);
    digitalWrite(motorPin6, HIGH);
    digitalWrite(motorPin7, HIGH);
    digitalWrite(motorPin8, HIGH);
    Serial.println("moving STOP!!!!!");
    
  }

  void ultrasonic(){
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin, LOW);
    duration=pulseIn (echopin,HIGH);
    distance= duration*0.034/2;
    Serial.print("distance :  ");
    Serial.println(distance);  
  }

  void buzz(){
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);   
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    Serial.println("HEAT SOURCE FOUND !!!!!");
  }

void loop() {
int pos = 0; //position of servo
int i = 0;  
turn = 0;
maxTemp = 0; //position of maximum temp


  for(pos = 0; pos <= 180; pos++){
    myservo.write(pos);
    Temp[pos] = mlx.readObjectTempC();
    delay(10);
//    Serial.print("position :  ");
//    Serial.println(pos);
//    Serial.print("Temprature :  ");
//    Serial.println(Temp[pos]);
 }
  for(i = 0; i < 181; i++){
    if(Temp[1] > Temp[maxTemp]){
      maxTemp = i;
    }
  }
  ultrasonic(); // read distance 
  Serial.print("Maximum heat position :  ");
    Serial.println(maxTemp);
    Serial.print("Maximum Temprature :  ");
    Serial.println(Temp[maxTemp]);
    Serial.print("Ambient Temprature :  ");
    Serial.println(mlx.readAmbientTempC());

  
    degres = 90 - maxTemp; //calculate the source of the heat in degres along
  turntime = 17 * degres;// along with the position of servo
  
  if(turntime < 0){
    turntime = turntime * 1; 
  }
  Serial.print("Degres :  ");
  Serial.println(degres);
  Serial.print("Turn Time :  ");
  Serial.println(turntime);
  


  
  if(Temp[maxTemp] > mlx.readAmbientTempC() && distance >= 15){

    Serial.print("distance from heat source :  ");
  Serial.println(distance + 10);

     if(degres < -30){ // if the heat source is -VE meaan heat is coming from left
    Left();
    delay(turntime);
    Stop();
  }else if(degres < 60 && degres > 0 ){// if the heat source is +VE meaan heat is coming from Right
    Right();
    delay(turntime);
    Stop();
  }else{
    Forward();
    delay(1000);
    Stop();
  }
  }
  
  if(Temp[maxTemp] > mlx.readAmbientTempC() && distance < 15){
    buzz();
  }

  if(Temp[maxTemp] < mlx.readAmbientTempC() && distance > 15){
    Forward();
    delay(500);
    Right();
    delay(180 * 17);
    Stop();
  }else if(Temp[maxTemp] < mlx.readAmbientTempC() && distance < 15){
    Backward();
    delay(500);
    Right();
    delay(17*90);
  }
  
  Serial.println("......................................");
 
}
