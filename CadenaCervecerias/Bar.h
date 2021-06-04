#pragma once
#include "cLocal.h"
#include "cListaMesas.h"
class Bar :
    public cLocal
{
    unsigned int CapCLientes;
    cListaMesas* Mesas; //hacer con lista template?
public:
    Bar(tm* fecha, string nombre, string ubicacion, unsigned int capacidad = 100, float litros = 0, unsigned monto = 0);
    ~Bar();
    void ActualizarSuministros();
    void DistribuirEnMesas(unsigned int mesa);
    void SimularCliente();
    void VerificarMesas();
    cListaMesas* getListaMesas() { return Mesas; };
    string to_string();
    void imprimir();
};

