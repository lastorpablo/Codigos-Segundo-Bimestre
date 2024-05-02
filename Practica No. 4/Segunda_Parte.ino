/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica No.4
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 25 de abril
*/

int pinsec[] = {4, 5, 6, 7, 8, 9, 10, 11, 12}; 
int time = 0;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT); 
  for (int i = 0; i < 9; i++) {
    pinMode(pinsec[i], OUTPUT);
  }
}
void loop() {
  if(digitalRead(2)==HIGH){
    time = 500; 
    for(int a = 0; a < 3; a++){
    Serial.println("Secuencia - Velocidad 1");
    for (int i = 0; i<9 ; i++){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    }
    for (int i = 9; i>=0 ; i--){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    }
  }
    for(int i = 0; i < 3; i++){
      delay(350);
      for(int a = 0; a < 9; a++){
        digitalWrite(pinsec[a], HIGH);
    }
    delay(500);
      for(int a = 9; a>=0; a--){
        digitalWrite(pinsec[a], LOW);
      }
    }
  }
    
  if(digitalRead(3)==HIGH){
    time = 1000; //la velocidad es la de la guia, pero se ve algo lento
    for(int a = 0; a < 3; a++){
    Serial.println("Secuencia - Velocidad 2");
    for (int i = 0; i<9 ; i++){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    }
    for (int i = 9; i>=0 ; i--){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    }
   }
    for(int i = 0; i < 3; i++){
      delay(350);
      for(int a = 0; a < 9; a++){
        digitalWrite(pinsec[a], HIGH);
    }
    delay(500);
      for(int a = 9; a>=0; a--){
        digitalWrite(pinsec[a], LOW);
      }
    }
  }
}  
