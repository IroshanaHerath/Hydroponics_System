void readSD()
{
  dataCount = 0;
  Serial.print("Initializing SD card...");
  lcd.print("Initializing SD card...");
  delay(1000);
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.

  if (!SD.begin(4)) 
  {
    Serial.println("initialization failed!");
    lcd.clear();
    lcd.print("Initializing Failed!");
    delay(2000);
    //return;
  }
  Serial.println("initialization done.");
  lcd.clear();
  lcd.print("Initializing Done!");
  delay(1000);

  // re-open the file for reading:
  myFile = SD.open("data.txt");
  if (myFile) 
  {
    Serial.println("data.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) 
    {
      sdData[dataCount] = myFile.parseInt();
      dataCount++;
    }
    // close the file:
    myFile.close();
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
    lcd.clear();
    lcd.print("Error Data File!");
    delay(2000);
  }
  totalWeeks = dataCount/4;
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  dataCount = 0;

  if (!SD.begin(4)) 
  {
    Serial.println("initialization failed!");
    lcd.clear();
    lcd.print("Initializing Failed!");
    delay(2000);
    //return;
  }
  Serial.println("initialization done.");
  lcd.clear();
  lcd.print("Initializing Done!");
  delay(1000);

  // re-open the file for reading:
  myFile = SD.open("parameters.txt");
  if (myFile) 
  {
    Serial.println("parameters.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) 
    {
      sdPara[dataCount] = myFile.parseInt();
      dataCount++;
    }
    // close the file:
    myFile.close();
  } 
  else 
  {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
    lcd.clear();
    lcd.print("Error Data File!");
    delay(2000);
  }
  
  setSDData();
}

void setSDData()
{
  int count = 0;
  for(int i= 0;i<totalWeeks;i++)
  {
    for(int j=0;j<4;j++)
    {
      data[i][j] = sdData[count];
      count++;
    }
  }
  
  setPhVal = sdPara[0];    // set Ph value
  
  onRH = sdPara[1];        // lights on Humid value
  offRH = sdPara[2];      // lights off Humid value
  RHHys = sdPara[3];      // humid hysteresis
  
  desCarbon = sdPara[4];   // desired co2 value
  carbonHys = sdPara[5];
  
  startTemp = sdPara[6];
  stopTemp = sdPara[7];
  chilHys = sdPara[8];
}
