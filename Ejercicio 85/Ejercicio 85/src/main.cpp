#include <Arduino.h>

int numeros[10];
int *dir_numeros;

void setup() {
Serial.println();
Serial.begin(9600);

    for (int i = 0; i < 10; i++) {
        Serial.print(i + 1);
        Serial.println(". Digite un numero: ");
        while (!Serial.available()) {
            
        }
        numeros[i] = Serial.parseInt();
    }

    dir_numeros = numeros;

    for (int i = 0; i < 10; i++) {
        if (*dir_numeros % 2 == 0) {
            Serial.print("Numero par: ");
            Serial.println(*dir_numeros);
            Serial.print("Posicion: ");
            Serial.println((unsigned long)dir_numeros, HEX); 
        }
        dir_numeros++;
    }
}

void loop() {
    
}