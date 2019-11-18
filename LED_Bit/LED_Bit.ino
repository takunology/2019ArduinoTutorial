#define TIME 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Light(9);
  Light(10);
  MultiLight(9,10);
  delay(TIME);
}

void Light(int pin){
  digitalWrite(pin,HIGH);
  delay(TIME);
  digitalWrite(pin,LOW);
}

void MultiLight(int pinA, int pinB){
  digitalWrite(pinA,HIGH);
  digitalWrite(pinB,HIGH);
  delay(TIME);
  digitalWrite(pinA,LOW);
  digitalWrite(pinB,LOW);
}
