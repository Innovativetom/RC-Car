// include the libraries //
#include <LiquidCrystal.h> //lcd 16x2 library
#include <Servo.h> //servo library for controlling the motors and stearing servo

// initialize the libraries, pins and variables
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int leftStickXAxisPin = 0;
int leftStickYAxisPin = 1;

int leftStickXAxisVal = 0;
int leftStickYAxisVal = 0;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
}

void loop() {
  // set the cursor to (0,0):
  //left sitck x axis
  lcd.setCursor(0, 0);  
  leftStickXAxisVal = stickinput(leftStickXAxisPin);
  lcd.print("LX :");
  lcd.print(leftStickXAxisVal);
  //left stick y axis
  lcd.setCursor(0, 1);  
  leftStickYAxisVal = stickinput(leftStickYAxisPin);
  lcd.print("LY :");
  lcd.print(leftStickYAxisVal);
  delay(100);
  lcd.clear();
}
