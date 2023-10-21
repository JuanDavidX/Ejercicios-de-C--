#include <Arduino.h>

int n1, n2, suma = 0, resta = 0, multiplicacion = 0;
float division = 0;

void setup() {
  Serial.println();
  Serial.begin(9600); 
  while (!Serial) {}

    Serial.print("Digite un numero: ");
      while (!Serial.available()) {
      }
        n1 = Serial.parseInt();
        Serial.println(n1);

            Serial.print("Digite otro numero: ");
            while (!Serial.available()) {
            }
              n2 = Serial.parseInt();
              Serial.println(n2);

  
               suma = n1 + n2;
               resta = n1 - n2;
               multiplicacion = n1 * n2;
               division = n1 / n2;

  
                Serial.print("\nLa suma es: ");
                Serial.println(suma);
                Serial.print("La resta es: ");
                Serial.println(resta);
                Serial.print("La multiplicacion es: ");
                Serial.println(multiplicacion);
                Serial.print("La division es: ");
                Serial.println(division);
                 }

 void loop() {

 }