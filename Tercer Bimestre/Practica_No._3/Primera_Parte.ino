/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Uso de Matriz LED
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 18 de julio.
*/

#include <LedControl.h>

#define DIN_MATRIZ 2
#define CS_MATRIZ 3
#define CLK_MATRIZ 4
#define Canal_ADC A6

LedControl PacMan = LedControl(DIN_MATRIZ,CLK_MATRIZ,CS_MATRIZ,1);

unsigned int valor_ADC;
unsigned int Control_velocidad;

byte PacMan_Open[8]={
  B00111100,
  B01000010,
  B10010100,
  B10001000,
  B10001000,
  B10000100,
  B01000010,
  B00111100
  };

byte PacMan_Eat[8]={
  B00111100,
  B01000010,
  B10010001,
  B10000001,
  B10001111,
  B10000001,
  B01000010,
  B00111100
  };

void setup() {
  Serial.begin(9600);
  pinMode(Canal_ADC, INPUT);
  PacMan.shutdown(0, false);
  PacMan.setIntensity(0,15);
  PacMan.clearDisplay(0);
}

void loop() {
  valor_ADC = analogRead(Canal_ADC);
  Control_velocidad = map(valor_ADC,0,1023,100,5000);
  
  Pacman_Uno();    
  delay(Control_velocidad); 
  Pacman_Dos();
  delay(Control_velocidad);  
}


void Pacman_Uno(){
  for(int i = 0; i < 8; i++){
    PacMan.setRow(0,i,PacMan_Open[i]);
    }
  }

void Pacman_Dos(){
  for(int i = 0; i < 8; i++){
    PacMan.setRow(0,i,PacMan_Eat[i]);
    }
  }
