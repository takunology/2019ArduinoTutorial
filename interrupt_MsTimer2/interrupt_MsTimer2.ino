#include <FlexiTimer2.h>
using namespace FlexiTimer2;

const int LED_pin = 11;

void flash()
{
  static int state = HIGH;
  digitalWrite(LED_pin, state);
  state = !state;  
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_pin, OUTPUT);
  set(600, flash);
  start();
}

void loop() {
  // put your main code here, to run repeatedly:

}
