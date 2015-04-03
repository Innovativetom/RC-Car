int stickinput(int pin){
  int readVal;
  readVal = analogRead(pin);
  delay(1);  
  return readVal;
}
