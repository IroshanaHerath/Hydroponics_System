void manualResChange()
{
  if(manMonth == month && manDate == monthDay && manHour == hour && manMinute == minute)
  {
    lcd.clear();
    totalMilliLitresA = 0;
    lcd.setCursor(0,1);
    lcd.print("Reservoir Change");
    lcd.setCursor(6,2);
    lcd.print("Progress");
    digitalWrite(waterOutPin,HIGH);
    while(totalMilliLitresA < liters*1000)
    {
      
    }
    digitalWrite(waterOutPin,LOW);
    lcd.clear();
  }
}
