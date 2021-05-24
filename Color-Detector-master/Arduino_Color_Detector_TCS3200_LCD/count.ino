
void count(){
   if (red > 8 && red < 18 && grn > 9 && grn < 19 && blu > 8 && blu < 16) {
        count0++;
        color = "WHITE";
        lcd.setCursor (0,1);
        lcd.print("WHITE= ");
        lcd.setCursor (7,1); 
        lcd.print("        ");
        lcd.setCursor (7,1);  
        lcd.print(count0);
        delay(small);
         }
  else if (red > 80 && red < 125 && grn > 90 && grn < 125 && blu > 80 && blu < 125){
  count1++;
   color = "BLACK";
  lcd.setCursor (10,1);
  lcd.print("BLACK= ");
  lcd.setCursor (17,1); 
  lcd.print("        ");
  lcd.setCursor (17,1);  
  lcd.print(count1); 
  delay(small);
   }
  else if (red > 12 && red < 30 && grn > 40 && grn < 70 && blu > 33 && blu < 70){
    count2++;
    color = "RED";
  lcd.setCursor (0,2);
  lcd.print("RED= ");
  lcd.setCursor (5,2); 
  lcd.print("        ");
  lcd.setCursor (5,2);  
  lcd.print(count2);
  delay(small);
  }
  else if (red > 50 && red < 95 && grn > 35 && grn < 70 && blu > 45 && blu < 85){
    count3++;
    color = "GREEN";
  lcd.setCursor (10,2);
  lcd.print("GREEN= ");
  lcd.setCursor (17,2); 
  lcd.print("        ");
  lcd.setCursor (17,2);  
  lcd.print(count3);
  delay(small);

  }
  else if (red > 10 && red < 20 && grn > 10 && grn < 25 && blu > 20 && blu < 38){
    count4++;
    color = "YELLOW";
  lcd.setCursor (0,3);
  lcd.print("YELLOW= ");
  lcd.setCursor (8,3); 
  lcd.print("        ");
  lcd.setCursor (8,3);  
  lcd.print(count4);
  delay(small);

  }
  else if (red > 65 && red < 125 && grn > 65 && grn < 115 && blu > 32 && blu < 65){
    count5++;
    color = "BLUE";
  lcd.setCursor (12,3);
  lcd.print("BLUE= ");
  lcd.setCursor (17,3); 
  lcd.print("        ");
  lcd.setCursor (17,3);  
  lcd.print(count5);
  delay(small);

  }

}
