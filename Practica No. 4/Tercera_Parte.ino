/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica NO.4
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 25 de abril
*/

int pinsec[6] = {2, 3, 4, 5, 6};
int time = 0;
int letra_C [4] = {13, 10, 9, 8};
int letra_U [5] = {12, 11, 10, 9, 8};
int letra_A [6] = {13, 12, 11, 9, 8, 7};
int letra_T [3] = {13, 12, 11};
int letra_R [3] = {13, 9, 8};
int letra_O [6] = {13, 12, 11, 10, 9, 8};

void setup(){
  
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(pinsec[i], OUTPUT);
  }
  for (int c = 0; c < 4; c++) {
    pinMode(letra_C[c], OUTPUT);
  }
  for (int u = 0; u < 5; u++) {
    pinMode(letra_U[u], OUTPUT);
  }
  for (int a = 0; a < 6; a++) {
    pinMode(letra_A[a], OUTPUT);
  }
  for (int t = 0; t < 3; t++) {
    pinMode(letra_T[t], OUTPUT);
  }
  for (int r = 0; r < 3; r++) {
    pinMode(letra_R[r], OUTPUT);
  }
  for (int o = 0; o < 6; o++) {
    pinMode(letra_O[o], OUTPUT);
  }
}
void loop()
{
  if(digitalRead(A0)==HIGH && !digitalRead(A2)){
    Serial.println("Practica No.4 - Kevin Pablo");
    delay(1500);
  }
  
  if(digitalRead(A1)==HIGH && !digitalRead(A3)){
    time = 500; 
    for(int a = 0; a < 3; a++){
    Serial.println("Secuencia - Velocidad 1");
    for (int i = 0; i<5 ; i++){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    }
    for (int i = 5; i>=0 ; i--){
    digitalWrite(pinsec[i], HIGH);
    delay(time);
    digitalWrite(pinsec[i], LOW);
    }
  }
    for(int i = 0; i < 3; i++){
      delay(350);
      for(int a = 0; a < 5; a++){
        digitalWrite(pinsec[a], HIGH);
    }
    delay(500);
      for(int a = 5; a>=0; a--){
        digitalWrite(pinsec[a], LOW);
      }
    }
  }
  
  if(digitalRead(A2)==HIGH && !digitalRead(A0)){
    delay(350);
    for (int c = 0; c<4 ; c++){
      digitalWrite(letra_C[c], HIGH);}
    delay(2000);
    for (int c = 4; c>=0 ; c--){
      digitalWrite(letra_C[c], LOW);}
    for (int u = 0; u<5 ; u++){
      digitalWrite(letra_U[u], HIGH);}
    delay(2000);
    for (int u = 5; u>=0 ; u--){
      digitalWrite(letra_U[u], LOW);}
    for (int a = 0; a<6 ; a++){
      digitalWrite(letra_A[a], HIGH);}
    delay(2000);
    for (int a = 6; a>=0 ; a--){
      digitalWrite(letra_A[a], LOW);}
    for (int t = 0; t<3 ; t++){
      digitalWrite(letra_T[t], HIGH);}
    delay(2000);
    for (int t = 3; t>=0 ; t--){
      digitalWrite(letra_T[t], LOW);}
    for (int r = 0; r<3 ; r++){
      digitalWrite(letra_R[r], HIGH);}
    delay(2000);
    for (int r = 3; r>=0 ; r--){
      digitalWrite(letra_R[r], LOW);}
    for (int o = 0; o<6 ; o++){
      digitalWrite(letra_O[o], HIGH);}
    delay(2000);
    for (int o = 6; o>=0 ; o--){
      digitalWrite(letra_O[o], LOW);}
    }
  
  if(digitalRead(A0)==HIGH && digitalRead(A2)==HIGH || digitalRead(A1)==HIGH && digitalRead(A3)){
    Serial.println("Gracias por su atencion");
    delay(1500);
  }
}
