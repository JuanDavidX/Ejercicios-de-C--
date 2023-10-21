#include <Arduino.h>

int numeros[5] = {1, 2, 3, 4, 5};
int suma = 0;

void setup() {
  Serial.println();
   Serial.begin(9600); 
   delay(1000); 

       for (int i = 0; i < 5; i++) {
           suma += numeros[i];
        }

              Serial.print("La suma de los elementos del arreglo es: ");
              Serial.println(suma);
}

void loop() {
  
}