/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto Final
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 22 de mayo
*/

//Librerias 
#include <Servo.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


//definiciones 
#define pinser 11
#define ON(pin); digitalWrite(pin, HIGH);
#define OFF(pin); digitalWrite(pin, LOW);


//Configuracion del teclado matricial
const byte rows = 2;
const byte columns = 3;

char keys[rows][columns] = 
{
  {'1','2','3'},
  {'4','5','6'}
};

byte rowsPins [rows] = {A0, A1};
byte columnsPins [columns] = {A2, A3, 13};

//contructor para el teclado matricial
Keypad board_insano = Keypad( makeKeymap(keys), rowsPins, columnsPins, rows, columns);

//constructor para LCD con I2C 
LiquidCrystal_I2C lcd(0x27,16,2);

//configuracion del servo
Servo mi_servo;

//array para el auto fantastico
int pinsec[4] = {7, 8, 9, 10};

//array x2
int display [6] = {2, 3, 4, 5, 6, 12};
int display2 [7] = {2, 12, 6, 5, 4, 3, 2};
int display3 [4] = {3, 4, 6, 12};
int display4 [6] = {2, 5, 3, 6, 4, 12};
int display5 [6] = {12, 4, 6, 3, 5, 2};
int display6 [3] = {2, 3, 12};
int display7 [3] = {4, 5, 6};




//variables globales
int time = 200;
int time2 = 1000;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Kevin Lastor");
  lcd.setCursor(1,1);
  lcd.print("Proyecto Final");
  setup_pins();
  mi_servo.write(0);
}

void loop()
{
  char key = board_insano.getKey();
  
  
  if(key)
  {    
    switch(key)
    {
      case('1'):
      {
        Serial.println("La Tecla Presionada fue 1");
        Serial.println("Contador Automatico de 0 - 99");
        for(int i=0; i <= 99; i++)
        { 
          Serial.println(i);
          delay(50);
        }
      break;
      }
      
      case('2'):
      {
        Serial.println("La Tecla Presionada fue 2");
        Serial.println("Contador Automatico de 99 - 0");
        for(int i = 99; i >= 0; i--)
        { 
          Serial.println(i);
          delay(50);
        }
      break;
      }
      
      case('3'):
      {
        Serial.println("La Tecla Presionada fue 3");
        auto_fantastico();
      break;
      }
      case('4'):
      {
        Serial.println("La Tecla Presionada fue 4");
        Serial.println("Secuencia Basica :c");
        cuarta_parte();
      break;
      }
      case('5'):
      {
        Serial.println("La Tecla Presionada fue 5");
        Serial.println("Movimiento de Servo a 180 grados");
        mi_servo.write(180);
        delay(2000);
        mi_servo.write(0);
      break;
      }
      case('6'):
      {

      break;
      }
    }
  }
}




void auto_fantastico()
{ 
  Serial.println("Secuencia de Auto Fantastico");
  for(int a = 0; a < 3; a++)
  {
    for (int i = 0; i<3; i++)
    {
      digitalWrite(pinsec[i], HIGH);
      delay(time);
      digitalWrite(pinsec[i], LOW);
    }
    
    for (int i = 3; i>0 ; i--)
    {
      digitalWrite(pinsec[i], HIGH);
      delay(time);
      digitalWrite(pinsec[i], LOW);
    }
  }
    for(int i = 0; i < 3; i++)
    {
      delay(350);
      for(int a = 0; a < 4; a++)
      {
        digitalWrite(pinsec[a], HIGH);
      }
      delay(500);
      for(int a = 4; a>=0; a--)
      {
        digitalWrite(pinsec[a], LOW);
      }
    }
}
  


void cuarta_parte()
{ 
  for(int i = 0; i < 6; i++)
  {
    ON(display[i]);
    delay(100);
  }
  delay(100);
  for(int i = 6; i >= 0; i--)
  {
    OFF(display[i]);
    delay(100);    
  }
  delay(100);
  for(int i = 0; i < 7; i++)
  {
    ON(display2[i]);
    delay(100);
  }
  delay(100);
  for(int i = 7; i >= 0; i--)
  {
    OFF(display2[i]);
    delay(100);    
  }
  delay(100);
  for(int i = 0; i < 4; i++)
  {
    ON(display3[i]);
    delay(100);
  }
  delay(100);
  for(int i = 4; i >= 0; i--)
  {
    OFF(display3[i]);
    delay(100);    
  }
  delay(100);
  for(int i = 0; i < 6; i++)
  {
    ON(display4[i]);
    delay(100);
  }
  delay(100);
  for(int i = 6; i >= 0; i--)
  {
    OFF(display5[i]);
    delay(100);    
  }
  delay(100);
  for(int i = 0; i < 6; i++)
  {
    ON(display4[i]);
    delay(100);
  }
  delay(100);
  for(int i = 6; i >= 0; i--)
  {
    OFF(display5[i]);
    delay(100);    
  }
  delay(300);
  for(int i = 0; i < 6; i++)
  {
    ON(display[i]);
    delay(500);
    OFF(display[i]);
  }
  delay(300);
  for(int i = 0; i < 7; i++)
  {
    ON(display2[i]);
    delay(500);
    OFF(display2[i]);
  }
  delay(400);
  for(int i = 0; i < 3; i++)
  {
    for(int i = 0; i < 3; i++)
    {
      ON(display6[i]);
    }
    delay(150);
    for(int i = 3; i >= 0; i++)
    {
      OFF(display6[i]);
    }
    delay(150);
    
    for(int i = 0; i < 3; i++)
    {
      ON(display7[i]);
    }
    delay(150);
    for(int i = 3; i >= 0; i++)
    {
      OFF(display7[i]);
    }
    delay(150);
  }
  
  for(int i = 0; i < 4; i++)
  {
    for(int i = 0; i < 6; i++)
    {
      ON(display[i]);
    }
    delay(400);
    for(int i = 6; i >= 0; i--)
    {
      OFF(display[i]);
    }
    delay(400);
  }
}



void setup_pins()
{ 
  for(int i = 0; i < 7; i++)
  {
    pinMode(display[i], OUTPUT);
  }
  
  mi_servo.attach(pinser);
  for(int i = 0; i < 4; i++)
  {
    pinMode(pinsec[i], OUTPUT);
  }
}
