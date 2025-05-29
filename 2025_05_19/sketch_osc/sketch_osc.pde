import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress myAddress;
String myMsg = "Mensaje actual";

void setup () {
  size (512, 512);
  oscP5 = new OscP5(this, 10000); // 10000 es el número de puerto
  myAddress = new NetAddress ("127.0.0.1",10002);
}

void draw () {
  // Por llenar
  background(0);
  textSize(40);
  text(myMsg, 0, 216);
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
}

void oscEvent (OscMessage msg) {
  println("Llego un mensaje");
  myMsg = "Llego un mensaje " + str(millis()); 
  msg.print();
}
