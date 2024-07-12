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
#include <SparkFun_ADXL345.h>

ADXL345 acelerometro_ADXL345 = ADXL345();

//D12, D11, D10, D9, D8, D2, D3, D4, D5, D6, D7

int x, y, z;
float SloadR, loadx, loady, loadz, valorSLR;
int Medidor;
unsigned long lastTime = 0;
unsigned long currentTime = 0;

int LEDS[] = {12, 11, 10, 9, 8, 2, 3, 4, 5, 6, 7};

void setup() {
  Serial.begin(9600);
  Serial.println("Uso del acelerometro ADXL345");
  acelerometro_ADXL345.powerOn();
  acelerometro_ADXL345.setRangeSetting(2);
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
  }

  if(Medidor == 7)
  {
    for(int i = 0; i < 7; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if(Medidor == 8)
  {
    for(int i = 0; i < 8; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if(Medidor == 9)
  {
    for(int i = 0; i < 9; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if(Medidor == 10)
  {
    for(int i = 0; i < 10; i++)
    {
      digitalWrite(LEDS[i], LOW);
    }
  }

  if (currentTime - lastTime >= 5000)
  {
    for(int i = 0; i < 10; i++)
    {
      digitalWrite(LEDS[i], HIGH);
    }
    lastTime = currentTime;
  }
  
  delay(200); 
}
