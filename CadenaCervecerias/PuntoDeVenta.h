#pragma once
#include "cLocal.h"
class PuntoDeVenta :
    public cLocal
{
public:
    PuntoDeVenta();
    ~PuntoDeVenta();
    void ActualizarSuministros();
    void SimularCliente();
    string to_string();
    void imprimir();
};

