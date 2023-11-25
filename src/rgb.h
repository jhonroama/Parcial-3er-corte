#include <Arduino.h>

class Rgb {
private:
  int pinBoton ;
  bool estadoAnteriorBoton;
  bool estadoPulsador;
  int pinBoton1;
  int pinBoton2 ;
  int pinBoton3 ;
  int contador;
  int contador2;
  int contador3;

public:
  Rgb();
  void aumentarContador(int &contador, int pin);
  void disminuirContador(int &contador, int pin); 
  void setup();
  void loop();
};