int s1v = 4;
int s1a = 5;
int s1r = 6;

int s2v = 7;
int s2a = 8;
int s2r = 9;

int p1a = 10;
int p2a = 11;

int pb1 = 2;
int pb2 = 3;

int tiempoverde = 1000;
boolean paso1 = true;

void setup() {
  Serial.begin(9600);
  
  pinMode(s1v,OUTPUT);
  pinMode(s1a,OUTPUT);
  pinMode(s1r,OUTPUT);
  
  pinMode(s2v,OUTPUT);
  pinMode(s2a,OUTPUT);
  pinMode(s2r,OUTPUT);
  
  pinMode(p1a,OUTPUT);
  pinMode(p2a,OUTPUT);

  // Configuramos los pines de interrupciones para que
  // detecten un cambio de bajo a alto
  attachInterrupt(digitalPinToInterrupt(pb1), peaton, RISING);
  //attachInterrupt(digitalPinToInterrupt(pb2), peaton, RISING);

}

void loop() {
  tiempoverde = 1000;
   
  for (int i = 1; i <= 10; i++){
    //Tiempo 1
    digitalWrite(s1v,HIGH);
    digitalWrite(s2r,HIGH);
    Serial.print(tiempoverde);
    delay(tiempoverde);  
  }
  fin();
       
  digitalWrite(s1a,HIGH);
  digitalWrite(s2r,HIGH);
  delay(2000);
  fin();

  tiempoverde = 1000;
  for (int i = 1; i <= 10; i++){
    //Tiempo 1
    digitalWrite(s2v,HIGH);
    digitalWrite(s1r,HIGH);
    Serial.print(tiempoverde);
    delay(tiempoverde); 
    fin(); 
    
  }
  
  digitalWrite(s2a,HIGH);
  digitalWrite(s1r,HIGH);
  delay(2000);
  fin();



  
}

void fin(){
  digitalWrite(s1v,LOW); 
  digitalWrite(s1a,LOW);
  digitalWrite(s1r,LOW);
  
  digitalWrite(s2v,LOW); 
  digitalWrite(s2a,LOW);
  digitalWrite(s2r,LOW);
}

void peaton() {
    tiempoverde = 0;
    Serial.println("Pasooo");

    
}
