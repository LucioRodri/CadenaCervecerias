#pragma once
#include "cLocal.h"
#include "cMesas.h"
#include "cLista.h"
class Bar :
    public cLocal
{
    unsigned int CapCLientes;
    cLista<cMesas>* Mesas; //hacer con lista template?
public:
    Bar(tm* fecha, string nombre, string ubicacion, unsigned int capacidad = 100, float litros = 0, unsigned monto = 0);
    ~Bar();
    void ActualizarSuministros();
    void DistribuirEnMesas(unsigned int mesa);
    void SimularCliente();
    void VerificarMesas();
    cLista<cMesas>* getListaMesas() { return Mesas; };
    string to_string();
    void imprimir();
};

