  /*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Uso de la pantalla LCD com interfaz I2C
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 07 de mayo
*/


//librerias
#include <Servo.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

//definicion para pines
#define pinbu 3
#define ledRed A1
#define ledGreen 2
#define ledYell A2
#define pinser 11
#define ON(pin) digitalWrite(pin, HIGH);
#define OFF(pin) digitalWrite(pin, LOW);


byte anime1[] = {
  B00100,
  B01111,
  B00101,
  B01110,
  B10100,
  B10110,
  B01010,
  B10010
};

byte anime2[] = {
  B00100,
  B01110,
  B00101,
  B11110,
  B00100,
  B00111,
  B01000,
  B01000
};



const byte rowns = 4;
const byte columns = 4;

char keys[rowns][columns] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
  
};

byte rownsPins [rowns] = {12, 10, 9, 8};
byte columnsPins [columns] = {7, 6, 5, 4};

//constructor para el LCD
LiquidCrystal_I2C lcd(0x27,16,2);

//contructor para el teclado matricial
Keypad board_insano = Keypad( makeKeymap(keys), rownsPins, columnsPins, rowns, columns);

//confi servo
Servo doorservo;


//declaracion de varibales
String info_recibida = "";
byte poscol = 0;

String contra = "2024*";



void setup()
{
  Serial.begin(9600);
  inicializaciones();
  pines_conf();
  doorservo.write(0);
  
  lcd.createChar(1, anime1);
  lcd.createChar(2, anime2);
   
  ON(ledYell);
  ON(ledRed);
  lcd.setCursor(3,0);
  lcd.print("Bienvenido");
  lcd.setCursor(1,1);
  lcd.print("Puerta Cerrada");
}

void loop(){
  
  char key = board_insano.getKey();
  
  
  if(key){
    info_recibida = info_recibida + key;
    Serial.println(key);
    lcd.setCursor(poscol,1);
    lcd.print("*               ");
    poscol++;
    
    if(key == '*'){
      lcd.setCursor(0,1);
      lcd.print("               ");
    
      if(info_recibida == contra){
        lcd.setCursor(0,1);
        ON(ledGreen);
        OFF(ledRed);
        lcd.print("Contra  correcta");
        doorservo.write(90);
        buzzer();
        delay(1500);
        
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(1,1);
        delay(300);
        lcd.print("Puerta abierta");
        delay(1500);
        animacion();
        Serial.println("Contra correcta");
      }
      
      else{
        lcd.setCursor(0,1);
        ON(ledRed);
        OFF(ledGreen);
        lcd.print("Contra incorrect");
        badbuzz(); 
        delay(1500);
        lcd.setCursor(0,1);
        lcd.print("                 ");
        lcd.setCursor(1,1);
        delay(300);
               
        Serial.println("Contra incorrecta");
      }
      
      info_recibida = "";
      delay(700);
      ON(ledRed);
      OFF(ledGreen);
      doorservo.write(0);
      lcd.setCursor(0,1);
      lcd.print("               ");
      delay(200);
      
      lcd.setCursor(1,1);
      lcd.print("Puerta cerrada");
      poscol = 0;
    }
  }
}

void buzzer(){
  for(int i = 0; i < 2; i++){
    tone(pinbu, 500, 200);
    delay(200);
    noTone(pinbu);
    delay(200);
  }
}

void badbuzz(){
  for(int i = 0; i < 5; i++){
    tone(pinbu, 500, 200);
    delay(200);
    noTone(pinbu);
    delay(200);
  }
}

void pines_conf(){
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYell, OUTPUT);
  doorservo.attach(pinser);
  
}

void inicializaciones(){
  lcd.init();
  lcd.backlight();
}

void animacion(){
  lcd.setCursor(0,1);
  lcd.print("                 ");
  lcd.setCursor(2,1);
  lcd.print("Adelante!");
  for(int i = 0; i<8; i++){
    lcd.setCursor(13,1);
    lcd.write(1);
    lcd.setCursor(13,1);
    lcd.write(2);
    delay(70);
  }
  lcd.setCursor(0,1);
  lcd.print("                ");
}
