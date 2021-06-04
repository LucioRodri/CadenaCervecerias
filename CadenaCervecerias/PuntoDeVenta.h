#pragma once
#include "cLocal.h"
class PuntoDeVenta :
    public cLocal
{
public:
    PuntoDeVenta(tm* fecha, string nombre, unsigned int numero, string ubicacion, cLista<cEmpleado>* lista_empleados, cLista<cCerveza>* lista_cerveza, float litros = 0, unsigned monto = 0);
    ~PuntoDeVenta();
    void ActualizarSuministros();
    void SimularCliente();
    string to_string();
    void imprimir();
};

