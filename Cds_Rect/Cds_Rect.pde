import processing.serial.*;
Serial Aport;
PrintWriter Dfile;
int Cval = 0;

void setup(){
  size(300, 100);
  background(192);
  fill(0);
  String ArduinoPort = Serial.list()[0];
  Aport = new Serial(this, ArduinoPort, 9600);
  text(0, 20, 22);
  text(100, 110, 22);
  text(200, 210, 22);
  Dfile = createWriter("Cds.dat");
}

void draw(){
  if(Aport.available() > 0){
    Cval = Aport.read();
  }
  fill(255);
  rect(25,25,255,50);
  fill(0);
  rect(25,25,Cval,50);
  if((frameCount % 60) == 0){
    Dfile.println(frameCount/60+" "+Cval);
  }
}

void KeyPressed(){
  Dfile.flush();
  Dfile.close();
}
