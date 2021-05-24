String voice; 
void setup() {
pinMode(13, OUTPUT);  
pinMode(12, OUTPUT); 
Serial.begin(9600);
} 
void loop() {
  while (Serial.available())
  { 
  delay(10); 
  char c = Serial.read(); 
  voice += c; 
  }  
  if (voice.length() > 0)
  {
    Serial.println(voice); 
       if(voice == "A")
       {
         digitalWrite(12, HIGH);
        }  
  if(voice == "B")
  {
   digitalWrite(12, LOW);
    } 

    if(voice == "C")
       {
         digitalWrite(13, HIGH);
        }  
  if(voice == "D")
  {
   digitalWrite(13, LOW);
    }
voice="";
}
}
