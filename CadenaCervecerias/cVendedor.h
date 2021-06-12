#pragma once
#include "cEmpleado.h"
class cVendedor :
    public cEmpleado
{
    friend class cLocal;
    static unsigned int SalarioPorHora;
    void modificarSalario(unsigned int nuevo) { SalarioPorHora = nuevo; };
public:
    cVendedor(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0);
    ~cVendedor();
};

