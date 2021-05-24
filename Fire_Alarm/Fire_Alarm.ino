#include <SoftwareSerial.h>
#define led 13
bool sensor;
int fire = 4;
//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+2347037799994\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
 // delay(180000);
  mySerial.print("Automatic Fire ALarm System\nREADY!!!"); //text content
  updateSerial();
  mySerial.write(26);
}

void loop()
{
    digitalWrite(led,HIGH);
   sensor = digitalRead(fire);
   Serial.print(sensor);
   if(sensor == 1){
    for(int i = 0; i<50; i++)
    {
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
    }
    }
   if(sensor == 1){
    
     mySerial.print("FIRE DETECTED!!! \n"); //text content
    updateSerial();
    mySerial.write(26);
   }
   delay(60000);
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
