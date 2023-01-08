const int sensorPin = A0;
const float baseLineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(int pinNumber = 2; pinNumber<5; pinNumber++){
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber , LOW);
}
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorVal = analogRead(sensorPin);
Serial.print("Sensor Value: ");
Serial.print(sensorVal);
float voltage = (sensorVal/1024.0) * 5.0;
Serial.print(", Volts: ");
Serial.print(voltage);
Serial.print(", Degrees C: ");
//converts voltage to temp
float temperature = (voltage - .5) * 100;
Serial.print(temperature);
//convert to degrees fahrenhight
Serial.print(", Degrees F: ");
float tempFahr = (temperature * 1.8) + 32;
Serial.println(tempFahr);
//control lights based on temp
if(temperature < baseLineTemp+5){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}else if(temperature >= baseLineTemp+5 && temperature < baseLineTemp+10){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
}else if(temperature >= baseLineTemp+20){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
}
delay(10);
}
