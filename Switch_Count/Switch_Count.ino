#define ON HIGH
#define OFF LOW
const int LED_A=9, LED_B=10;
const int SW_pin=2;

int SW_State=OFF;
int SW_Count = 1;
int Count = 0;

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
    delay(50);
    Count++;
    Serial.print("スイッチが押されたよ. 押された回数:");
    Serial.println(SW_Count);
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
  }
  else {
    if(Count > 1){ //チャタリングで一気に+50くらいになる対策
      Count = 1;
    }
    SW_Count += Count;
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
    Count = 0; //初期化
  }
  SW_State = OFF;
}
