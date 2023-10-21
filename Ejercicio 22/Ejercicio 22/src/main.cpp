#include <Arduino.h>

int numero;

void setup() {
  Serial.println();
  Serial.begin(9600); 
  delay(1000); 

       do {
             Serial.println("Digite un numero[1-10]: ");
                while (Serial.available() == 0) {
      
                 }
                    numero = Serial.parseInt();
                   
                       } while (numero < 1 || numero > 10);

                             for (int i = 1; i <= 20; i++) {
                                   Serial.print(numero);
                                   Serial.print(" * ");
                                   Serial.print(i);
                                   Serial.print(" = ");
                                   Serial.println(numero * i);
                                     
                                  }
}

void loop() {
  
}