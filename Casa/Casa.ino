//PIR
int PIR = A0; 
int ledPIR = 13;
long tiempoPIR;
boolean encenderPatio = false;

//LM UNO
int LM1 = A1;
int ledLM1 = 12;

//LM DOS
int LM2 = A2;
int ledLM2 = 11;

//LDR
int LDR1 = A3;
int ledLDR1 = 10;



void setup() {
  Serial.begin(9600);
  Serial.println("Inicio");

  //PIR
  pinMode(PIR,INPUT);
  pinMode(ledPIR,OUTPUT); 
  tiempoPIR = 0;

  //LM35 DOS
  pinMode(LM1, INPUT);
  pinMode(ledLM1, OUTPUT);

  //LM35 DOS
  pinMode(LM2, INPUT);
  pinMode(ledLM2, OUTPUT);

  //LDR
  pinMode(LDR1, INPUT);
  pinMode(ledLDR1, OUTPUT);
  
}

void loop() {
  servicioPIR();
  
  servicioLM(LM1,ledLM1);
  servicioLM(LM2,ledLM2);

  servicioLDR(LDR1,ledLDR1);
  
  
}

void servicioLDR (int sensor, int led){
  int lectura = analogRead(sensor);
//  Serial.println(lectura);
  
  if ( lectura < 200 ){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW); 
  }
  
}

void servicioLM(int sensor, int led) {
  float vLM = analogRead(sensor);

  float temp = vLM * 5 * 100 / 1023;
  Serial.print("La temperatura es: ");
  Serial.println(temp);

  if (temp > 25){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  
}

void servicioPIR(){
  //Leer el valor del sensor
  int lectura = digitalRead(PIR);

  //Si detecta prescencia...
  if ( lectura == 1){
//    Serial.println("Persona detectada");
    //Variable temporal para evitar delay()
    //Millis son los milisegundos de la ejecucion
    tiempoPIR = millis();
    //Se declara encendido el patio
    encenderPatio = true;

    //Si el sensor no detecta prescencia...
  }else if(!encenderPatio){
    digitalWrite(ledPIR,LOW);
    
  }

  //Si encenderPatio es verdadero...
  if (encenderPatio){
    //Variables para monitoreo
//    Serial.print("Patio encendido. Tiempo: ");
//    Serial.print(millis());
//    Serial.print("  Termina en: ");
//    Serial.println(tiempoPIR + 30000);

    //Se enciende el LED y RELE
    digitalWrite(ledPIR,HIGH);
    encenderPatio = true;

    //Cuando hayan pasado 10 seg (10000ms) se apaga la alerta
    if (millis() > tiempoPIR + 10000){
//      Serial.println("Patio apagado por tiempo");
      encenderPatio = false;
    }
  }
}
