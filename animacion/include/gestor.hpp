#pragma once
#include <vector>
#include <memory>
#include <random>
#include "particula.hpp"

using namespace std;

class GestorParticulas {
 public:
  GestorParticulas(int width, int height);
  void Refrescar();
  vector<shared_ptr<Particula>> ListarParticulas() const;

 private:
  int ancho, alto;
  int maximo_particulas;
  vector<shared_ptr<Particula>> Particulas;
  mt19937 rng;
  uniform_int_distribution<int> distX;
  uniform_int_distribution<int> distY;
  uniform_int_distribution<int> distSpawn;

  void GenerarParticulas();
};
