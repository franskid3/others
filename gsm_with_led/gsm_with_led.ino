#include <SoftwareSerial.h>
SoftwareSerial gsm(9, 10);
char* number = "08164699936";
char* confirmation_message = "Command has been received and implemented";

int relay1 = 5;
int relay2 = 6;
int relay3 = 7;
int relay4 = 8;
int relay5 ;
int relay6 ;
int relay7 ;
int relay8 ;
int buzzer ;

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.print("AT\r\n");
  gsm.print("AT+CFUN=1\r\n");
  Serial.println(readGSM());
  delay(10);
  gsm.print("AT+CMGF=1\r\n");
  gsm.print("AT+CMGR=1\r\n");

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  pinMode(buzzer, OUTPUT);
   gsm.print("at+cmgda=\"DEL ALL\"\n\r"); // To Delete Messages from SIM Memory

}


String c = "";
String readGSM() {
  while (!gsm.available())
  {
    delay(13);
  }
  if (gsm.available())
  {
    return gsm.readString();
  }

}


void sendConfirmation()
{
  /*gsm.print("AT+CMGS\r\n");
  gsm.print(number);
  gsm.print(confirmation_message);
  gsm.print((char)26);
  Serial.println(readGSM());*/
}


void loop()
{ if ((readGSM().indexOf("+CMTI:")) != -1 )
  { for(int i = 0; i < 3; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
    Serial.println("NEW MESSAGE");
    gsm.print("AT+CMGR=1\r\n");

    c = readGSM(); Serial.println(c);


    if (c.indexOf("LEDON") != -1)
    {
      Serial.println("LEDON");
      digitalWrite(relay1, HIGH);
      sendConfirmation();
    }

   /* if (c.indexOf("LEDOFF") != -1)
    {
      Serial.println("LEDOFF");
      digitalWrite(relay1, LOW);
      sendConfirmation();
    }

    if (c.indexOf("@LED2ON")  != -1)
    {
      Serial.println("LED2ON");
      digitalWrite(relay2, HIGH);
      sendConfirmation();
    }

    if (c.indexOf("@LED2OFF") != -1)
    {
      Serial.println("LED2OFF");
      digitalWrite(relay2, LOW);
      sendConfirmation();
    }

    if (c.indexOf("@LED3ON")  != -1)
    {
      Serial.println("LED3ON");
      digitalWrite(relay3, HIGH);
      sendConfirmation();
    }

    if (c.indexOf("@LED3OFF") != -1)
    {
      Serial.println("LED3OFF");
      digitalWrite(relay3, LOW);
      sendConfirmation();
    }

    if (c.indexOf("@LED4ON")  != -1)
    {
      Serial.println("LED4ON");
      digitalWrite(relay4, HIGH);
      sendConfirmation();
    }

    if (c.indexOf("@LED4OFF") != -1)
    {
      Serial.println("LED4OFF");
      digitalWrite(relay4, LOW);
      sendConfirmation();
    }

    if (c.indexOf("@LED5ON")  != -1)
    {
      Serial.println("LED5ON");
      digitalWrite(relay5, HIGH);
      sendConfirmation();
    }

    if (c.indexOf("@LED5OFF") != -1)
    {
      Serial.println("LED5OFF");
      digitalWrite(relay5, LOW);
      sendConfirmation();
    }
    if (c.indexOf("@LED6ON")  != -1)
    {
      Serial.println("LED6ON");
      digitalWrite(relay6, HIGH);
      sendConfirmation();
    }

    if (c.indexOf("@LED6OFF") != -1)
    {
      Serial.println("LED6OFF");
      digitalWrite(relay6, LOW);
      sendConfirmation();
    }

    if (c.indexOf("@LED7ON")  != -1)
    {
      Serial.println("LED7ON");
      digitalWrite(relay7, HIGH);
      sendConfirmation();
    }

    if (c.indexOf("@LED7OFF") != -1)
    {
      Serial.println("LED7OFF");
      digitalWrite(relay7, LOW);
      sendConfirmation();
    }

    if (c.indexOf("@LED8ON")  != -1)
    {
      Serial.println("LED8ON");
      digitalWrite(relay8, HIGH);
      sendConfirmation();
    }

    if (c.indexOf("@LED8OFF") != -1)
    {
      Serial.println("LED8OFF");
      digitalWrite(relay8, LOW);
      sendConfirmation();
    }*/

    gsm.flush();
    gsm.print("at+cmgda=\"del all\"\n\r"); // To Delete Messages from SIM Memory

  };
  if(gsm.available())
  {Serial.println(gsm.readString());}
}

/*fan
tv
light
ac
*/
