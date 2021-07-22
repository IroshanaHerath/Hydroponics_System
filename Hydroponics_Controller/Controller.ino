void function()
{
  //tempController();
  humidController();
 
}

void humidController()
{
  botState = false;
  if(lightState == true && (humid <= (onRH - RHHys) ))
  {
    digitalWrite(misterPin,HIGH);
  }
  else if(lightState == true && (humid >= onRH ))
  {
    digitalWrite(misterPin,LOW);
  }
  
  if(lightState == false && (humid <= (offRH - RHHys) ))
  {
    digitalWrite(misterPin,HIGH);
  }
  else if(lightState == false && (humid >= offRH ))
  {
    digitalWrite(misterPin,LOW);
  }
  
  if(tempVal <= stopTemp)
  {
    digitalWrite(chillerPin,LOW);
  }
  
  else if(tempVal >= startTemp)
  {
    digitalWrite(chillerPin,HIGH);
  }
  
  
  if(co2Val <= desCarbon)
  {
    digitalWrite(co2Pin,HIGH);
  }
  
  else if(co2Val >= (desCarbon + carbonHys))
  {
    digitalWrite(co2Pin,LOW);
  }
  
  for(int i = 0;i<6;i++)
  {
    if(currentNut[i] < cutOff)
    {
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Nut Bottle #");
      lcd.print(i+1);
      lcd.print(" LOW");
      botState = true;
      delay(1000);
    }
  }
  
  if(botState == false)  digitalWrite(alarmPin,LOW);
  else  digitalWrite(alarmPin,HIGH);
  
  
}

void nutFunction()
{
  if(weekDay == startDay && nutState == false && co2Val < data[weekCount][3] && weekCount < totalWeeks)
  {
    int increase = (data[weekCount][3] -co2Val)/data[weekCount][3];
    int nut1Vol = data[weekCount][0]*waterSize*increase;
    int nut2Vol = data[weekCount][1]*waterSize*increase;
    int nut3Vol = data[weekCount][2]*waterSize*increase;
    int nutDelay;
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pump #1 is running");
    nutDelay = nut1Vol/pumpRate;
    digitalWrite(pumpPin[0],HIGH);
    delay(nutDelay);
    digitalWrite(pumpPin[0],LOW);
    
    lcd.print("Pump #2 is running");
    nutDelay = nut2Vol/pumpRate;
    digitalWrite(pumpPin[1],HIGH);
    delay(nutDelay);
    digitalWrite(pumpPin[1],LOW);
    
    lcd.print("Pump #3 is running");
    nutDelay = nut3Vol/pumpRate;
    digitalWrite(pumpPin[2],HIGH);
    delay(nutDelay);
    digitalWrite(pumpPin[2],LOW);
    
    lcd.clear();
    nutState = true;
    weekCount++;
  }
  
  if(weekDay != startDay)  nutState = false;
  
}
