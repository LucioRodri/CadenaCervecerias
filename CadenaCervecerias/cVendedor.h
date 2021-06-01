#pragma once
#include "cEmpleado.h"
class cVendedor :
    public cEmpleado
{
    static const unsigned int SalarioPorHora;
public:
    cVendedor();
    ~cVendedor();
};

