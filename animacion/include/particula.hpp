#pragma once
#include <string>
using namespace std;

class Particula {
public:
  Particula(int x, int y, int vida, int altura);
  bool Actualizar();
  string Dibujar() const;
  int GetX() const;
  int GetY() const;

private:
  int x, y;
  float dy;
  float velocidad_caida;
  int vida;
  int edad;
  int fase;
  int altura_maxima;
  char GetChar() const;
};

