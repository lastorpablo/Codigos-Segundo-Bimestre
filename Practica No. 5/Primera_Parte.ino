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

float kilogramos = 24;
float amperes = 15;
float res_peso;
float res_amp;

int time1 = 1000;
int time2 = 100;
//a=2, b=3, c=4, d=5, e=6, f=7, g=8
int secuencia [7] = {2, 3, 4, 5, 6, 7 , 8};
int num1 [2] = {3, 4};
int num3 [5] = {2, 3, 4, 5, 8};
int num5 [5] = {2, 4, 5, 7, 8};
int num7 [3] = {2, 3, 4};
int num9 [5] = {2, 3, 4, 7, 8};

void setup()
{
  Serial.begin(9600);
  Serial.println("PESO");
  res_peso = kg_lb(kilogramos);
  Serial.print(kilogramos);
  Serial.print(" kilogramos es igual a ");
  Serial.print(res_peso);
  Serial.println( " libras");
  
  Serial.println("CORRIENTE");
  res_amp = corriente(amperes);
  Serial.print(amperes);
  Serial.print(" amperio(s) son igual a ");
  Serial.print(res_amp);
  Serial.println( " Microamperio(s)");
     
}

void loop()
{
  secuencial();
}

float kg_lb(float k){
  float resultadoP;
  resultadoP= k*2.20462;
  return resultadoP;
}

float corriente(float A){
  float resultadoA;
  resultadoA = A*1000000;
  return resultadoA;
}

void configuracion(){
  for(int i = 0; i < 7; i++){
    pinMode(secuencia[i], OUTPUT);
  }
}

int secuencial(){  
  for(int i = 0; i<2; i++){
    digitalWrite(num1[i], HIGH);
  }
  delay(time1);
  for(int i = 2; i>=0; i--){
    digitalWrite(num1[i], LOW);
  }
  delay(time2);
  
  for(int i = 0; i<5; i++){
    digitalWrite(num3[i], HIGH);
  }
  delay(time1);
  for(int i = 5; i>=0; i--){
    digitalWrite(num3[i], LOW);
  }
  delay(time2);
  
  for(int i = 0; i<5; i++){
    digitalWrite(num5[i], HIGH);
  }
  delay(time1);
  for(int i = 5; i>=0; i--){
    digitalWrite(num5[i], LOW);
  }
  delay(time2);
  
  for(int i = 0; i<3; i++){
    digitalWrite(num7[i], HIGH);
  }
  delay(time1);
  for(int i = 3; i>=0; i--){
    digitalWrite(num7[i], LOW);
  }
  delay(time2);
  
  for(int i = 0; i<5; i++){
    digitalWrite(num9[i], HIGH);
  }
  delay(time1);
  for(int i = 5; i>=0; i--){
    digitalWrite(num9[i], LOW);
  }
  delay(time2);
}
