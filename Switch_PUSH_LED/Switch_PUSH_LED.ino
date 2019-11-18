#define ON HIGH
#define OFF LOW
const int LED_A=9, LED_B=10;
const int SW_pin=2;

int SW_State=OFF;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT); //9番LEDピン
  pinMode(10,OUTPUT);//10番LEDピン
  pinMode(2,INPUT);//2番SWピン
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  SW_State = digitalRead(SW_pin);
  if(SW_State == ON){
    Serial.println(SW_State);
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
  }
  else {
    Serial.println("0");
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
  }
  SW_State = OFF;
}
