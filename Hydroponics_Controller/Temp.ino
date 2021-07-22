void temperature()
{

  sensors.requestTemperatures();
  tempVal = sensors.getTempCByIndex(0) ;

  ////// uLCD display
  lcd.setCursor(0, 2);
  lcd.print("Temp:");
  lcd.print(tempVal);
  lcd.print("C");

}
