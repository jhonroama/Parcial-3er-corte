
#include <Rgb.h>


Rgb::Rgb(){
  pinBoton = 35;
  estadoAnteriorBoton = HIGH;
  estadoPulsador = false;
  pinBoton1 = 36;
  pinBoton2 = 39;
  pinBoton3 = 34;
  contador = 255;
  contador2 = 255;
  contador3 = 255;

}

void Rgb::aumentarContador(int &contador, int pin) {
    contador += 10;
    analogWrite(pin, contador);
    delay(100);
    if (contador > 255) {
      contador = 255;
      analogWrite(pin, contador);
    }
}

void Rgb::disminuirContador(int &contador, int pin) {
    contador -= 10;
    analogWrite(pin, contador);
    delay(100);
    if (contador < 0) {
      contador = 0;
      analogWrite(pin, contador);
    }
}

void Rgb::setup() {
    Serial.begin(9600);
}

void Rgb::loop() {
    int estadoBoton = digitalRead(pinBoton);
    int estado1 = digitalRead(pinBoton1);
    int estado2 = digitalRead(pinBoton2);
    int estado3 = digitalRead(pinBoton3);

    if (estadoBoton != estadoAnteriorBoton) {
      estadoBoton = digitalRead(pinBoton);

      if (estadoBoton == 0) {
        if (!estadoPulsador) {
          estadoPulsador = true;
          Serial.println("SUBIR");
        } else {
          estadoPulsador = false;
          Serial.println("BAJAR");
        }
      }
    }
    if (estado1 == 1 && estadoPulsador == 1) {
      disminuirContador(contador, 32);
    } else if (estado1 == 1 && estadoPulsador == 0) {
      aumentarContador(contador, 32);
    } else if (estado2 == 1 && estadoPulsador == 1) {
      disminuirContador(contador2, 33);
    } else if (estado2 == 1 && estadoPulsador == 0) {
      aumentarContador(contador2, 33);
    } else if (estado3 == 1 && estadoPulsador == 1) {
      disminuirContador(contador3, 25);
    } else if (estado3 == 1 && estadoPulsador == 0) {
      aumentarContador(contador3, 25);
    }

    Serial.println(estadoPulsador);
    Serial.println("Valores");
    Serial.print(contador);
    Serial.print(" ");
    Serial.print(contador2);
    Serial.print(" ");
    Serial.print(contador3);
    Serial.print(" ");
    delay(250);
    estadoAnteriorBoton = estadoBoton;
}