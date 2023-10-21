#include <Arduino.h>

class Tiempo {
private:
    int hora, minutos, segundos;

public:
    Tiempo(int, int, int);
    Tiempo(long);
    void mostrarTiempo();
};

Tiempo::Tiempo(int _hora, int _minutos, int _segundos) {
    hora = _hora;
    minutos = _minutos;
    segundos = _segundos;
}

Tiempo::Tiempo(long tiempo) {
    hora = int(tiempo / 10000);
    minutos = int((tiempo - hora * 10000) / 100);
    segundos = int(tiempo - hora * 10000 - minutos * 100);
}

void Tiempo::mostrarTiempo() {
    Serial.print("La hora es: ");
    Serial.print(hora);
    Serial.print(":");
    Serial.print(minutos);
    Serial.print(":");
    Serial.println(segundos);
}

void setup() {
    Serial.begin(9600);

    int hora, minutos, segundos;

    Serial.println("Ingrese las horas:");
    while (!Serial.available()) {
        // Espera a que se ingresen las horas
    }
    hora = Serial.parseInt();

    Serial.println("Ingrese los minutos:");
    while (!Serial.available()) {
        // Espera a que se ingresen los minutos
    }
    minutos = Serial.parseInt();

    Serial.println("Ingrese los segundos:");
    while (!Serial.available()) {
        // Espera a que se ingresen los segundos
    }
    segundos = Serial.parseInt();

    for (minutos = minutos; minutos >= 60; hora++) {
        minutos = minutos - 60;
    }
    for (segundos = segundos; segundos >= 60; minutos++) {
        segundos = segundos - 60;
    }

    Tiempo hoy(hora, minutos, segundos);
    hoy.mostrarTiempo();

    Tiempo ayer(13045);
    ayer.mostrarTiempo();
}

void loop() {
    // El loop de Arduino, si es necesario
}