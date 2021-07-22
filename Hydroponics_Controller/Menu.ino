void selection()
{
  pointer[0] = 1;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("------Main Menu-----");
  //mainMenu();
  maximum = mainMax;
  index = 0;
  main0 = true;
  temp = true;
  sub1 = false;
  
  while(main0 == true)
  {
    maximum = mainMax;
    index = 0;
    mainMenu();
    response();
    main0 = temp;
    if(sub1 == true)  subMenu();
  }
  
}

void mainMenu()
{
  lcd.setCursor(0, 0);
  lcd.print("------Main Menu-----");
  lcd.setCursor(0, 2);
  if(pointer[0] == 1)  lcd.print("1).Settings");
  if(pointer[0] == 2)  lcd.print("2)Pump Configuration");
  if(pointer[0] == 3)  lcd.print("3).Calibration");
  if(pointer[0] == 4)  lcd.print("4).Reservoir Change");
  if(pointer[0] == 5)  lcd.print("5).N Bottle Settings");
  if(pointer[0] == 6)  lcd.print("6).Nutrient Schedule");
  if(pointer[0] == 7)  lcd.print("7).Take Readings");
  
}



void subMenu()
{
  if(pointer[0] == 1)  settings();
  if(pointer[0] == 2)  pumps();
  if(pointer[0] == 3)  calibration();
  if(pointer[0] == 4)  reservoir();
  if(pointer[0] == 5)  nutSet();
  if(pointer[0] == 6)  schedule();
  if(pointer[0] == 7)  readings();
}

void settings()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("------Settings------");
  
  maximum = setMax;
  index = 1;
  temp = true;
  sub1 = false;
  pointer[1] = 1;
  
  while(temp == true)
  {
    maximum = setMax;
    index = 1;
    setMenu();
    response();
    if(sub1 == true)  sub1Menu();
  }
  temp = true;
  lcd.clear();
}

void setMenu()
{
  lcd.setCursor(0, 0);
  lcd.print("------Settings------");
  lcd.setCursor(0, 2);
  if(pointer[1] == 1)  lcd.print("1).Time & Date");
  if(pointer[1] == 2)  lcd.print("2).Reservoir Size");
  if(pointer[1] == 3)  lcd.print("3).Cycle Timer");
  if(pointer[1] == 4)  lcd.print("4).Chiller");
  if(pointer[1] == 5)  lcd.print("5).Carbon Dioxide");
  if(pointer[1] == 6)  lcd.print("6).Humidifier");
  if(pointer[1] == 7)  lcd.print("7).Ph Settings");
  
  
}


void sub1Menu()
{
  if(pointer[0] == 1 && pointer[1] == 1)  setTime();
  if(pointer[0] == 1 && pointer[1] == 2)  setReservoir();
  if(pointer[0] == 1 && pointer[1] == 3)  setCycle();
  if(pointer[0] == 1 && pointer[1] == 4)  setChiller();
  if(pointer[0] == 1 && pointer[1] == 5)  setCarbon();
  if(pointer[0] == 1 && pointer[1] == 6)  setHumidity();
  if(pointer[0] == 1 && pointer[1] == 7)  setPh();
  
}

void setTime()
{
  displayTime();
  
  maximum = timeMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    timeMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void timeMenu()
{
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  lcd.setCursor(9, 1);
  lcd.print(" ");
  lcd.setCursor(9, 2);
  lcd.print(" ");
  lcd.setCursor(9, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("mm:");
  lcd.print(minute);    
  lcd.setCursor(11, 2);
  lcd.print("mm:");
  lcd.print(month);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(4, 1);
    lcd.print(hour);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(hour <= 0)  hour =23;
      else hour--;
      delay(wait);
      displayTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(hour >= 23)  hour =0;
      else hour++;
      delay(wait);
      displayTime();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(4, 2);
    lcd.print(minute);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(minute <= 0)  minute =59;
      else minute--;
      delay(wait);
      displayTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(minute >= 59)  minute =0;
      else minute++;
      delay(wait);
      displayTime();
    }
  }
  
  if(pointer[2] == 3)
  {
    
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(4, 3);
    lcd.print(second);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(second <= 0)  second =59;
      else second--;
      delay(wait);
      displayTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(second >= 59)  second =0;
      else second++;
      delay(wait);
      displayTime();
    }
  }
  
  if(pointer[2] == 4)
  {
    
    lcd.setCursor(9, 1);
    lcd.print(">");
    lcd.setCursor(14, 1);
    lcd.print(year);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(year <= 0)  year =99;
      else year--;
      delay(wait);
      displayTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(year >= 99)  year =0;
      else year++;
      delay(wait);
      displayTime();
    }
  }
  
  if(pointer[2] == 5)
  {
    
    lcd.setCursor(9, 2);
    lcd.print(">");
    lcd.setCursor(14, 2);
    lcd.print(month);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(month <= 1)  month =12;
      else month--;
      delay(wait);
      displayTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(month >= 12)  month =1;
      else month++;
      delay(wait);
      displayTime();
    }
  }
  
  if(pointer[2] == 6)
  {
    
    lcd.setCursor(9, 3);
    lcd.print(">");
    lcd.setCursor(14, 3);
    lcd.print(monthDay);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(monthDay <= 1)  monthDay =31;
      else monthDay--;
      delay(wait);
      displayTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(monthDay >= 31)  monthDay =1;
      else monthDay++;
      delay(wait);
      displayTime();
    }
  }
}

void displayTime()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("-----Date & Time----");
  lcd.setCursor(1, 1);
  lcd.print("hh:       yy:");
  lcd.setCursor(1, 2);
  lcd.print("mm:       mm:");
  lcd.setCursor(1, 3);
  lcd.print("ss:       dd:");
  
  lcd.setCursor(4, 1);
  lcd.print(hour);
  lcd.setCursor(4, 2);
  lcd.print(minute);
  lcd.setCursor(4, 3);
  lcd.print(second);
  
  lcd.setCursor(14, 1);
  lcd.print(year);
  lcd.setCursor(14, 2);
  lcd.print(month);
  lcd.setCursor(14, 3);
  lcd.print(monthDay);
}

void setReservoir()
{
  displayRes();
  
  maximum = resMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    resMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void resMenu()
{
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("Water res Size:");
  lcd.setCursor(16, 2);
  lcd.print(waterSize);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(16, 2);
    lcd.print(waterSize);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(waterSize <= 0)  waterSize =waterMax;
      else waterSize--;
      delay(wait);
      displayRes();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(waterSize >= waterMax)  waterSize =0;
      else waterSize++;
      delay(wait);
      displayRes();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(16, 3);
    lcd.print(nutSize);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(nutSize <= 0)  nutSize =nutMax;
      else nutSize--;
      delay(wait);
      displayRes();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(nutSize >= nutMax)  nutSize =0;
      else nutSize++;
      delay(wait);
      displayRes();
    }
  }
}

void displayRes()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("---Reservoir Size---");
  lcd.setCursor(1, 2);
  lcd.print("Water res Size:");
  lcd.setCursor(1, 3);
  lcd.print("Nutrient Size:");
  
  lcd.setCursor(16, 2);
  lcd.print(waterSize);
  lcd.setCursor(16, 3);
  lcd.print(nutSize);
  
}

void setCycle()
{
  displayCycle();
  
  maximum = cycleMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    cycleMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void cycleMenu()
{
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("On Time:");
  lcd.setCursor(16, 2);
  lcd.print(onTime);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(16, 2);
    lcd.print(onTime);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(onTime <= 0)  onTime =onMax;
      else onTime--;
      delay(wait);
      displayCycle();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(onTime >= onMax)  onTime =0;
      else onTime++;
      delay(wait);
      displayCycle();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(16, 3);
    lcd.print(offTime);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(offTime <= 0)  offTime =offMax;
      else offTime--;
      delay(wait);
      displayCycle();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(offTime >= offMax)  offTime =0;
      else offTime++;
      delay(wait);
      displayCycle();
    }
  }
}



void displayCycle()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----Cycle Timer----");
  lcd.setCursor(1, 2);
  lcd.print("On Time:");
  lcd.setCursor(1, 3);
  lcd.print("Off Time:");
  
  lcd.setCursor(16, 2);
  lcd.print(onTime);
  lcd.setCursor(16, 3);
  lcd.print(offTime);
  
}

void setChiller()
{
  displayChiller();
  
  maximum = chillerMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    chillerMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void chillerMenu()
{
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("Stop Temp:");
  lcd.setCursor(16, 2);
  lcd.print(stopTemp);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(16, 1);
    lcd.print(startTemp);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(startTemp <= 0)  startTemp =startMax;
      else startTemp--;
      delay(wait);
      displayChiller();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(startTemp >= startMax)  startTemp =0;
      else startTemp++;
      delay(wait);
      displayChiller();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(16, 2);
    lcd.print(stopTemp);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(stopTemp <= 0)  stopTemp =stopMax;
      else stopTemp--;
      delay(wait);
      displayChiller();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(stopTemp >= stopMax)  stopTemp =0;
      else stopTemp++;
      delay(wait);
      displayChiller();
    }
  }
  
  if(pointer[2] == 3)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(16, 3);
    lcd.print(chilHys);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(chilHys<= 0)  chilHys =chilHysMax;
      else chilHys--;
      delay(wait);
      displayChiller();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(chilHys >= chilHysMax)  chilHys =0;
      else chilHys++;
      delay(wait);
      displayChiller();
    }
  }
}

void displayChiller()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("------Chiller------");
  lcd.setCursor(1, 1);
  lcd.print("Start Temp:");
  lcd.setCursor(1, 2);
  lcd.print("Stop Temp:");
  lcd.setCursor(1, 3);
  lcd.print("Hysteresis:");
  
  lcd.setCursor(16, 1);
  lcd.print(startTemp);
  lcd.setCursor(16, 2);
  lcd.print(stopTemp);
  lcd.setCursor(16, 3);
  lcd.print(chilHys);
  
}

void setCarbon()
{
  displayCarbon();
  
  maximum = carbonMenuMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    carbonMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void carbonMenu()
{
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("Desired PPM:");
  lcd.setCursor(16, 2);
  lcd.print(desCarbon);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(16, 2);
    lcd.print(desCarbon);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(desCarbon <= 0)  desCarbon =carbonMax;
      else desCarbon--;
      delay(wait);
      displayCarbon();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(desCarbon >= carbonMax)  desCarbon =0;
      else desCarbon++;
      delay(wait);
      displayCarbon();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(16, 3);
    lcd.print(carbonHys);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(carbonHys <= 0)  carbonHys =carbonHysMax;
      else carbonHys--;
      delay(wait);
      displayCycle();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(carbonHys >= carbonHysMax)  carbonHys =0;
      else carbonHys++;
      delay(wait);
      displayCycle();
    }
  }
}



void displayCarbon()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----CarbonDioxide---");
  lcd.setCursor(1, 2);
  lcd.print("Desired PPM:");
  lcd.setCursor(1, 3);
  lcd.print("Hysteresis:");
  
  lcd.setCursor(16, 2);
  lcd.print(desCarbon);
  lcd.setCursor(16, 3);
  lcd.print(carbonHys);
  
}

void setHumidity()
{
  displayHumidity();
  
  maximum = humidityMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    humidityMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void humidityMenu()
{
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("Light Off RH:");
  lcd.setCursor(16, 2);
  lcd.print(offRH);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(16, 1);
    lcd.print(onRH);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(onRH <= 0)  onRH =onRHMax;
      else onRH--;
      delay(wait);
      displayHumidity();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(onRH >= onRHMax)  onRH =0;
      else onRH++;
      delay(wait);
      displayHumidity();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(16, 2);
    lcd.print(offRH);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(offRH <= 0)  offRH =offRHMax;
      else offRH--;
      delay(wait);
      displayHumidity();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(offRH >= offRHMax)  offRH =0;
      else offRH++;
      delay(wait);
      displayHumidity();
    }
  }
  
  if(pointer[2] == 3)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(16, 3);
    lcd.print(RHHys);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(RHHys<= 0)  RHHys = RHHysMax;
      else RHHys--;
      delay(wait);
      displayHumidity();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(RHHys >= RHHysMax)  RHHys =0;
      else RHHys++;
      delay(wait);
      displayHumidity();
    }
  }
}

void displayHumidity()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("------Humidity------");
  lcd.setCursor(1, 1);
  lcd.print("Light On RH:");
  lcd.setCursor(1, 2);
  lcd.print("Light Off RH:");
  lcd.setCursor(1, 3);
  lcd.print("Hysteresis:");
  
  lcd.setCursor(16, 1);
  lcd.print(onRH);
  lcd.setCursor(16, 2);
  lcd.print(offRH);
  lcd.setCursor(16, 3);
  lcd.print(RHHys);
  
}

void setPh()
{
  displayPh();
  
  maximum = phMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    phMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void phMenu()
{
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("Down:");
  lcd.setCursor(15, 2);
  lcd.print(downPh);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(15, 1);
    lcd.print(upPh);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(upPh <= 0)  upPh =upPhMax;
      else upPh--;
      delay(wait);
      displayPh();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(upPh >= upPhMax)  upPh =0;
      else upPh++;
      delay(wait);
      displayPh();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(15, 2);
    lcd.print(downPh);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(downPh <= 0)  downPh =downPhMax;
      else downPh--;
      delay(wait);
      displayPh();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(downPh >= downPhMax)  downPh =0;
      else downPh++;
      delay(wait);
      displayPh();
    }
  }
  
  if(pointer[2] == 3)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(15, 3);
    lcd.print(setPhVal,1);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(setPhVal<= 0)  setPhVal =setPhValMax;
      else setPhVal-=0.1;
      delay(wait);
      displayPh();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(setPhVal >= setPhValMax)  setPhVal =0;
      else setPhVal+=0.1;
      delay(wait);
      displayPh();
    }
  }
}

void displayPh()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----Ph Settings----");
  lcd.setCursor(1, 1);
  lcd.print("Up:");
  lcd.setCursor(1, 2);
  lcd.print("Down:");
  lcd.setCursor(1, 3);
  lcd.print("Set Value:");
  
  lcd.setCursor(15, 1);
  lcd.print(upPh);
  lcd.print("ml/l");
  lcd.setCursor(15, 2);
  lcd.print(downPh);
  lcd.print("ml/l");
  lcd.setCursor(15, 3);
  lcd.print(setPhVal,1);
  
}


void pumps()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----Pump Settings---");
  
  maximum = pumpMax;
  index = 1;
  temp = true;
  sub1 = false;
  pointer[1] = 1;
  
  while(temp == true)
  {
    maximum = pumpMax;
    index = 1;
    pumpMenu();
    response();
    if(sub1 == true)  setPumps();
  }
  temp = true;
  lcd.clear();
}


void pumpMenu()
{
  lcd.setCursor(0, 0);
  lcd.print("----Pump Settings---");
  lcd.setCursor(0, 2);
  if(pointer[1] == 1)  lcd.print("1).Pump #1");
  if(pointer[1] == 2)  lcd.print("2).Pump #2");
  if(pointer[1] == 3)  lcd.print("3).Pump #3");
  if(pointer[1] == 4)  lcd.print("4).Pump #4");
  if(pointer[1] == 5)  lcd.print("5).Pump #5");
  if(pointer[1] == 6)  lcd.print("6).Pump #6");
  
}

void setPumps()
{
  displayPumps();
  
  maximum = subPumpMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = pump[pointer[1]-1];
  
  while(temp == true)
  {
    subPumpMenu();
    response();
    if(sub1 == true)
    {
      pump[pointer[1]-1]=pointer[2];
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
      pointer[2] = 0;
      break;
    }
  }
  temp = true;
  lcd.clear();
}

void subPumpMenu()
{
  
/*  lcd.setCursor(1, 2);
  lcd.print("Category:");
  lcd.setCursor(16, 2);
  lcd.print(offRH);*/
   
    if(digitalRead(leftPin) == LOW)
    {
      if(pointer[2] <= 0)  pointer[2] =subPumpMax;
      else pointer[2]--;
      delay(wait);
      displayPumps();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(pointer[2] >= subPumpMax)  pointer[2] =0;
      else pointer[2]++;
      delay(wait);
      displayPumps();
    }
  
}

void displayPumps()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("------Pump #");
  lcd.print(pointer[1]);
  lcd.print("------");
  
  lcd.setCursor(1, 1);
  lcd.print("Current:");
  if(pump[pointer[1]-1]==0)  lcd.print("Nutrient");
  if(pump[pointer[1]-1]==1)  lcd.print("Ph Up");
  if(pump[pointer[1]-1]==2)  lcd.print("Ph Down");
  if(pump[pointer[1]-1]==3)  lcd.print("Water");
  
  lcd.setCursor(1, 2);
  lcd.print("Category:");
  if(pointer[2]==0)  lcd.print("Nutrient");
  if(pointer[2]==1)  lcd.print("Ph Up");
  if(pointer[2]==2)  lcd.print("Ph Down");
  if(pointer[2]==3)  lcd.print("Water");
  
  
}

void calibration()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----Calibration----");
  
  maximum = calMax;
  index = 1;
  temp = true;
  sub1 = false;
  pointer[1] = 1;
  
  while(temp == true)
  {
    maximum = calMax;
    index = 1;
    sub1 = false;
    calMenu();
    response();
    if(sub1 == true)  setCal();
  }
  //temp = true;
  lcd.clear();
}

void calMenu()
{
  lcd.setCursor(0, 0);
  lcd.print("----Calibration----");
  lcd.setCursor(0, 2);
  if(pointer[1] == 1)  lcd.print("1).CarbonDioxide");
  if(pointer[1] == 2)  lcd.print("2).Temperature");
  if(pointer[1] == 3)  lcd.print("3).Ph Probe");
  if(pointer[1] == 4)  lcd.print("4).EC/TDS Probe");
  if(pointer[1] == 5)  lcd.print("5).Pumps");
  if(pointer[1] == 6)  lcd.print("6).Not set");
  
}

void setCal()
{
  if(pointer[1] == 1)
  {
    lcd.clear();
    lcd.setCursor(0, 1);  
    lcd.print("Calibrating CO2");
    delay(2000);
    lcd.setCursor(0, 2);
    lcd.print("Completed");
    delay(1000);
    temp == false;
    lcd.clear();
  }
  
  if(pointer[1] == 2)
  {
    lcd.clear();
    lcd.setCursor(0, 1);  
    lcd.print("Calibrating Temp");
    delay(2000);
    lcd.setCursor(0, 2);
    lcd.print("Completed");
    delay(1000);
    temp == false;
    lcd.clear();
  }
  
  if(pointer[1] == 3)
  {
    lcd.clear();
    lcd.setCursor(0, 1);  
    lcd.print("Calibrating Ph");
    delay(2000);
    lcd.setCursor(0, 2);
    lcd.print("Completed");
    delay(1000);
    temp == false;
    lcd.clear();
  }
  
  if(pointer[1] == 4)
  {
    lcd.clear();
    lcd.setCursor(0, 1);  
    lcd.print("Calibrating EC/TDS");
    delay(2000);
    lcd.setCursor(0, 2);
    lcd.print("Completed");
    delay(1000);
    temp == false;
    lcd.clear();
  }
  
  if(pointer[1] == 5)
  {
    lcd.clear();
    lcd.setCursor(0, 1);  
    lcd.print("Calibrating Pumps");
    delay(2000);
    lcd.setCursor(0, 2);
    lcd.print("Completed");
    delay(1000);
    temp == false;
    lcd.clear();
  }
  
  if(pointer[1] == 6)
  {
    lcd.clear();
    lcd.setCursor(0, 1);  
    lcd.print("Calibrating Not Set");
    delay(2000);
    lcd.setCursor(0, 2);
    lcd.print("Completed");
    delay(1000);
    temp == false;
    lcd.clear();
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reservoir()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("--Reservoir Change--");
  
  maximum = resChangeMax;
  index = 1;
  temp = true;
  sub1 = false;
  pointer[1] = 1;
  
  while(temp == true)
  {
    maximum = resChangeMax;
    index = 1;
    resFreqMenu();
    response();
    if(sub1 == true)  subResMenu();
    
  }
  temp = true;
  lcd.clear();
}

void resFreqMenu()
{
  lcd.setCursor(0, 0);
  lcd.print("--Reservoir Change--");
  lcd.setCursor(0, 2);
  if(pointer[1] == 1)  lcd.print("1).Time & Date");
  if(pointer[1] == 2)  lcd.print("2).Frequency");
  if(pointer[1] == 3)  lcd.print("3).Manual Change");
  
}


void subResMenu()
{
  if(pointer[0] == 4 && pointer[1] == 1)  resTime();
  if(pointer[0] == 4 && pointer[1] == 2)  resFreq();
  if(pointer[0] == 4 && pointer[1] == 3)  resManual();
}

void resTime()
{
  displayResTime();
  
  maximum = timeResMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    timeResMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  //temp = true;
  lcd.clear();
}

void timeResMenu()
{
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("mm:");
  lcd.print(resMinute);    
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(4, 1);
    lcd.print(resHour);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(resHour <= 0)  resHour =23;
      else resHour--;
      delay(wait);
      displayResTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(resHour >= 23)  resHour =0;
      else resHour++;
      delay(wait);
      displayResTime();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(4, 2);
    lcd.print(resMinute);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(resMinute <= 0)  resMinute =59;
      else resMinute--;
      delay(wait);
      displayResTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(resMinute >= 59)  resMinute =0;
      else resMinute++;
      delay(wait);
      displayResTime();
    }
  }
  
  if(pointer[2] == 3)
  {
    
    lcd.setCursor(0, 3);
    lcd.print(">");
    
    if(digitalRead(leftPin) == LOW)
    {
      if(resDay <= 0)  resDay =6;
      else resDay--;
      delay(wait);
      displayResTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(resDay >= 6)  resDay =0;
      else resDay++;
      delay(wait);
      displayResTime();
    }
  }
  
}

void displayResTime()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("-----Date & Time----");
  lcd.setCursor(1, 1);
  lcd.print("hh:");
  lcd.setCursor(1, 2);
  lcd.print("mm:");
  lcd.setCursor(1, 3);
  lcd.print("dd:");
  
  lcd.setCursor(4, 1);
  lcd.print(resHour);
  lcd.setCursor(4, 2);
  lcd.print(resMinute);
  lcd.setCursor(4, 3);
  if(resDay==0)  lcd.print("MON");
  if(resDay==1)  lcd.print("TUE");
  if(resDay==2)  lcd.print("WED");
  if(resDay==3)  lcd.print("THU");
  if(resDay==4)  lcd.print("FRI");
  if(resDay==5)  lcd.print("SAT");
  if(resDay==6)  lcd.print("SUN");
}

void resFreq()
{
  displayFreq();
  
  maximum = freqMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    freqMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void freqMenu()
{
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("Every Week:");
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 2);
    lcd.print(">");
    freq = pointer[2];
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(16, 3);
    freq = pointer[2];
  }
}

void displayFreq()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("---Reservoir Freq---");
  lcd.setCursor(1, 2);
  lcd.print("Every Week");
  lcd.setCursor(1, 3);
  lcd.print("Every Two Weeks");
  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void resManual()
{
  displayManTime();
  
  maximum = manualTimeMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    manTimeMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
    }
  }
  //temp = true;
  lcd.clear();
}

void manTimeMenu()
{
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  lcd.setCursor(9, 1);
  lcd.print(" ");
  lcd.setCursor(9, 2);
  lcd.print(" ");
  
  
  lcd.setCursor(1, 2);
  lcd.print("mm:");
  lcd.print(manMinute);    
  lcd.setCursor(11, 2);
  lcd.print("mm:");
  lcd.print(manMonth);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(4, 1);
    lcd.print(manHour);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(manHour <= 0)  manHour =23;
      else manHour--;
      delay(wait);
      displayManTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(manHour >= 23)  manHour =0;
      else manHour++;
      delay(wait);
      displayManTime();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(4, 2);
    lcd.print(manMinute);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(minute <= 0)  manMinute =59;
      else manMinute--;
      delay(wait);
      displayManTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(manMinute >= 59)  manMinute =0;
      else manMinute++;
      delay(wait);
      displayManTime();
    }
  }
  
  if(pointer[2] == 3)
  {
    
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(9, 3);
    lcd.print(liters);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(liters <= 0)  liters =ltrMax;
      else liters--;
      delay(wait);
      displayManTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(liters >= ltrMax)  liters =0;
      else liters++;
      delay(wait);
      displayManTime();
    }
  }
  
  if(pointer[2] == 4)
  {
    
    lcd.setCursor(9, 1);
    lcd.print(">");
    lcd.setCursor(14, 1);
    lcd.print(manDate);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(manDate <= 0)  manDate =31;
      else manDate--;
      delay(wait);
      displayManTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(manDate >= 31)  manDate =0;
      else manDate++;
      delay(wait);
      displayManTime();
    }
  }
  
  if(pointer[2] == 5)
  {
    
    lcd.setCursor(9, 2);
    lcd.print(">");
    lcd.setCursor(14, 2);
    lcd.print(manMonth);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(manMonth <= 0)  manMonth =12;
      else manMonth--;
      delay(wait);
      displayManTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(manMonth >= 12)  manMonth =0;
      else manMonth++;
      delay(wait);
      displayManTime();
    }
  }
  
}

void displayManTime()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("-----Date & Time----");
  lcd.setCursor(1, 1);
  lcd.print("hh:       dd:");
  lcd.setCursor(1, 2);
  lcd.print("mm:       mm:");
  lcd.setCursor(1, 3);
  lcd.print("liters:");
  
  lcd.setCursor(4, 1);
  lcd.print(manHour);
  lcd.setCursor(4, 2);
  lcd.print(manMinute);
  lcd.setCursor(9, 3);
  lcd.print(liters);
  
  lcd.setCursor(14, 1);
  lcd.print(manDate);
  lcd.setCursor(14, 2);
  lcd.print(manMonth);
}


void nutSet()
{
  lcd.clear();
  
  maximum = nutMax;
  index = 1;
  temp = true;
  sub1 = false;
  pointer[1] = 1;
  
  while(temp == true)
  {
    maximum = nutMax;
    index = 1;
    nutMenu();
    response();
    if(sub1 == true)  setBot();
  }
  temp = true;
  lcd.clear();
}

void nutMenu()
{
  lcd.setCursor(0, 0);
  lcd.print("--N Bottle Settings-");
  lcd.setCursor(0, 2);
  lcd.print(pointer[1]);
  lcd.print(").Nut. Bottle #");
  lcd.print(pointer[1]);
  
}


void setBot()
{
  displayBot();
  
  maximum = botMax;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    botMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      currentNut[pointer[1]-1] += manualNut[pointer[1]-1];
      lcd.print("Saved");
      delay(1000);
      temp = false;
      
    }
  }
  temp = true;
  lcd.clear();

}

void botMenu()
{
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("Bottle Size:");
  lcd.setCursor(15, 2);
  lcd.print(botSize[pointer[1]-1]);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(15, 2);
    lcd.print(botSize[pointer[1]-1]);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(botSize[pointer[1]-1] <= 1000)  botSize[pointer[1]-1] =5000;
      else botSize[pointer[1]-1]--;
      delay(wait);
      displayBot();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(botSize[pointer[1]-1] >= 5000)  botSize[pointer[1]-1] =1000;
      else botSize[pointer[1]-1]++;
      delay(wait);
      displayBot();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(15, 3);
    lcd.print(manualNut[pointer[1]-1]);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(manualNut[pointer[1]-1] <= 0)  manualNut[pointer[1]-1] =botSize[pointer[1]-1];
      else manualNut[pointer[1]-1]--;
      delay(wait);
      displayBot();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(manualNut[pointer[1]-1] >= botSize[pointer[1]-1])  manualNut[pointer[1]-1] =0;
      else manualNut[pointer[1]-1]++;
      delay(wait);
      displayBot();
    }
  }
  
}

void displayBot()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("---Nut. Bottle #");
  lcd.print(pointer[1]);
  lcd.print("---");
  lcd.setCursor(1, 1);
  lcd.print("Remaining:");
  lcd.setCursor(1, 2);
  lcd.print("Bottle Size:");
  lcd.setCursor(1, 3);
  lcd.print("Manual Refill:");
  
  lcd.setCursor(15, 1);
  lcd.print(currentNut[pointer[1]-1]);
  lcd.setCursor(15, 2);
  lcd.print(botSize[pointer[1]-1]);
  lcd.setCursor(15, 3);
  lcd.print(manualNut[pointer[1]-1]);
  
}

void schedule()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----N. Schedule----");
  
  maximum = 2;
  index = 1;
  temp = true;
  sub1 = false;
  pointer[1] = 1;
  
  while(temp == true)
  {
    maximum = 2;
    index = 1;
    scheduleMenu();
    response();
    if(sub1 == true)  subNutMenu();
  }
  temp = true;
  lcd.clear();
}

void scheduleMenu()
{
  lcd.setCursor(0, 0);
  lcd.print("----N. Schedule----");
  lcd.setCursor(0, 2);
  if(pointer[1] == 1)  lcd.print("1).Set Start Time");
  if(pointer[1] == 2)  lcd.print("2).Manual Control");  
  
}

void subNutMenu()
{
  if(pointer[0] == 6 && pointer[1] == 1)  setNutTime();
  if(pointer[0] == 6 && pointer[1] == 2)  manualNutSet();
  
}

void setNutTime()
{
  displayNutTime();
  
  maximum = 3;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    nutTimeMenu();
    response();
    if(sub1 == true)
    {
      lcd.clear();
      lcd.setCursor(6, 1);
      lcd.print("Saved");
      delay(1000);
      temp = false;
      startState = false;
      weekCount = 0;
    }
  }
  temp = true;
  lcd.clear();
}

void nutTimeMenu()
{
  lcd.setCursor(0, 1);
  lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("hh:");
  lcd.setCursor(16, 2);
  lcd.print(startHour);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(16, 1);
    lcd.print(startDate);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(startDate <= 1)  startDate =31;
      else startDate--;
      delay(wait);
      displayNutTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(startDate >= 31)  startTemp =1;
      else startDate++;
      delay(wait);
      displayNutTime();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(16, 2);
    lcd.print(startHour);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(startHour <= 0)  startHour =23;
      else startHour--;
      delay(wait);
      displayNutTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(startHour >= 23)  startHour =0;
      else startHour++;
      delay(wait);
      displayNutTime();
    }
  }
  
  if(pointer[2] == 3)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(16, 3);
    lcd.print(startMinute);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(startMinute<= 0)  startMinute =59;
      else startMinute--;
      delay(wait);
      displayNutTime();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(startMinute >= 59)  startMinute =0;
      else startMinute++;
      delay(wait);
      displayNutTime();
    }
  }
}

void displayNutTime()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----Set Start----");
  lcd.setCursor(1, 1);
  lcd.print("Start Date:");
  lcd.setCursor(1, 2);
  lcd.print("Start Hour:");
  lcd.setCursor(1, 3);
  lcd.print("Start Minute:");
  
  lcd.setCursor(16, 1);
  lcd.print(startDate);
  lcd.setCursor(16, 2);
  lcd.print(startHour);
  lcd.setCursor(16, 3);
  lcd.print(startMinute);
  
}

void manualNutSet()
{
  displayNut();
  
  maximum = 2;
  index = 2;
  temp = true;
  sub1 = false;
  pointer[2] = 1;
  
  while(temp == true)
  {
    nutSetMenu();
    response();
    if(sub1 == true)
    {
      int pumpOnTime = nutVolume/pumpRate;
      lcd.clear();
      lcd.setCursor(4, 1);
      lcd.print("Please Wait");
      digitalWrite(pumpPin[pumpNum-1],HIGH);
      delay(pumpOnTime);
      digitalWrite(pumpPin[pumpNum-1],LOW);
      currentNut[pumpNum-1] -= nutVolume;
      temp = false;
    }
  }
  temp = true;
  lcd.clear();
}

void nutSetMenu()
{
  
  lcd.setCursor(0, 2);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print(" ");
  
  lcd.setCursor(1, 2);
  lcd.print("Pump #:");
  lcd.setCursor(16, 2);
  lcd.print(pumpNum);
    
  if(pointer[2] == 1)
  {

    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(16, 2);
    lcd.print(pumpNum);
   
    if(digitalRead(leftPin) == LOW)
    {
      if(pumpNum <= 1)  pumpNum =6;
      else pumpNum--;
      delay(wait);
      displayNut();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(pumpNum >= 6)  pumpNum =1;
      else pumpNum++;
      delay(wait);
      displayNut();
    }
  }
  
  if(pointer[2] == 2)
  {
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(16, 3);
    lcd.print(nutVolume);
    
    if(digitalRead(leftPin) == LOW)
    {
      if(nutVolume <= 0)  nutVolume =currentNut[pumpNum-1];
      else nutVolume--;
      delay(wait);
      displayNut();
    }
    if(digitalRead(rightPin) == LOW)
    {
      if(nutVolume >= currentNut[pumpNum-1])  nutVolume =0;
      else nutVolume++;
      delay(wait);
      displayNut();
    }
  }
  
}

void displayNut()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("----Manual Feed----");
  lcd.setCursor(1, 2);
  lcd.print("Pump #:");
  lcd.setCursor(1, 3);
  lcd.print("Volume(ml):");

  
  lcd.setCursor(16, 2);
  lcd.print(pumpNum);
  lcd.setCursor(16, 3);
  lcd.print(nutVolume);
  
}


void readings()
{
  temp = true;
  sub1 = false;
  while(temp == true)
  {
    response();
    ec();
    printDate();
  if(millis()-startRead > reads)
    {
      startRead = millis();
      
      lcd.clear();
      lcd.setCursor(0, 0);
      
      printec();
      
      temperature();
      humidity();
      ph();
      CO2();

    }
  }
  lcd.clear();
  temp = true;
  index = 1;
}

void response()
{
    if(digitalRead(backPin)==LOW)  // back pin is pressed
    {
      while(digitalRead(backPin) == LOW);
      for(int i= 0; i<6 ; i++)
      {
        temp = false;
      }
      
    }
    
    else if(digitalRead(downPin)==LOW)
    {
      while(digitalRead(downPin) == LOW);
      if(pointer[index] == maximum)  pointer[index] = maximum;
      else pointer[index] ++;
      
      lcd.setCursor(0, 2);
      lcd.print("                    ");
    }
    
    else if(digitalRead(upPin)==LOW)
    {
      while(digitalRead(upPin) == LOW);
      if (pointer[index] == 1)  pointer[index] = 1;
      else pointer[index] --;
      
      lcd.setCursor(0, 2);
      lcd.print("                    ");
    }
    
    else if(digitalRead(okPin) == LOW)
    {
      while(digitalRead(okPin) == LOW);
      sub1 = true;
    }
}


