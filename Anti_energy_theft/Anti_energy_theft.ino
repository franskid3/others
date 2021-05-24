#include <SoftwareSerial.h>
//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(2, 3); //SIM800L Tx & Rx is connected to Arduino #3 & #2

int sensor = 0;

void setup()
{
  pinMode(12, INPUT);
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
    delay(30000);
  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  ///////////////////////////////////////////////
//    mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
//  updateSerial();
// mySerial.println("AT+CMGS=\"+2347037799994\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
//  updateSerial();
//  mySerial.print("ANTI ENERGY THEFT SENSOR \n ACTIVATED!!!"); //text content
//  updateSerial();
//  mySerial.write(26);
//  delay(10000);
//  //////////////////////////////////////////////////
//  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
//  updateSerial();
//  mySerial.println("AT+CMGS=\"+2348034715684\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
//     updateSerial();
//     mySerial.print("THEFT DETECTED!!! \n"); //text content
//    updateSerial();
//    mySerial.write(26);
//    delay(10000);
  ///////////////////////////////////////////////////
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
 mySerial.println("AT+CMGS=\"+2349035526933\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("ANTI ENERGY THEFT SENSOR \n ACTIVATED!!!"); //text content
  updateSerial();
  mySerial.write(26);

  delay(1000);
}

void loop()
{
 sensor = digitalRead(12);
  
    if(sensor == 1){ 
      delay(3000);
      sensor = digitalRead(12);
      if(sensor == 1){
      Serial.println("theft detected");

//      mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
//  updateSerial();
//  mySerial.println("AT+CMGS=\"+2347037799994\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
//     updateSerial();
//     mySerial.print("THEFT DETECTED!!! \n"); //text content
//    updateSerial();
//    mySerial.write(26);
//    delay(10000);
//    ///////////////////////////////////////////////////////////
//    mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
//  updateSerial();
//  mySerial.println("AT+CMGS=\"+2348034715684\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
//     updateSerial();
//     mySerial.print("THEFT DETECTED!!! \n"); //text content
//    updateSerial();
//    mySerial.write(26);
//    delay(10000);
    /////////////////////////////////////////////////////
      mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+2349035526933\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
     updateSerial();
     mySerial.print("THEFT DETECTED!!! \n"); //text content
    updateSerial();
    mySerial.write(26);
    delay(120000);
   }}
   else{
    Serial.println("Evrything is alright");
    delay(1000);
   }
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
