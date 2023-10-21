#include <Arduino.h>

template <class TIPOD>
void despliegue(TIPOD dato);

void setup() {
    Serial.begin(9600);

    int dato1 = 4;
    float dato2 = 5.678;
    double dato3 = 156.789;
    char dato4 = 'a';

    despliegue(dato1);
    despliegue(dato2);
    despliegue(dato3);
    despliegue(dato4);
}

void loop() {
}

template <class TIPOD>
void despliegue(TIPOD dato) {
    Serial.print("El dato es: ");
    Serial.println(dato);
}