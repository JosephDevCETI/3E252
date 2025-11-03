#include <ftxui/component/component.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <chrono>
#include "gestor.hpp"

using namespace ftxui;
using namespace std;

int main() {
  auto screen = Screen::Create(Dimension::Full(), Dimension::Full());
  GestorParticulas ps(screen.dimx(), screen.dimy());

  while (true) {
    
    int ancho = screen.dimx();
    int alto = screen.dimy();

    
    vector<vector<string>> grid(alto, vector<string>(ancho, " "));

    ps.Refrescar();

    for (auto &p : ps.ListarParticulas()) {
      int px = p->GetX();
      int py = p->GetY();
      if (px >= 0 && px < ancho && py >= 0 && py < alto)
        grid[py][px] = p->Dibujar();
    }

    vector<Element> lines;
    lines.reserve(alto);
    for (int y = 0; y < alto; ++y) {
      string fila;
      fila.reserve(ancho * 2);
      for (int x = 0; x < ancho; ++x)
        fila += grid[y][x] + " "; 
      lines.push_back(text(fila));
    }

    auto doc = vbox(std::move(lines));

    screen.Clear();
    Render(screen, doc);
    screen.Print();

    // limiter de FPS ~60
    this_thread::sleep_for(chrono::milliseconds(16));
  }

  return 0;
}
