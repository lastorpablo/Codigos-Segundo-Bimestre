/* 
    Fundación Kinal
    Centro educativo Técncico Laboral Kinal
    Quinto Perito
    Quinto Electrónica 
    Codigo Técnico: EB5AM
    Curso: Taller de Electrónica Digital y reparación de computadoras
    Proyecto: Interfaces de visualización e Interacción
    Dev: Kevin Owen Roger Pablo Lastor
    Fecha: 09 de mayo de 2024
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
char name [5]={'K', 'E', 'V', 'I', 'N'};
int posicion [] = {0, 1, 2, 3, 4, 5};
int carnet [] = {2, 0, 2, 3, 1, 1, 3};
int po_car [] = {0, 1, 2, 3, 4, 5, 6};

void setup()
{
  lcd_1.begin(16, 2);
}

void loop()
{
  delay(500);
  for(int i = 0; i < 5; i++){
   lcd_1.setCursor(posicion[i], 0);
   lcd_1.print(name[i]);
    delay(300);
   }
  for(int i = 0; i<7; i++){
     lcd_1.setCursor(po_car[i], 1);
     lcd_1.print(carnet[i]);
     delay(300);
   }
  //lcd_1.clear();
  delay(500);
}
