/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Interfaces de comunicación e identificación
   Dev: Kevin Owen Roger Pablo Lastor
   Fecha: 22 de Julio
*/

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9         
#define SS_PIN 10
#define LED_RED 4
#define LED_GREEN 5
#define Buzzcut 3

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;  

byte ID_RFID[4];
byte Admin_server[4] = {0xE3, 0x23, 0xC7, 0x24};


void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.println("Kangaroo Court - Club");
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())
    return;

  if ( ! mfrc522.PICC_ReadCardSerial())
    return;

    Serial.print("Membresia UID:");
    for (byte i = 0; i < mfrc522.uid.size; i++) {   
      if(mfrc522.uid.uidByte[i] < 0x10){
        Serial.print(" 0");
        }
        else{
          Serial.print(" ");
          }
          Serial.print(mfrc522.uid.uidByte[i], HEX);
          ID_RFID[i] = mfrc522.uid.uidByte[i];
    }
    Serial.println(" ");

    if(Access(ID_RFID,Admin_server)){
      Serial.println(" Acceso permitido ");             
      Serial.println("Bienvenido Papu Supremo");
      digitalWrite(LED_GREEN,HIGH);
      tone(Buzzcut, 200);
      delay(4000);
    }
       
    else {
      Serial.println(" Desconocido... ");   
      Serial.println("Y vos quien sos? >:/" );      
      digitalWrite(LED_RED,HIGH);
      tone(Buzzcut, 400);
      delay(4000);
    }
    
    digitalWrite(LED_GREEN,LOW);      
    digitalWrite(LED_RED,LOW);
    noTone(Buzzcut);
}

boolean Access(byte Tag_read[], byte Membership[]){
    for(byte i = 0; i < mfrc522.uid.size; i++){
      if(Tag_read[i] != Membership[i]){
        return(false);
        }
      }
      return(true);
}
