#define sol 391.995
#define mib 311.127
#define sib 466.164
#define re 293.665
#define solb 369.994
#define faS 369.994
#define fa 349.228
#define mi 329.628
#define reS 311.127
#define solS 415.305
#define doS 277.183
#define doN 261.626
#define si 493.883
#define la 440.000
#define laS 466.164
#define pin 9

int redonda = 1000;
int blanca = 500;
int negra = 250;
int corchea = 125;
int semicorchea = 63;
int corcheaPD = 188;

  
void setup()
{
  pinMode(pin, OUTPUT);

  tone(pin, sol, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, sol, negra);
  delay(negra);
  noTone(pin);
  delay(negra);
  
  tone(pin, sol, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, mib, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, sib, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, mib, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, sib, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, blanca);
  delay(blanca);
  noTone(pin);
  delay(blanca);

  tone(pin, re, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, re, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, re, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, mib, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, sib, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, faS, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, re, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, sib, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, blanca);
  delay(blanca);
  noTone(pin);
  delay(blanca);

  tone(pin, sol, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, sol, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, sol, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, faS, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, fa, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);
  
  //aqui empieza la segundo linea
  tone(pin, doS, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, doN, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, doS, corchea);
  delay(corchea);
  noTone(pin);
  delay(corchea);

  delay(corchea);

  tone(pin, fa, corchea);
  delay(corchea);
  noTone(pin);
  delay(corchea);

  tone(pin, laS, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, la, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, solS, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, faS, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, corchea);
  delay(corchea);
  noTone(pin);
  delay(corchea);

  delay(corchea);

  tone(pin, doN, corchea);
  delay(corchea);
  noTone(pin);
  delay(corchea);

  tone(pin, reS, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, doN, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, reS, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, mi, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, sol, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, si, blanca);//compas 9
  delay(blanca);
  noTone(pin);
  delay(blanca);

  tone(pin, mi, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, mi, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, mi, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, mi, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, reS, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, re, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, doS, semicorchea);//inicio compas 11  
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, doN, semicorchea); 
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, doS, corchea);
  delay(corchea);
  noTone(pin);
  delay(corchea);

  delay(corchea);

  tone(pin, fa, corchea);  
  delay(corchea);
  noTone(pin);
  delay(corchea);

  tone(pin, laS, negra);
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, la, corcheaPD);
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, solS, semicorchea);
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, semicorchea);//inicio compas 12  
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, faS, semicorchea);  
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, sol, corchea);  
  delay(corchea);
  noTone(pin);
  delay(corchea);

  delay(corchea);

  tone(pin, doN, corchea);  
  delay(corchea);
  noTone(pin);
  delay(corchea);

  tone(pin, reS, negra);  
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, doN, corcheaPD);  
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, sol, semicorchea);  
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, mi, negra);//inicio compas 13
  delay(negra);
  noTone(pin);
  delay(negra);

  tone(pin, doN, corcheaPD);  
  delay(corcheaPD);
  noTone(pin);
  delay(corcheaPD);

  tone(pin, sol, semicorchea);  
  delay(semicorchea);
  noTone(pin);
  delay(semicorchea);

  tone(pin, mi, redonda);
  delay(redonda);
  noTone(pin);
  delay(redonda);
}

void loop(){
}
