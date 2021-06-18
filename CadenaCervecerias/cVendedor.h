#pragma once
#include "cEmpleado.h"
class cVendedor :
    public cEmpleado
{
    friend class cLocal;
    static unsigned int SalarioPorHora;
    unsigned int AniosAntiguedad;
    void modificarSalario(unsigned int nuevo) { SalarioPorHora = nuevo; };
public:
    cVendedor(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0);
    ~cVendedor();
    friend ostream& operator<<(ostream& out, cVendedor& V);
    friend istream& operator>>(istream& in, cVendedor& V);
    //friend cVendedor& operator=(const cVendedor& otro);
};

