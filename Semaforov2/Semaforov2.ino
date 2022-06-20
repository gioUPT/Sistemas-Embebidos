int s1v = 4;
int s1a = 5;
int s1r = 6;

int p1a = 7;
int p2a = 8;

int spv = 9;
int spr = 10;

int pb1 = 2;
int pb2 = 3;

boolean tiempoverde = true;

int boton;

void setup() {
  Serial.begin(9600);
  
  pinMode(s1v,OUTPUT);
  pinMode(s1a,OUTPUT);
  pinMode(s1r,OUTPUT);
  
  pinMode(p1a,OUTPUT);
  pinMode(p2a,OUTPUT);

  pinMode(spv,OUTPUT);
  pinMode(spr,OUTPUT);

  // Configuramos los pines de interrupciones para que
  // detecten un cambio de bajo a alto
  attachInterrupt(digitalPinToInterrupt(pb1), peatonUno, RISING);
  attachInterrupt(digitalPinToInterrupt(pb2), peatonDos, RISING);


}

void loop() {

  while(tiempoverde){
    //Siempre Verde
    digitalWrite(s1v,HIGH);
    digitalWrite(spr,HIGH);
    Serial.print(tiempoverde);
    delay(tiempoverde);  
  }
  fin();
  digitalWrite(spr,HIGH);
  digitalWrite(boton,HIGH);
  intermitente(s1a);
  rojo();
  tiempoverde = true;
  
 
}

void peatonUno() {
    tiempoverde = false;
    boton = 7;
}
void peatonDos() {
    tiempoverde = false;
    boton = 8;
}


void intermitente(int led){
  for (int i = 0; i < 4; i++){
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW);
    delay(300);
  }
  fin();
}

void rojo(){
  digitalWrite(s1r,HIGH);
  digitalWrite(spv,HIGH);
  delay(7000);
  intermitente(spv);
  fin();
}


void fin(){
  digitalWrite(s1v,LOW); 
  digitalWrite(s1a,LOW);
  digitalWrite(s1r,LOW);
  
  digitalWrite(p1a,LOW);
  digitalWrite(p2a,LOW);
   
  digitalWrite(spv,LOW);
  digitalWrite(spr,LOW);

}
