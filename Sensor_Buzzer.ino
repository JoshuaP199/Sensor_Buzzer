#include "SR04.h"
#include "pitches.h"
#include "LiquidCrystal.h"

#define TRIG_PIN 4
#define ECHO_PIN 3

#define RED 2
#define GREEN 7

LiquidCrystal lcd(6, 13, 9, 10, 11, 12); //lcd pins for RS,E,D4,D5,D6,D7

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

void setup() {
  Serial.begin(9600);  //allows to watch what is being sent in the serial monitor on that channel
  pinMode(RED, OUTPUT); //Saying that RED is an output
  pinMode(GREEN, OUTPUT);
  digitalWrite(RED, LOW); //tells RED to be given 0V
  digitalWrite(GREEN, HIGH); //tells GREEN to be given 5V
  lcd.begin(10, 2);
}

void loop() {  
  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");
  lcd.setCursor(0,0);
  lcd.print(a);
  if (a < 20) {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    tone(8, NOTE_A3, 150);
  }
  else {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
  }
  delay(300);
  lcd.clear();
}
