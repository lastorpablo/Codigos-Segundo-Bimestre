/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Uso de pantalla OLED
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 18 de julio.
*/

#include <Wire.h>          
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>   


#define widht_oled    128      
#define height_oled   64        
#define Canal_ADC A6

Adafruit_SSD1306 waza(widht_oled,height_oled,&Wire, -1);

unsigned int valor_ADC;

void setup() {
  Serial.begin(9600);
  pinMode(Canal_ADC, INPUT);
  waza.begin();

 if(!waza.begin(SSD1306_SWITCHCAPVCC, 0x3C))
 {
  Serial.println("No puedo comunicarme con la pantalla oled");
  Serial.println("Favor de revisar conexiones o alimentacion");
  while(1);   //Ciclo infinito
 }
  
  waza.clearDisplay();
  waza.setTextSize(2);
  waza.setTextColor(SSD1306_WHITE);
  waza.setCursor(0,0);
  waza.println("Valor del ADC");
  waza.display();
}

void loop() {
  waza.setTextSize(1);
  waza.setTextColor(SSD1306_WHITE);
  waza.setCursor(0,0);
  waza.println("Valor del ADC");
  waza.display();
  valor_ADC = analogRead(Canal_ADC);
  waza.setTextSize(2);
  waza.setTextColor(SSD1306_WHITE);
  waza.setCursor(0,12);
  waza.println(valor_ADC);
  waza.display();
  delay(100);
  waza.clearDisplay();
}
