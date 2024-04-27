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
    time = 50;
    Serial.println("Secuencia - Velocidad 1");
    for (int i = 0; i<9 ; i++){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    delay(time);
    }
    for (int i = 9; i>=0 ; i--){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    delay(time);
    }
  }
  if(digitalRead(3)==HIGH){
    time = 1000;
    Serial.println("Secuencia - Velocidad 2");
    for (int i = 0; i<9 ; i++){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    delay(time);
    }
    for (int i = 9; i>=0 ; i--){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    delay(time);
    }
  }
}  
