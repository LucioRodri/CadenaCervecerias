#pragma once
#include "cLocal.h"

class PuntoDeVenta :
    public cLocal
{
public:
    PuntoDeVenta(tm* fecha, string nombre, string ubicacion, float litros = 0, unsigned monto = 0);
    ~PuntoDeVenta();
    void SimularCliente();
};

