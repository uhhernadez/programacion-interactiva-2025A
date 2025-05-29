import oscP5.*;
import netP5.*;
import controlP5.*;

ControlP5 cp5;
OscP5 oscP5;
NetAddress myAddress;
String myMsg = "Mensaje actual";

void setup () {
  size (512, 512);
  cp5 = new ControlP5(this);
  oscP5 = new OscP5(this, 10000); // 10000 es el número de puerto
  myAddress = new NetAddress ("127.0.0.1",10002);
  
  cp5.addSlider("sliderEvent")
     .setPosition(10,10)
     .setSize(20, 50)
     .setRange(0,1);
}

void draw () {
  // Por llenar
  background(0);
  textSize(40);
  text(myMsg, 0, 216);
}

void sliderEvent (float val) {
  OscMessage m = new OscMessage("/volume");
  m.add(val);
  oscP5.send(m, myAddress);
}

void keyPressed () {
  if (key == 'c' || key == 'C') {
    OscMessage m = new OscMessage("/tecla/c");
    println("Se presiono la tecla c");
    m.add("Se presiono la tecla C");
    oscP5.send(m, myAddress);
  }
  if (key == 'v' || key == 'V') {
    OscMessage m = new OscMessage("/tecla/v");
    println("Se presiono la tecla v");
    m.add(millis());
    oscP5.send(m, myAddress);
  }
  if (key == 'b' || key == 'B') {
    OscMessage m = new OscMessage("/tecla/b");
    println("Se presiono la tecla b");
    float num = random(0, 10000) / 10; 
    m.add(num);
    oscP5.send(m, myAddress);
  }
}

void oscEvent (OscMessage msg) {
  println("Llego un mensaje");
  myMsg = "Llego un mensaje " + str(millis()); 
  msg.print();
}
