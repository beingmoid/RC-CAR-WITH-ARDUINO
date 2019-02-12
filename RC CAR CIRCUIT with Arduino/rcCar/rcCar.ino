/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 1);
  // Print a message to the LCD.

  
 pinMode(8,INPUT);
  pinMode(9,INPUT);
 pinMode(10,INPUT);
    pinMode(6,OUTPUT);//LEFT motor
     pinMode(7,OUTPUT);//RIGHT_MOTOR
    
 
      int leftSensor=8;
      int rightSensor=9;
      int MidSensor=10;
    
 
}

void loop() {
  
 if(digitalRead(10)==HIGH && digitalRead(8)==LOW && digitalRead(9)==LOW)
 {
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  lcd.print("BOTH MOTOR");
  
 }
  else if(digitalRead(10)==HIGH && digitalRead(9)==HIGH&& digitalRead(8)==LOW) //MIDRIGHT
 {
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      lcd.print("RIGHT MOTOR");
  
 }
 else if(digitalRead(10)==HIGH && digitalRead(8)==HIGH&& digitalRead(9)==LOW)//MIDLEFT
 {
   digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
      lcd.print("LEFT MOTOR");
 }
   else if(digitalRead(10)==LOW && digitalRead(8)==LOW && digitalRead(9)==LOW)//ALLLOW
 {
   digitalWrite(7,LOW);
      digitalWrite(6,LOW);
 }
  else if(digitalRead(10)==LOW && digitalRead(8)==HIGH && digitalRead(9)==LOW)//ALLLOW
 {
   digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      lcd.print("RIGHT MOTOR");
 }
   else if(digitalRead(10)==LOW && digitalRead(8)==LOW && digitalRead(9)==HIGH)//ALLLOW
 {
   digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
      lcd.print("LEFT MOTOR");
 }
   lcd.setCursor(1,0);
 
}

