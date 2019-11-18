const int LED_pin=11;
int Dtime=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i=0; i<255; i++){
    analogWrite(LED_pin, i);
    delay(Dtime);
  }
  for(i=255; i>0; i--){
    analogWrite(LED_pin, i);
    delay(Dtime);
  }
}
