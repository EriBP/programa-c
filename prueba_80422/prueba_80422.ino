
/*
 * Ejemplo de operadores
 * Fecha: 8 de abril del 2022
 * 
 * Esteprograma permite experimentar el uso y aplicaciones del 
 * operador de modulo
 */

 //Blibliotecas
 //#include <Serial.h> //Opcional

 // Constantes

 // Variables
 int dato = 0;
 double timeStart, timeFinish;

 // Definicion de objetos·

 // Condiciones iniciales · Se ejecuta solo un vez al energizar
 void setup() {                 //Inicio de void setup()
    //Aqui va tu codigo
    Serial.begin (115200); //Inicial comunicacion serial
    Serial.println ("Comunicacion Serial Iniciada");
    delay (10000);        
 }//Fin de void setup

 // Cuerpo del programa · Se ejecuta constantemente
 void loop(){              //Inicio de void loop
   //put your main code here, to run repeatedly;

   timeStart = micros (); //Inicia el conteo de tiempo

   //Ejecuta el contador de anillo 10 mil veces
   for (int i = 0; i < 10000; i++) {
   dato++;
   //Comparacion
   if (dato > 8) {
    dato = 0;
   }
 }

 timeFinish = micros (); //Termina el conteo de tiempo

 //Reporte en monitor serial
 Serial.print("Con if ");
 Serial.println (timeFinish - timeStart); //Imprimir el valor del contador
 delay (10000);

 timeStart = micros ();  //Inicia el conteo de tiempo

 //Ejecuta el contador de anillo 10 mil veces
 for (int i = 0; i < 10000; i++){
    dato++;
    //Incremento
    //Modulo
    dato %=8;
 }
 
   timeFinish = micros ();  //Termina el conteo de tiempo
   //Reporte en monitor serial
   Serial.print ("Con operadores  ");
   Serial.println (timeFinish - timeStart); //Imprimir el valor del contador   
   delay(1000);
   
 }//Fin de void loop
   
 //Funicioes del usuario
