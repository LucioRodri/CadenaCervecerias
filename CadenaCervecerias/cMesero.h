#pragma once
#include "cEmpleado.h"
#include "cMesas.h"
class cMesero :
    public cEmpleado
{
    friend class cLocal;
    static unsigned int SalarioPorHora;
    void modificarSalario(unsigned int nuevo) { SalarioPorHora = nuevo; };
public:
    cMesero(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0);
    void LimpiarMesa(cMesas* mesa);
    ~cMesero();
};

