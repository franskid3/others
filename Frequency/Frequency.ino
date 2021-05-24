void setup() {
pinMode(input,INPUT);
lcd.begin(16, 2);
Serial.begin(9600);
}

void loop(){
float vout;
float vin;

float volt = analogRead(A0);
// Serial.print(volt);
  Serial.print("\n");
  delay(1000);

vout = 10000*volt/20000;


float voltage = 1110/vout;

float real = voltage*62.96;
if(volt == 0){
  Serial.print("0");
Serial.print(" V");
}
else{
Serial.print(real);
Serial.print(" V");
}

}
