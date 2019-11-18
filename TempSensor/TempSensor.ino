#define FromLow 300
#define FromHigh 1600
#define ToLow -30
#define ToHigh 100

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analog, temp, Voltage;
  analog = analogRead(0);
  Voltage = map(analog, 0, 1023, 0, 5000);
  temp = map(Voltage, FromLow, FromHigh, ToLow, ToHigh);
  Serial.println(temp);
  delay(100);
}
