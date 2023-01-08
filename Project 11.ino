#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2); 

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
void setup() {
  lcd.begin(16,2);
  
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0,1); // changes the Cursor to continue 
//writing in the second row
  lcd.print("Crystal Ball!");
}
void loop() {
  switchState=digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    if (switchState == HIGH) {
      reply = random(8);
      lcd.clear(); // clears the writing
      lcd.setCursor(0,0);
      lcd.print("The ball says:");
      lcd.setCursor(0,1);

      switch(reply){ // the program will enter the case 
//assigned to the switch
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("You dumb");
        break;
        case 2:
        lcd.print("You ugly");
        break;
        case 3:
        lcd.print("You fat");
        break;
        case 4:
        lcd.print("You smart as hell");
        break;
        case 5:
        lcd.print("Nah");
        break;
        case 6:
        lcd.print("Try again later");
        break;
        case 7:
        lcd.print("Go away");
        break;
      }
    }
  }
  

}
