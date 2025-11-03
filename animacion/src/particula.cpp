#include "particula.hpp"
#include <cstdlib>
using namespace std;

Particula::Particula(int x, int y, int vida, int altura)
  : x(x), y(y), dy(static_cast<float>(y)),
    velocidad_caida(0.05f + (rand() % 10) / 200.0f),
    vida(vida),
    edad(0),
    fase(4 + (rand() % 4)),
    altura_maxima(altura) {}

bool Particula::Actualizar() {
  edad++;
  dy += velocidad_caida;
  y = static_cast<int>(dy);
  return (edad < vida) && (y < altura_maxima);
}

char Particula::GetChar() const {
  int paso = edad / fase;

  switch (paso) {
    case 0: return '*';
    case 1: return 'O';
    case 2: return 'o';
    default: return '.'; 
  }
}

string Particula::Dibujar() const {
  return string(1, GetChar());
}

int Particula::GetX() const { return x; }
int Particula::GetY() const { return y; }

