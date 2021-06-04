#pragma once
#include "cEmpleado.h"
class cMesero :
    public cEmpleado
{
    static const unsigned int SalarioPorHora;
public:
    cMesero(string cuit, tm* hora_entrada, tm* hora_salida, unsigned int horas_trabajadas = 0);
    ~cMesero();
};

