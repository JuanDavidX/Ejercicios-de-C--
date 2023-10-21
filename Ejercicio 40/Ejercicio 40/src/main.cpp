#include <Arduino.h>

void setup() {
  Serial.println();
  Serial.begin(9600);
  Serial.println("Digite su nombre: ");
}

void loop() {
  if (Serial.available() > 0) {
    char nombre[50];
    Serial.readBytesUntil('\n', nombre, 50);
    Serial.println(nombre);
  }
}