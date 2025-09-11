#pragma once
#include <Foco.hpp>
#include <iostream>

using namespace std;

class SerieNavidad
{
private:
    Foco focos[10];
public:
    SerieNavidad(/* args */) {}
    ~SerieNavidad() {}
    void Encender(){
        for (int nFoco = 0; nFoco < 10; nFoco++)
        {
           focos[nFoco].Encender();
        }
        
    }
    void Apagar(){
        for (int nFoco = 0; nFoco < 10; nFoco++)
        {
           focos[nFoco].Apagar();
        }
    }
    void ConsultarSerie(){
        for (int nFoco = 0; nFoco < 10; nFoco++)
        {
           cout << focos[nFoco].ConsultarEstado();
        }
    }
};