int switchState = 0;


void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState == LOW){
    digitalWrite(3, HIGH); //GREEN LED
    digitalWrite(4, LOW); //RED LED
    digitalWrite(5, LOW); //RED LED
  }
  else{//the button is pressed
    digitalWrite(3, LOW); //GREEN LED
    digitalWrite(4, LOW); //RED LED
    digitalWrite(5, HIGH); //RED LED
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(250);
  }
  
}
