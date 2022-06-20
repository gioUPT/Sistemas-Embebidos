int pcR;

int rojo = 11;
int verde = 10;
int azul = 9;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(rojo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);
  
}

void loop() {
  pcR = analogRead(A0);

  if(pcR <= 100){
    Serial.print("Noche: El valor de ");
    Serial.println(pcR);
    
      digitalWrite(azul,1);
      digitalWrite(rojo,0);
      digitalWrite(verde,0);
    }
    
    else if (pcR > 100 && pcR <= 500 ){
      Serial.print("Luz tenue: El valor de");
      Serial.println(pcR);

      digitalWrite(azul,0);
      digitalWrite(rojo,1);
      digitalWrite(verde,0);
      }
      
    else if(pcR > 500 && pcR <= 900 ){
      Serial.print("Luz: El valor de ");
      Serial.println(pcR);  

      digitalWrite(azul,0);
      digitalWrite(rojo,0);
      digitalWrite(verde,1);
    }
    
    else if(pcR > 900){
      Serial.print("Luz de dia: El valor de ");
      Serial.println(pcR);

      analogWrite(azul,150);
      analogWrite(rojo,100);
      analogWrite(verde,0);
      
      }

  delay(1000);

}
