#pragma once
#include "cEmpleado.h"
class cCerveza;
class cEncargado :
    public cEmpleado
{
    static const unsigned int SalarioPorHora;
public:
    cEncargado();
    ~cEncargado();
    void SolicitarCerveza(cCerveza* cerveza, unsigned int cantidad);
    void Verificar();
};

