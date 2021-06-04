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
    Bar(tm* fecha, string nombre, unsigned int numero, string ubicacion, cLista<cEmpleado>* lista_empleados, cLista<cCerveza>* lista_cerveza,cLista <cMesas>* lista_mesas, unsigned int capacidad = 100, float litros = 0, unsigned monto = 0);
    ~Bar();
    void ActualizarSuministros();
    void DistribuirEnMesas(unsigned int mesa);
    void SimularCliente();
    void VerificarMesas();
    string to_string();
    void imprimir();
};

