float vLM;
float temp;
float vLED;

int pinLED = 3;

void setup() {
  
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  
}

void loop() {
  vLM = analogRead(A0);

  temp = vLM * 5 * 100 / 1023;
  Serial.print("La temperatura es: ");
  Serial.println(temp);

  vLED = (temp * 255) / 50;
  Serial.print("El voltaje  es: ");
  Serial.println(vLED);

 analogWrite(pinLED,vLED);
 delay(5);

}
