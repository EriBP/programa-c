/*
 * ESP32CAM_OPERADORES
 * Por: Erika Barojas
 * Fecha: 11 de abril 2022
2* 
 * ESTE ES UN PROGRAMA PARA EJEMPLIFICAR EL USO DEL OPERADOR MODULO
 */

// Bibliotecas
// #include <Serial.h>;  //EL SERIAL ESTA DENTRO DE LA BIBLIOTECA DE ARDUINO


// Constantes

// Variables
int dato = 0;   // Inicializo una variable para establecer un contador de anillo


// Definición de objetos

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código
    Serial.begin (115200); //inicializar el moonitor serial, parametro velocidad
    
    // Serial.print ("Conexion iniciada"); imprime pero no da salto
    Serial.println("Conexion serial iniciada");// probar comunicacion serial con un mensaje. De la biblioteca serial instruccion println
  //  delay (1000);//Agregar esperas poder visualizar lo que se necesita en milisegundos
    
}// Fin de void setup

// Cuerpo del programa - Se ejecuta constamente
void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:
    dato++;   //operador incremental  o
    //dato = dato + 1;       //primera es mas eficiente
    
    // ********************CONTADOR DE ANILLO (DOS FORMAS)*******************************
         // CON COMPARACION
    // if (dato > 8) {
      // dato = 0;                                                                                                          
    // }

    
        // CON OPERADOR
    dato %= 8; //operador de residuo
    
    Serial.println(dato);    //imprimo contenido dato
    delay (1000);    //Espera

}// Fin de void loop

// Funcioes del usuario
