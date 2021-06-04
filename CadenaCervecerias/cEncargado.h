#pragma once
#include "cEmpleado.h"
class cCerveza;
class cEncargado :
    public cEmpleado
{
    static const unsigned int SalarioPorHora;
public:
    cEncargado(string cuit, tm* hora_entrada, tm* hora_salida, unsigned int horas_trabajadas = 0);
    ~cEncargado();
    void SolicitarCerveza(cCerveza* cerveza, unsigned int cantidad);
    void Verificar();
};

