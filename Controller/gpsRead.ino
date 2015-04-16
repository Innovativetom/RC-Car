void gpsRead(){
if(Serial.available() > 1)
{
  if (char(Serial.read()) == 'R' && char(Serial.read()) == 'M' && char(Serial.read()) == 'C')
    {
      gpsTime(Serial.parseInt());
      Serial.parseFloat(); //discard unnecessary part
      gpsLatLong(Serial.parseInt(), Serial.parseInt(), Serial.parseInt(), Serial.parseInt());
      gpsSpeed = Serial.parseFloat()*1.852; //km/h
      gpsBearing = Serial.parseFloat();
      gpsDate(Serial.parseInt());
      if (gpsYear%4 == 0) DaysAMonth[1] = 29; //leap year check
 
      //Time zone adjustment
      gpsHour += TimeZone;
      //DST adjustment
      if (gpsMonth*100+gpsDay >= DSTbegin[gpsYear-13] &&
        gpsMonth*100+gpsDay < DSTend[gpsYear-13]) gpsHour += 1;
      if (gpsHour < 0)
      {
        gpsHour += 24;
        gpsDay -= 1;
        if (gpsDay < 1)
        {
          if (gpsMonth == 1)
          {
            gpsMonth = 12;
            gpsYear -= 1;
          }
          else
          {
            gpsMonth -= 1;
          }
          gpsDay = DaysAMonth[gpsMonth-1];
        }
      }
      if (gpsHour >= 24)
      {
        gpsHour -= 24;
        gpsDay += 1;
        if (gpsDay > DaysAMonth[gpsMonth-1])
        {
          gpsDay = 1;
          gpsMonth += 1;
          if (gpsMonth > 12) gpsYear += 1;
        }
      }
  lcd.setCursor(0,0); 
  lcd.print(gpsLat);
  lcd.print(":");
  lcd.print(gpsLong);
}

}
}

void gpsTime(long UTC)
{
  gpsHour = int(UTC/10000);
  gpsMin = int(UTC%10000/100);
  gpsSec = UTC%100;
}
 
void gpsLatLong(int lat1, int lat2, int long1, int long2)
{
  gpsLat = int(lat1/100) + (lat1%100)/60.0 + float(lat2)/10000.0/60.0;

  gpsLong = int(long1/100) + (long1%100)/60.0 + float(long2)/10000.0/60.0;

}
 
void gpsDate(long dateRead)
{
  gpsDay = int(dateRead/10000);
  gpsMonth = int(dateRead%10000/100);
  gpsYear = dateRead%100; //last 2 digits, e.g. 2013-> 13
}
