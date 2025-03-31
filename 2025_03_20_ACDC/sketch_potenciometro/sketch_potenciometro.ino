void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(9, OUTPUT);
}

void loop() {
  int analogVal = analogRead(A0);
  int newVal = map(analogVal, 0, 1023, 0, 255);
  analogWrite(9,newVal);
  Serial.println("-----");
  Serial.println(analogVal);
  Serial.println(newVal);
}
