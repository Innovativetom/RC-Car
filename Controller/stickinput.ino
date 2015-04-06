int stickinput(int pin){
  int readVal;
  readVal = analogRead(pin);
  readVal = map(readVal, 0, 1024, 1000, 2000);
  delay(1);  
  return readVal;
}
