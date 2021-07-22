void level(){
  //read the switch value into a variable
  int sensorVal = digitalRead(levelSW);

  if (sensorVal == HIGH) {
    digitalWrite(waterInPin, LOW);    
  } 
  else {
    digitalWrite(waterInPin, HIGH); 
  }
}
