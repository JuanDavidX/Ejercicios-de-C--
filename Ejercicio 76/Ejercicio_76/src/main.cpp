#include <Arduino.h>

void pedirDatos();
void comprobarSimetria(int m[][100], int, int);

int m[100][100], nfilas, ncol;

void setup() {
    Serial.begin(9600);
    pedirDatos();
    comprobarSimetria(m, nfilas, ncol);
}

void loop() {
    
}

void pedirDatos() {
    Serial.println(); 
    Serial.println("Digite el número de filas: ");
    while (!Serial.available()) {
       
    }
    nfilas = Serial.parseInt();
     
    Serial.println(); 
    Serial.println("Digite el número de columnas: ");
    while (!Serial.available()) {
       
    }
    ncol = Serial.parseInt();

 
    for (int i = 0; i < nfilas; i++) {
        for (int j = 0; j < ncol; j++) {
            Serial.println(); 
            Serial.print("Digite m[" + String(i) + "][" + String(j) + "]: ");
            while (!Serial.available()) {
              
            }
            m[i][j] = Serial.parseInt();
        }
    }
}

void comprobarSimetria(int m[][100], int nfilas, int ncol) {
    int cont = 0;

    // Si es cuadrada
    if (nfilas == ncol) {
        // y además si Aij = Aji
        for (int i = 0; i < nfilas; i++) {
            for (int j = 0; j < ncol; j++) {
                if (m[i][j] == m[j][i]) {
                    cont++; // El conteo debe ser igual al número de elementos de la matriz
                }
            }
        }
    }

    if (cont == nfilas * ncol) {
        Serial.println(); 
        Serial.println("La matriz es Simétrica");
    } else {
        Serial.println(); 
        Serial.println("La matriz NO es simétrica");
    }
}