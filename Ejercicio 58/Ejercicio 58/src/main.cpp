#include <Arduino.h>

struct Datos {
    String ciudad, provincia;
    double salario;
};

struct Empleado {
    String nombre;
    Datos dir_empleado;
};

void setup() {
    Serial.begin(9600);
    int numero_empleados;

    Serial.println("Digite el número de empleados a registrar: ");
    while (!Serial.available()) {
        // Espera a que se ingrese el número de empleados
    }
    numero_empleados = Serial.parseInt();

    Empleado empleados[numero_empleados];

    for (int i = 0; i < numero_empleados; i++) {
        Serial.println("Empleado #" + String(i + 1));
        Serial.println("Nombre: ");
        while (!Serial.available()) {
            // Espera a que se ingrese el nombre
        }
        empleados[i].nombre = Serial.readStringUntil('\n');

        Serial.println("Provincia: ");
        while (!Serial.available()) {
            // Espera a que se ingrese la provincia
        }
        empleados[i].dir_empleado.provincia = Serial.readStringUntil('\n');

        Serial.println("Ciudad: ");
        while (!Serial.available()) {
            // Espera a que se ingrese la ciudad
        }
        empleados[i].dir_empleado.ciudad = Serial.readStringUntil('\n');

        Serial.println("Salario: ");
        while (!Serial.available()) {
            // Espera a que se ingrese el salario
        }
        empleados[i].dir_empleado.salario = Serial.parseFloat();
    }

    Serial.println("\nDatos de los empleados registrados:");

    for (int i = 0; i < numero_empleados; i++) {
        Serial.println("\nEmpleado #" + String(i + 1));
        Serial.println("Nombre: " + empleados[i].nombre);
        Serial.println("Provincia: " + empleados[i].dir_empleado.provincia);
        Serial.println("Ciudad: " + empleados[i].dir_empleado.ciudad);
        Serial.println("Salario: " + String(empleados[i].dir_empleado.salario, 2));
    }
}

void loop() {
    // Tu código en el loop, si es necesario
}