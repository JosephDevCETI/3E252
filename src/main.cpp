#include <iostream> //libreria 
#include <Foco.hpp>
#include <SerieNavidad.hpp>

using namespace std; //abrebiacion 

int main(int argc, char const *argv[]){ //main

    Foco foco;
    foco.ConsultarEstado() ? foco.Apagar() : foco.Encender();
    string msj = foco.ConsultarEstado() ? "Encendido" : "Apagado" ;
    cout << "El foco esta " << msj <<endl;

    SerieNavidad miSerie;
    miSerie.Encender();
    miSerie.ConsultarSerie();
    miSerie.Apagar();
    miSerie.ConsultarSerie();
    return 0;
}