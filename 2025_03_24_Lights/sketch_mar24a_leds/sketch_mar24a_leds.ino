const int p0 = 8, p1 = 9, 
		  p2 = 10, p3 = 11;
void setup()
{
  Serial.begin(9600);      
  pinMode(p0, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
}

void loop()
{
  int val = analogRead(A0);
  int delayTime = map(val, 0, 1023, 50, 500);
  Serial.println(val);
  p0On();
  delay(delayTime);
  p1On();
  delay(delayTime);
  p2On();
  delay(delayTime);
  p3On();
  delay(delayTime);
  p2On();
  delay(delayTime);
  p1On();
  delay(delayTime);
  
}

void p0On () {
  digitalWrite(p0, HIGH);
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
}

void p1On () {
  digitalWrite(p0, LOW);
  digitalWrite(p1, HIGH);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
}

void p2On () {
  digitalWrite(p0, LOW);
  digitalWrite(p1, LOW);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, LOW);
}

void p3On () {
  digitalWrite(p0, LOW);
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, HIGH);
}