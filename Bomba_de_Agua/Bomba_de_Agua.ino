int pinLED = 3;
boolean bomba;
void setup() {
  Serial.begin(9600);
  pinMode(pinLED,OUTPUT);

}

void loop() {
  int sensorDer = analogRead(A0);
  int sensorIzq = analogRead(A5);

  Serial.print("Sensor izquierda: ");
  Serial.print(sensorIzq);

  Serial.print("\tSensor derecha: ");
  Serial.println(sensorDer);
  
  

  delay(1000);
  
  if (true){
    
  }

}
