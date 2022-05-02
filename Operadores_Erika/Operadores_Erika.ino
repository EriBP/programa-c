

/*
 * Programaci`on en C
 * Ejercicio IOT Operadores and y or
 * Sensor DHT11
 * Por: Erika Barojas Payan
 * Fecha: 25 de abril de 2022
 * 
 * 
 */

// Bibliotecas
#include "DHT.h"

// Constantes

#define DHTPIN 12   //Sensor esta en el pin 12
#define DHTTYPE DHT11  // Sensor

//*******Constantes de botones***********
const int BOTON1 = 14; //Boton 1 pin 14 donde voy a conectar
const int BOTON2 = 15; //Boton 1 pin 15
const int BOTON3 = 13; //Boton 1 pin 13

//*******Constantes de leds***********
const int LED1 = 4; //Boton 1 pin 4  donde voy a conectar
const int LED2 = 2; //Boton 1 pin 2

//*********Nivel de temperatura********
const int TEMP_H = 28

// Variables

int boton1_dato;  //No otorgo valor, lo toma de la primera lectura
int boton2_dato;
int boton3_dato;

// Definición de objetos
DHT dht(DHTPIN, DHTTYPE);

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()

// Aquí va tu código
Serial.begin(9600);
Serial.println(F("DHTxx test!"));

          //************Configurar botones************

pinMode (BOTON1, INPUT_PULLUP);  //pinMode Configura el pin del boton como entrada //INPUT, OUTPUT
pinMode (BOTON2, INPUT_PULLUP);  //Activar resistencia PULLUP, 1 o 0, Si precionamos se enciendo, de lo contrario se va a tierra.
pinMode (BOTON3, INPUT_PULLUP);

          //************Configurar leds************

pinMode (LED1, OUTPUT); //Configurar el pin del led como salida de voltaje
pinMode (LED2, OUTPUT);  
digitalWrite (LED1, LOW); //Empieza con el LED apagado   
digitalWrite (LED2, LOW); //Empieza con el LED apagado //se puede poner en el segundo parametro 1, true, HIGH, 0, false, LOW     
                                        
}// Fin de void setup



// Cuerpo del programa - Se ejecuta constamente

void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:
  delay(2000);

//*********Lectura del sensor**********
//Read temperature as Celsius (the default)
float t = dht.readTemperature();
//Check if any reads failed and exit early (to try again).
if (isnan(t)){
  Serial.println(F("Failed to read from DHT sensor!"));
  return
}
  Serial.println(t);

//*********Lectura del boton 1 *******
  
   boton1_dato = digitalRead(BOTON1); //Leer el pin del boton1
   if (boton1_dato == 1){
    digitalWrite ((LED1, LOW);//Prende o apaga el boton                                     
   }else {
    digitalWrite (LED1, HIGH);
   }

//****Automatico por temperatura, sobrecarga y alta demanda***

boton2_dato = digitalRead (BOTON2);
boton3_dato = digitalRead (BOTON3);

if (t>TEMP_H || boton2_dato == 1 || boton3_dato == 1){
  digitalWrite ((LED2, HIGH)                                       
   } else {
    digitalWrite (LED2, LOW);
   }


   
}// Fin de void loop

// Funcioes del usuario
