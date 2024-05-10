/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Relevadores y Visualizadores
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 02 de mayo del 2024
*/

int time1 = 1000;
int time3 = 500;
//a=2, b=3, c=4, d=5, e=6, f=7, g=8
int salidas [9] = {2, 3, 4, 5, 6, 7 , 8, 9, 10};
int num0 [6] = {2, 3, 4, 5, 6, 7};
int num1 [2] = {3, 4};
int num2 [5] = {2, 3, 5, 6, 8};
int num3 [5] = {2, 3, 4, 5, 8};
int num4 [4] = {3, 4, 7, 8};
int num5 [5] = {2, 4, 5, 7, 8};
int num6 [6] = {2, 4, 5, 6, 7, 8};
int num7 [3] = {2, 3, 4};
int num8 [7] = {2, 3, 4, 5, 6, 7, 8};
int num9 [5] = {2, 3, 4, 7, 8};

void setup()
{
  Serial.begin(9600);
  digitalWrite(10, HIGH);
  configuracion();
}

void loop()
{
  varnum9();
  delay(time3);
  varnum8();
  delay(time3);
  varnum7();
  delay(time3);
  varnum6();
  delay(time3);
  varnum5();
  delay(time3);
  varnum4();
  delay(time3);
  varnum3();
  delay(time3);
  varnum2();
  delay(time3);
  varnum1();
  delay(time3);
  varnum0();
  buzzer();
}


void configuracion(){
  for(int i = 0; i < 9; i++){
    pinMode(salidas[i], OUTPUT);
  }
}

int varnum0(){
  for(int i = 0; i<6; i++){
    digitalWrite(num0[i], HIGH);
  }
  delay(time1);
  for(int i = 6; i>=0; i--){
    digitalWrite(num0[i], LOW);
  }
}

int varnum1(){  
  for(int i = 0; i<2; i++){
    digitalWrite(num1[i], HIGH);
  }
  delay(time1);
  for(int i = 2; i>=0; i--){
    digitalWrite(num1[i], LOW);
  }
}
  
int varnum2(){
  for(int i = 0; i<5; i++){
    digitalWrite(num2[i], HIGH);
  }
  delay(time1);
  for(int i = 5; i>=0; i--){
    digitalWrite(num2[i], LOW);
  }
}
 
int varnum3(){
  for(int i = 0; i<5; i++){
    digitalWrite(num3[i], HIGH);
  }
  delay(time1);
  for(int i = 5; i>=0; i--){
    digitalWrite(num3[i], LOW);
  }
}
int varnum4(){
  for(int i = 0; i<4; i++){
    digitalWrite(num4[i], HIGH);
  }
  delay(time1);
  for(int i = 4; i>=0; i--){
    digitalWrite(num4[i], LOW);
  }
}

int varnum5(){
  for(int i = 0; i<5; i++){
    digitalWrite(num5[i], HIGH);
  }
  delay(time1);
  for(int i = 5; i>=0; i--){
    digitalWrite(num5[i], LOW);
  }
}

int varnum6(){
  for(int i = 0; i<6; i++){
    digitalWrite(num6[i], HIGH);
  }
  delay(time1);
  for(int i = 6; i>=0; i--){
    digitalWrite(num6[i], LOW);
  }
}

int varnum7(){
  for(int i = 0; i<3; i++){
    digitalWrite(num7[i], HIGH);
  }
  delay(time1);
  for(int i = 3; i>=0; i--){
    digitalWrite(num7[i], LOW);
  }
}

int varnum8(){
  for(int i = 0; i<7; i++){
    digitalWrite(num8[i], HIGH);
  }
  delay(time1);
  for(int i = 7; i>=0; i--){
    digitalWrite(num8[i], LOW);
  }
}

int varnum9(){
  for(int i = 0; i<5; i++){
    digitalWrite(num9[i], HIGH);
  }
  delay(time1);
  for(int i = 5; i>=0; i--){
    digitalWrite(num9[i], LOW);
  }
}

int buzzer(){
  digitalWrite(10, LOW);
  delay(50);
  tone(9, 400);
  delay(500);
  noTone(9);
  delay(2000);
}
