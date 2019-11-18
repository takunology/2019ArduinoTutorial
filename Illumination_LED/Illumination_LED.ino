const int LED_R=9;
const int LED_G=10;
const int LED_B=11;
int Dtime = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}
//RGBの順番でイルミネーション
void loop() {
  // put your main code here, to run repeatedly:
  int i;
    for(i=0; i<255; i++){
    analogWrite(LED_R, i);
    delay(Dtime);
  }
  for(i=255; i>0; i--){
    analogWrite(LED_R, i);
    delay(Dtime);
  }
  for(i=0; i<255; i++){
    analogWrite(LED_G, i);
    delay(Dtime);
  }
  for(i=255; i>0; i--){
    analogWrite(LED_G, i);
    delay(Dtime);
  }
  for(i=0; i<255; i++){
    analogWrite(LED_B, i);
    delay(Dtime);
  }
  for(i=255; i>0; i--){
    analogWrite(LED_B, i);
    delay(Dtime);
  }
}
