// include the libraries //
#include <LiquidCrystal.h> //lcd 16x2 library
#include <Servo.h> //servo library for controlling the motors and stearing servo
#include <Timer.h>



// initialize the libraries, pins and variables
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

Servo drive; 
Servo stearing;
int leftStickXAxisPin = 0; 
int leftStickYAxisPin = 1;

//gps values
const int TimeZone = -5;
int DSTbegin[] = { //DST 2013 - 2025 in Canada and US
  310, 309, 308, 313, 312, 311, 310, 308, 314, 313, 312, 310, 309};
int DSTend[] = { //DST 2013 - 2025 in Canada and US
  1103, 1102, 1101, 1106, 1105, 1104, 1103, 1101, 1107, 1106, 1105, 1103, 1102};
int DaysAMonth[] = { //number of days a month
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
int gpsYear;
int gpsMonth;
int gpsDay = 0;
int gpsHour;
byte gpsMin;
byte gpsSec;
float gpsLat0;
float gpsLong0;
float gpsLat;
float gpsLong;
float gpsSpeed; //km/h
float gpsBearing; //deg

//stick values
int leftStickXAxisVal = 0;
int leftStickYAxisVal = 0;

Timer t;

void setup() {
  Serial.begin(38400);  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
  drive.attach(6);
  stearing.attach(9);
}

void loop() {
  //set the cursor to (0,0):
  //left sitck x axis

  //  leftStickXAxisVal = stickinput(leftStickXAxisPin);
  //  lcd.print("LX :");
  //  lcd.print(leftStickXAxisVal);
  t.every(1000, gpsRead);
  


  lcd.setCursor(0,1);
  leftStickYAxisVal = stickinput(leftStickYAxisPin);
  lcd.print("LY :");
  lcd.print(leftStickYAxisVal);


  if ((leftStickYAxisVal<1550) && (leftStickYAxisVal>1450)){
    drive.writeMicroseconds(1500);
    lcd.print(1500);
  }
  else {
    drive.writeMicroseconds(leftStickYAxisVal);
  }
delay(100);
lcd.clear();

}




