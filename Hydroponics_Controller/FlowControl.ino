void flow()
{
  if(digitalRead(resetButtonA) == LOW)
  {
    totalMilliLitresA = 0;
//    lcd.setCursor(0, 1);
//    lcd.print("0L      ");
  }
  if(digitalRead(resetButtonB) == LOW)
  {
    totalMilliLitresB = 0;
//    lcd.setCursor(8, 1);
//    lcd.print("0L      ");
  }
  
  if( (digitalRead(resetButtonA) == LOW) || (digitalRead(resetButtonB) == LOW) )
  {
    digitalWrite(statusLed, LOW);
  } else {
    digitalWrite(statusLed, HIGH);
  }
  
  if((millis() - oldTime) > 1000)    // Only process counters once per second
  { 
    // Disable the interrupt while calculating flow rate and sending the value to
    // the host
    detachInterrupt(sensorInterrupt);
   // lcd.setCursor(15, 0);
    //lcd.print("*");
    
    // Because this loop may not complete in exactly 1 second intervals we calculate
    // the number of milliseconds that have passed since the last execution and use
    // that to scale the output. We also apply the calibrationFactor to scale the output
    // based on the number of pulses per second per units of measure (litres/minute in
    // this case) coming from the sensor.
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    
    // Note the time this processing pass was executed. Note that because we've
    // disabled interrupts the millis() function won't actually be incrementing right
    // at this point, but it will still return the value it was set to just before
    // interrupts went away.
    oldTime = millis();
    
    // Divide the flow rate in litres/minute by 60 to determine how many litres have
    // passed through the sensor in this 1 second interval, then multiply by 1000 to
    // convert to millilitres.
    flowMilliLitres = (flowRate / 60) * 1000;
    
    // Add the millilitres passed in this second to the cumulative total
    totalMilliLitresA += flowMilliLitres;
    totalMilliLitresB += flowMilliLitres;
  
    // During testing it can be useful to output the literal pulse count value so you
    // can compare that and the calculated flow rate against the data sheets for the
    // flow sensor. Uncomment the following two lines to display the count value.
    //Serial.print(pulseCount, DEC);
    //Serial.print("  ");
    
    // Write the calculated value to the serial port. Because we want to output a
    // floating point value and print() can't handle floats we have to do some trickery
    // to output the whole number part, then a decimal point, then the fractional part.
    unsigned int frac;
    
    // Print the flow rate for this second in litres / minute
   // Serial.print(int(flowRate));  // Print the integer part of the variable
    //Serial.print(".");             // Print the decimal point
    // Determine the fractional part. The 10 multiplier gives us 1 decimal place.
    frac = (flowRate - int(flowRate)) * 10;
    //Serial.print(frac, DEC) ;      // Print the fractional part of the variable

    // Print the number of litres flowed in this second
    Serial.print(" ");             // Output separator
    Serial.print(flowMilliLitres);

    // Print the cumulative total of litres flowed since starting
    Serial.print(" ");             // Output separator
    Serial.print(totalMilliLitresA);
    Serial.print(" ");             // Output separator
    Serial.println(totalMilliLitresB);
    
    
    lcd.setCursor(0, 0);
    //lcd.print("Debit:");
    if(int(flowRate) < 10)
    {
      lcd.print(" ");
    }
    lcd.print((int)flowRate);   // Print the integer part of the variable
    lcd.print('.');             // Print the decimal point
    lcd.print(frac, DEC) ;      // Print the fractional part of the variable
    lcd.print(" L");
    lcd.print("/min");
    
    /*lcd.setCursor(0, 1);
    lcd.print(int(totalMilliLitresA / 1000));
    lcd.print(":L");
    lcd.setCursor(8, 1);
    lcd.print(int(totalMilliLitresB / 1000));
    lcd.print(":L");*/

    // Reset the pulse counter so we can start incrementing again
    pulseCount = 0;
    
    // Enable the interrupt again now that we've finished sending output
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
}

/**
 * Invoked by interrupt0 once per rotation of the hall-effect sensor. Interrupt
 * handlers should be kept as small as possible so they return quickly.
 */
void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}
