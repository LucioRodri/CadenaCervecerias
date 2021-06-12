#pragma once
#include "cEmpleado.h"
class cCerveza;
class cEncargado :
    public cEmpleado
{
    friend class cLocal;
    static unsigned int SalarioPorHora;
    void modificarSalario(unsigned int nuevo) { SalarioPorHora = nuevo; };
public:
    cEncargado(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0);
    ~cEncargado();
    void SolicitarCerveza(cCerveza* cerveza, unsigned int cantidad);//PedirBarriles
    void Verificar();//verifica que haya cerveza disponible
};

