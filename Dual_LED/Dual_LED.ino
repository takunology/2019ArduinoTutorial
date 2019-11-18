#define TIME 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Light(9);
  delay(TIME);
  Light(10);
}

void Light(int pin){
  digitalWrite(pin,HIGH);
  delay(TIME);
  digitalWrite(pin,LOW);
}
