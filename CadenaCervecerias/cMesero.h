#pragma once
#include "cEmpleado.h"
#include "cMesas.h"
class cMesero :
    public cEmpleado
{
    friend class cLocal;
    static unsigned int SalarioPorHora;
    string Apodo;
    void modificarSalario(unsigned int nuevo) { SalarioPorHora = nuevo; };
public:
    cMesero(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0);
    void LimpiarMesa(cMesas* mesa);
    friend ostream& operator<<(ostream& out, cMesero& M);
    friend istream& operator>>(istream& in, cMesero& M);
    ~cMesero();
};

