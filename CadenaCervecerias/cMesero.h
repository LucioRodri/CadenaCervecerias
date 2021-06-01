#pragma once
#include "cEmpleado.h"
class cMesero :
    public cEmpleado
{
    static const unsigned int SalarioPorHora;
public:
    cMesero();
    ~cMesero();
};

