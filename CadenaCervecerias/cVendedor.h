#pragma once
#include "cEmpleado.h"
class cVendedor :
    public cEmpleado
{
    static const unsigned int SalarioPorHora;
public:
    cVendedor(string cuit, tm* hora_entrada, tm* hora_salida, unsigned int horas_trabajadas = 0);
    ~cVendedor();
};

