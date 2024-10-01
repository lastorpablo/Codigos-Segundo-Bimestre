# include <SoftwareSerial.h>
#include <TimerOne.h>

int BT_Rx = 10;
int BT_Tx = 11;

SoftwareSerial BT(BT_Rx,BT_Tx);
volatile int i = 0;
volatile boolean cruce_cero = 0;
int Triac = 3; ;
int T_int=100;
int dim;
String cadena;
long valor;
void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode( Triac, OUTPUT);
  attachInterrupt(0, deteccion_Cruce_cero, RISING);
  Timer1.initialize(T_int);
  Timer1.attachInterrupt(Dimer, T_int);
}

void deteccion_Cruce_cero(){
  
cruce_cero = true;  
i=0;                                                 
digitalWrite(Triac, LOW); 
 
}

void Dimer() 
{                   
if (cruce_cero == true ){
  if (i>=dim ) {
  digitalWrite(Triac, HIGH);
  i=0;
  cruce_cero=false;
  }
  else
  {
    i++; 
  }}}

void loop() {
if(BT.available() > 0){
        int servopos = BT.read();
        dim = map(servopos,0,100,83,0);
    }
 
    if(BT.available() > 0){
        char mensaje = BT.read();
    }
}
