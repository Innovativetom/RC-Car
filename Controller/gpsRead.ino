void gpsRead(){
   if (gps.available() > 1)
  {
    if (char(gps.read()) == 'R' && char(gps.read()) == 'M' && char(gps.read()) == 'C')
    {
      gpsTime(gps.parseInt());
      gps.parseFloat(); //discard unnecessary part
      gpsLatLong(gps.parseInt(), gps.parseInt(), gps.parseInt(), gps.parseInt());
      gpsSpeed = gps.parseFloat()*1.852; //km/h
      gpsBearing = gps.parseFloat();
      gpsDate(gps.parseInt());
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
       
      Serial.print(gpsDay);
      Serial.print("/");
      Serial.print(gpsMonth);
      Serial.print("/");
      Serial.print(gpsYear);
      Serial.print(" ");
      Serial.print(gpsHour);
      Serial.print(":");
      Serial.println(gpsMin);
      Serial.println(gpsBearing);
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
   Serial.print("Lat: ");
   Serial.print(gpsLat,4);
   Serial.print(" Long: ");
  gpsLong = int(long1/100) + (long1%100)/60.0 + float(long2)/10000.0/60.0;
   Serial.println(gpsLong,4);
}
 
void gpsDate(long dateRead)
{
  gpsDay = int(dateRead/10000);
  gpsMonth = int(dateRead%10000/100);
  gpsYear = dateRead%100; //last 2 digits, e.g. 2013-> 13
}
