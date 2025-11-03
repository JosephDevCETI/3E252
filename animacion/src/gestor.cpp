#include "gestor.hpp"
#include <chrono>
using namespace std;

GestorParticulas::GestorParticulas(int width, int height)
  : ancho(ancho), alto(alto),
    rng(static_cast<unsigned>(chrono::high_resolution_clock::now().time_since_epoch().count())),
    distX(0, width - 1),
    prob(0, 99),
    maximo_particulas(350) {}

void GestorParticulas::GenerarParticulas() {
  if (Particulas.size() >= maximo_particulas) return;
  if (prob(rng) < 25) { 
    int x = distX(rng);
    Particulas.push_back(make_shared<Particula>(x, 0, 250, alto));
  }
}

void GestorParticulas::Refrescar() {
  GenerarParticulas();
  vector<shared_ptr<Particula>> activas;
  activas.reserve(Particulas.size());
  for (auto &p : Particulas) {
    if (p->Actualizar()) activas.push_back(p);
  }
  Particulas.swap(activas);
}

vector<shared_ptr<Particula>> GestorParticulas::ListarParticulas() const {
  return Particulas;
}
