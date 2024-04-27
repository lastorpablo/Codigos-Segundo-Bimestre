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

int i = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.println("Contador 0 - 99");
  Serial.println("izquierda - derecha +");
  Serial.println(i);
}

void loop()
{
  if(digitalRead(2)==HIGH){
    delay(350);
    i++;
    if(i >= 100){
      i = 0;
    }
    Serial.println(i);
  }
  
  else if(digitalRead(3)==HIGH){
    delay(350);
    i--;
    if(i < 0){
      i = 99;
    }
    Serial.println(i);  
  }
}
