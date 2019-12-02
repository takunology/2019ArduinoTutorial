const int pinA = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vol = analogRead(pinA);
  Serial.println(vol);
  delay(50);
}
