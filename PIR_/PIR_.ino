int lectura; //leer si hay prescencia del sensor

long tiempo; //tiempo de espera al sensor

boolean encenderPatio = false; //variable para cuando la luz se encienda

//Variables para activar el relevador (opcional)
#define RELAY_ON 0    
#define RELAY_OFF 1

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT); //Sensor
  
  pinMode(8,OUTPUT); //LED
  pinMode(9,OUTPUT); //RELE
  tiempo = 0;
  Serial.println("Inicio");
}

void loop() {
  //Leer el valor del sensor
  lectura = digitalRead(7);

  //Si detecta prescencia...
  if ( lectura == 1){
    Serial.println("Persona detectada");
    //Variable temporal para evitar delay()
    //Millis son los milisegundos de la ejecucion
    tiempo = millis();
    //Se declara encendido el patio
    encenderPatio = true;

    //Si el sensor no detecta prescencia...
  }else if(!encenderPatio){
    //Apaga LED y Rele
    digitalWrite(8,LOW);
    digitalWrite(9,RELAY_OFF);
    
  }

  //Si encenderPatio es verdadero...
  if (encenderPatio){
    //Variables para monitoreo
    Serial.print("Patio encendido. Tiempo: ");
    Serial.print(millis());
    Serial.print("  Termina en: ");
    Serial.println(tiempo + 30000);

    //Se enciende el LED y RELE
    digitalWrite(9,RELAY_ON);
    digitalWrite(8,HIGH);
    encenderPatio = true;

    //Cuando hayan pasado 10 seg (10000ms) se apaga la alerta
    if (millis() > tiempo + 10000){
      Serial.println("Patio apagado por tiempo");
      encenderPatio = false;
    }
  }
  
  }
