/* 
  Fundación Kinal
    Centro educativo Técncico Laboral Kinal
    Quinto Perito
    Quinto Electrónica 
    Codigo Técnico: EB5AM
    Curso: Taller de Electrónica Digital y reparación de computadoras
    Proyecto: Catálogo de productos
    Dev: Kevin Owen Roger Pablo Lastor
    Fecha: 19 de abril de 2024
*/

struct Dulce_1
{
  char nombre [50]; 
  int cantidad;
};

struct Dulce_2
{
  char nombre [50];
  int cantidad;
};

struct Dulce_3
{
  char nombre [50];
  int cantidad;
};

struct Dulce_4
{
  char nombre [50];
  int cantidad;
};


Dulce_1 dulce1 = {"Bubbaloo", 15};
Dulce_2 dulce2 = {"Mentos", 23};
Dulce_3 dulce3 = {"Coffes Dulce", 21};
Dulce_4 dulce4 = {"Toffe chocolate", 9};

int contador = 0;



void setup()
{
  Serial.begin(9600);
  Serial.println("Inventario Dulceria Kinal");
  Serial.println("Seleccione avanzar para continuar");
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop()
{
  if(digitalRead(2)==HIGH) 
  {
      delay(350);
      contador = contador + 1; 
   
    if(contador == 1){
      Serial.print("El Dulce numero 1 es: ");
      Serial.println(dulce1.nombre);
      Serial.print("La cantidad de dulces es: ");
      Serial.println(dulce1.cantidad);
    }
    
    if(contador == 2) {
      Serial.print("El Dulce numero 2 es: ");
      Serial.println(dulce2.nombre);
      Serial.print("La cantidad de dulces es: ");
      Serial.println(dulce2.cantidad);
    }
       
    if(contador == 3){
      Serial.print("El Dulce numero 3 es: ");
      Serial.println(dulce3.nombre);
      Serial.print("La cantidad de dulces es: ");
      Serial.println(dulce3.cantidad);
    }
    
  
    if(contador == 4){
      Serial.print("El Dulce numero 4 es: ");
      Serial.println(dulce4.nombre);
      Serial.print("La cantidad de dulces es: ");
      Serial.println(dulce4.cantidad);
    }
    
    if(contador == 5) { 
      contador = 0;
    }
  }  

  else if(digitalRead(3)==HIGH) 
  {
  delay(350);
    contador = contador-1;
    
    if(contador == 1){
      Serial.print("El Dulce numero 1 es: ");
      Serial.println(dulce1.nombre);
      Serial.print("La cantidad de dulces es: ");
      Serial.println(dulce1.cantidad);
    }
    
    if(contador == 2) {
      Serial.print("El Dulce numero 2 es: ");
      Serial.println(dulce2.nombre);
      Serial.print("La cantidad de dulces es: ");
      Serial.println(dulce2.cantidad);
    }
       
    if(contador == 3){
      Serial.print("El Dulce numero 3 es: ");
      Serial.println(dulce3.nombre);
      Serial.print("La cantidad de dulces es: ");
      Serial.println(dulce3.cantidad);
    }
    
  
    if(contador == 4){
      Serial.print("El Dulce numero 4 es: ");
      Serial.println(dulce4.nombre);
      Serial.print("La cantidad de dulces es: ");
      Serial.println(dulce4.cantidad);
    }
  }
}  
