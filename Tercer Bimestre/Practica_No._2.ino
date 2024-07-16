/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Uso del acelerometro ADXL345
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 12 de julio.
*/

#include <Wire.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include <SparkFun_ADXL345.h>


#define LED_1 12
#define LED_2 A2
#define LED_3 A3
#define LED_4 9
#define LED_5 8
#define LED_6 2
#define LED_7 3
#define LED_8 4
#define LED_9 5
#define LED_10 6


ADXL345 acelerometro_ADXL345 = ADXL345();
SoftwareSerial DFPlayerSerial(10, 11); 
DFRobotDFPlayerMini MP3;

//D12, A2, A3, D9, D8, D2, D3, D4, D5, D6

int x, y, z;
float SloadR, loadx, loady, loadz, valorSLR;
int Medidor;
unsigned long lastTime = 0;
unsigned long currentTime = 0;

char LEDS[] = {LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_10};

void setup() {
  Serial.begin(9600);    
  Serial.println("Uso del acelerometro ADXL345");
  acelerometro_ADXL345.powerOn();
  acelerometro_ADXL345.setRangeSetting(2);

  DFPlayerSerial.begin(9600);
  MP3.begin(DFPlayerSerial);
  MP3.volume(25);    

  for(int i = 0; i < 10; i++)
  {
    pinMode(LEDS[i], OUTPUT);
  }

  for(int i = 0; i < 10; i++)
  {
    digitalWrite(LEDS[i], HIGH);
  }
}

void loop() {
  

  acelerometro_ADXL345.readAccel(&x, &y, &z);
  loadx = x * 0.04;
  loady = y * 0.04;
  loadz = z * 0.04;
  SloadR = ((loadx*loadx) + (loady*loady) + (loadz*loadz));
  valorSLR = sqrt(SloadR);
  Serial.println(valorSLR);
  
  currentTime = millis();
      
  Medidor = map(valorSLR,10.89, 25.10, 0, 10);

  if(Medidor == 1)
  {
    for(int i = 0; i < 1; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if(Medidor == 2)
  {
    for(int i = 0; i < 2; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if(Medidor == 3)
  {
    for(int i = 0; i < 3; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if(Medidor == 4)
  {
    for(int i = 0; i < 4; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if(Medidor == 5)
  {
    for(int i = 0; i < 5; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if(Medidor == 6)
  {
    for(int i = 0; i < 6; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
    MP3.play(1);
    delay(6000);
  }

  if(Medidor == 7)
  {
    for(int i = 0; i < 7; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
    MP3.play(1);
    delay(6000);
  }

  if(Medidor == 8)
  {
    for(int i = 0; i < 8; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
    MP3.play(1);
    delay(6000);
  }

  if(Medidor == 9)
  {
    for(int i = 0; i < 9; i++)
    {
      digitalWrite(LEDS[i], LOW);
     }
     MP3.play(1);
     delay(6000);
  }

  if(Medidor == 10)
  {
    for(int i = 0; i < 10; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
    MP3.play(1);
    delay(6000);
  }

  if (currentTime - lastTime >= 5000)
  {
    for(int i = 0; i < 10; i++)
    {
      digitalWrite(LEDS[i], HIGH);
    }
    MP3.pause();
    delay(100);
    lastTime = currentTime;
  }
  
  delay(200); 
}
