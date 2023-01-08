int buttons[6];

int notes[] = {262,294,330,349};

void setup() {
  buttons[0] = 2;
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int keyVal = analogRead(A0);
Serial.println(keyVal);
if(keyVal == 1023){
  noTone(8);
}else if(keyVal >= 1011 && keyVal <= 1022){
  tone(8,notes[0]);
}else if(keyVal >= 510 && keyVal <= 1010){
  tone(8,notes[1]);
}else if(keyVal >= 20 && keyVal <= 509){
  tone(8,notes[2]);
}else if(keyVal >= 0 && keyVal <= 10){
  tone(8,notes[3]);
}else{
  noTone(8);
}
}
