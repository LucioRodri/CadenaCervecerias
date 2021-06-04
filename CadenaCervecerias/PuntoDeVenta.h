#pragma once
#include "cLocal.h"
class cMesas;
class PuntoDeVenta :
    public cLocal
{
    cLista<cMesas>* getListaMesas() { return NULL; };
public:
    PuntoDeVenta(tm* fecha, string nombre, string ubicacion, float litros = 0, unsigned monto = 0);
    ~PuntoDeVenta();
    void ActualizarSuministros();
    void SimularCliente();
    string to_string();
    void imprimir();
};

