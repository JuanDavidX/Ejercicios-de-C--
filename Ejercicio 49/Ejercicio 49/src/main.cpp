#include <Arduino.h>

char cadena[50];
int a = 0, e = 0, i = 0, o = 0, u = 0;
int contador = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese una oración (Max. 50 caracteres): ");
}

void loop() {
  if (Serial.available() > 0) {
    contador = 0;
    a = e = i = o = u = 0;
    Serial.readBytesUntil('\n', cadena, 50);
    strlwr(cadena);

    for (contador; contador < 50; contador++) {
      switch (cadena[contador]) {
        case 'a':
          a++;
          break;
        case 'e':
          e++;
          break;
        case 'i':
          i++;
          break;
        case 'o':
          o++;
          break;
        case 'u':
          u++;
          break;
      }
    }

    Serial.println(cadena);
    Serial.print("Vocal A: ");
    Serial.println(a);
    Serial.print("Vocal E: ");
    Serial.println(e);
    Serial.print("Vocal I: ");
    Serial.println(i);
    Serial.print("Vocal O: ");
    Serial.println(o);
    Serial.print("Vocal U: ");
    Serial.println(u);
    Serial.println("Presione cualquier tecla para salir");
    while (Serial.available() == 0) {
      
    }
    
    while (Serial.available() > 0) {
      Serial.read();
    }
    Serial.println("Ingrese una oración (Max. 50 caracteres): ");
  }
}




