#include<avr/wdt.h>
const int SW_pin = 2;
int Flag = 1;
int SW_State = 0;

void setup() {
  // put your setup code here, to run once:
  wdt_enable(WDTO_2S);
  pinMode(SW_pin, INPUT);
  Serial.begin(9600);
  Flag = 2;
  Serial.println("init");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Flag)
  {
    SW_State = digitalRead(SW_pin);
    Serial.println(Flag);
    if(SW_State == HIGH)
    {
      Flag = 0;
    }
    delay(200);
  }
  Serial.println("Push!");
  wdt_reset();
  Flag = 3;
}
