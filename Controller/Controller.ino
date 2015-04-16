// include the libraries //
#include <LiquidCrystal.h> //lcd 16x2 library
#include <Servo.h> //servo library for controlling the motors and stearing servo

// initialize the libraries, pins and variables
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

Servo drive; 
Servo stearing;
int leftStickXAxisPin = 0; 
int leftStickYAxisPin = 1;

//stick values
int leftStickXAxisVal = 0;
int leftStickYAxisVal = 0;

void setup() {
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




