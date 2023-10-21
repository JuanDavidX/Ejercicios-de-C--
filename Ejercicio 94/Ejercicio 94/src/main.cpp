#include <Arduino.h>

struct Alumno {
    char nombre[30];
    int edad;
    float promedio;
} alumno[3], *puntero_alumno = alumno;

void pedirDatos();
void comprobarMejorPromedio(Alumno *);

void setup() {
    Serial.println();
    Serial.begin(9600);
    pedirDatos();
    comprobarMejorPromedio(puntero_alumno);
}

void loop() {
    
}

void pedirDatos() {
    for (int i = 0; i < 3; i++) {
        Serial.flush(); 
        Serial.println("Digite su nombre: ");
        while (!Serial.available()) {
            
        }
        Serial.readBytesUntil('\n', (puntero_alumno + i)->nombre, 30);

        Serial.println("Digite su edad: ");
        while (!Serial.available()) {
            
        }
        (puntero_alumno + i)->edad = Serial.parseInt();

        Serial.println("Digite su promedio: ");
        while (!Serial.available()) {
            
        }
        (puntero_alumno + i)->promedio = Serial.parseFloat();

        Serial.println();
    }
}

void comprobarMejorPromedio(Alumno *puntero_alumno) {
    float mayor = 0.0;
    int pos = 0;

    for (int i = 0; i < 3; i++) {
        if ((puntero_alumno + i)->promedio > mayor) {
            mayor = (puntero_alumno + i)->promedio; 
            pos = i; 
        }
    }

    
    Serial.println("\nAlumno con el mejor promedio:");
    Serial.print("Nombre: ");
    Serial.println((puntero_alumno + pos)->nombre);
    Serial.print("Edad: ");
    Serial.println((puntero_alumno + pos)->edad);
    Serial.print("Promedio: ");
    Serial.println((puntero_alumno + pos)->promedio);
}