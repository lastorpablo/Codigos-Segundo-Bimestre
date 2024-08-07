/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica No. 1 - Segunda Parte 
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 04 de julio.
*/

#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9
#define canalADC A7
#define sensor_hall 3 
#define sensor_IR 5

LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);

unsigned int valSpeed;
unsigned int Speed;
bool state_sensor_2;

volatile int rev = 0;
unsigned long lastTime = 0;
unsigned long currentTime = 0;
float rpm = 0;

 
int paso [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup()
{
  Serial.begin(9600);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);  
  pinMode(sensor_IR, INPUT);         
  pinMode(canalADC, INPUT);
  pinMode(sensor_hall, INPUT);

  lcd.init(); 
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Contador de rev.");
  lcd.setCursor(0,1);
  lcd.print("No. De RPM = ");
  attachInterrupt(digitalPinToInterrupt(sensor_hall), contrev, FALLING);
}
  
void loop()
{ 
  state_sensor_2 = digitalRead(sensor_IR);

  currentTime = millis();
  Serial.println(Speed);
  if (currentTime - lastTime >= 2000) {

  if(Speed == 1){
    rpm = (rev / 8.2) * 60.0;
    }

  else if(Speed == 2){
    rpm = (rev / 12.6) * 60.0;
    }
    
  else if(Speed == 3){
    rpm = (rev / 16.8) * 60.0;
    }
    
  else if(Speed == 4){
    rpm = (rev / 20.6) * 60.0;
    }
    
  else if(Speed == 5){
    rpm = (rev / 24.7) * 60.0;
    }

  else if(Speed == 6){
    rpm = (rev / 28.7) * 60.0;
    }

  else if(Speed == 7){
    rpm = (rev / 32.7) * 60.0;
    }

  else if(Speed == 8){
    rpm = (rev / 37.3) * 60.0;
    }

  else if(Speed == 9){
    rpm = (rev / 40.9) * 60.0;
    }
    
  else if(Speed == 10){
    rpm = (rev / 43.7) * 60.0;
    }       
     
    rev = 0;
    //rpm = 0;
    lastTime = currentTime; 
  }
  
  lcd.setCursor(13,1);
  lcd.print(rpm);
  
  if(state_sensor_2 == LOW)
  { 
    
    valSpeed = analogRead(canalADC);    
    Speed = map(valSpeed,0,1023,1,10);
    Serial.println(Speed);
    for (int i = 0; i < 8; i++)
    { 
      digitalWrite(IN1, paso[i][0]);     
      digitalWrite(IN2, paso[i][1]);
      digitalWrite(IN3, paso[i][2]);
      digitalWrite(IN4, paso[i][3]);
      delay(Speed);
    
     }
   }
}

void contrev()
{
  rev++;
  
}
