#pragma once
#include <EstadoFoco.hpp>

class Foco
{
private:
    EstadoFoco estado;
public:
    Foco() {estado = false;}
    ~Foco() {}
    void Encender(){estado = true;}
    void Apagar(){estado = false;}
    bool ConsultarEstado(){return estado;}
};