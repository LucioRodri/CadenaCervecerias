#pragma once
#include "cLocal.h"
#include "cListaMesas.h"
class Bar :
    public cLocal
{
    cListaMesas* Mesas; //hacer con lista template?
public:
    Bar(tm* fecha, string nombre, string ubicacion, float litros = 0, unsigned monto = 0);
    ~Bar();
    void DistribuirEnMesas(unsigned int cant_grupos);//recibe una cantidad de grupos de clientes, y segun esta cantidad ensucia una cantidad de mesas
    void SimularCliente();
    void VerificarMesas();
    cListaMesas* getListaMesas() { return Mesas; };
};

