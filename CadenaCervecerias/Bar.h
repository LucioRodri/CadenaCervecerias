#pragma once
#include "cLocal.h"
#include "cMesas.h"
class Bar :
    public cLocal
{
    unsigned int CapCLientes;
    cMesas* Mesas; //hacer con lista template?
public:
    Bar();
    ~Bar();
    void ActualizarSuministros();
    void DistribuirEnMesas(unsigned int mesa);
    void SimularCliente();
    void VerificarMesas();
    string to_string();
    void imprimir();
};

