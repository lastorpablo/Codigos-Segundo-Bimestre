/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica NO.1
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 20 de Junio

*/
#include <Adafruit_NeoPixel.h>
 
#define ON(pin)     digitalWrite(pin, HIGH);
#define OFF(pin)    digitalWrite(pin, LOW);
#define in_A 6
#define in_B 7
#define in_C A2
#define in_D A1
#define in_E A0
#define in_F 4
#define in_G 5
#define Cantidad_Leds 1
#define pin_Led 9
#define DELAYVAL 500
 
 
char outputs[] = {in_A,in_B,in_C,in_D,in_E,in_F,in_G};
 
//Variables para Sensor Ultrasonico

int Triger = 2;
int Echo = 3;
long Sensor;
long Distancia;
int person = 0;
 
//constructor para LED NeoPixel

Adafruit_NeoPixel pixels(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);
 
 
void setup()

{
  Serial.begin(9600);
  pixels.begin();
  pinMode(Triger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Triger, LOW);
  for(int a = 0; a < 7; a++)
  {
    pinMode(outputs[a], OUTPUT);
  }

  ON(in_A);
  ON(in_B);
  ON(in_C);
  ON(in_D);
  ON(in_E);  
  ON(in_F);
  OFF(in_G);
}
 
void loop()

{
  medicion();
  lectura();
}
 
void lectura()

{
  if(Distancia>=6 && Distancia<=10)
  {
    Serial.println("Alguien a entrado");
    delay(300);
    person++;
    
    switch(person)
    {
      case(1):
      {
        OFF(in_A);
        ON(in_B);
        ON(in_C);
        OFF(in_D);
        OFF(in_E);
        OFF(in_F);
        OFF(in_G);
      break;
      }
      case(2):
      {
        ON(in_A);
        ON(in_B);
        OFF(in_C);
        ON(in_D);
        ON(in_E);
        OFF(in_F);
        ON(in_G);
      break;
      }
      case(3):
      {
        ON(in_A);
        ON(in_B);
        ON(in_C);
        ON(in_D);
        OFF(in_E);
        OFF(in_F);
        ON(in_G);
      break;
      }
      case(4):
      {
        OFF(in_A);
        ON(in_B);
        ON(in_C);
        OFF(in_D);
        OFF(in_E);
        ON(in_F);
        ON(in_G);
      break;
      }
      case(5):
      {
        ON(in_A);
        OFF(in_B);
        ON(in_C);
        ON(in_D);
        OFF(in_E);
        ON(in_F);
        ON(in_G);
      break;
      }
      case(6):
      {
        OFF(in_A);
        OFF(in_B);
        ON(in_C);
        ON(in_D);
        ON(in_E);
        ON(in_F);
        ON(in_G);
      break;
      }
      case(7):
      {
        ON(in_A);
        ON(in_B);
        ON(in_C);
        OFF(in_D);
        OFF(in_E);
        OFF(in_F);
        OFF(in_G);
      break;
      };
      case(8):
      {
        ON(in_A);
        ON(in_B);
        ON(in_C);
        ON(in_D);
        ON(in_E);
        ON(in_F);
        ON(in_G);
      break;
      }
      case(9):
      {
        ON(in_A);
        ON(in_B);
        ON(in_C);
        OFF(in_D);
        OFF(in_E);
        ON(in_F);
        ON(in_G);
        delay(1000);
        OFF(in_A);
        OFF(in_B);
        OFF(in_C);
        OFF(in_D);
        OFF(in_E);
        OFF(in_F);
        ON(in_G);
      break;
      }
    }
  }

  if(person >= 0 && person < 9)
  { 
    pixels.setPixelColor(0,0,255,0);
    pixels.show();
  }
  if(person >= 9)
  {
    pixels.setPixelColor(0,255,0,0);
    pixels.show();
  }
}
 
 
long medicion()
{
  digitalWrite(Triger, HIGH);
  delay(100);
  digitalWrite(Triger, LOW);
  Sensor = pulseIn(Echo, HIGH);
  Distancia = Sensor/59;
}

 
