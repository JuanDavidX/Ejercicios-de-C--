#include <Arduino.h>

int n1, n2;

void setup() {
  Serial.println();
  Serial.begin(9600); 
  delay(1000); 

    Serial.println();
    Serial.println("Digite 2 numeros: ");
}

void loop() {
  if (Serial.available() > 0) {
      int input = Serial.parseInt();
        if (input != 0) {
           n1 = input;
           Serial.print(n1);

             while (Serial.available() == 0) {
        
            }

                   input = Serial.parseInt();
                          if (input != 0) {
                           n2 = input;
                           Serial.println(n2);

                                 if (n1 == n2) {
                                     Serial.println("Ambos numeros son iguales");
                                          } else if (n1 > n2) {
                                                   Serial.print("El mayor es: ");
                                                   Serial.println(n1);
                                          } else {
                                                   Serial.print("El mayor es: ");
                                                   Serial.println(n2);
                                                  }

                                                   while (true) {
          
        }
      }
    }
  }
}