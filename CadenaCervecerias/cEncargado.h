#pragma once
#include "cEmpleado.h"
#include "cLocal.h"
class cEncargado :
    public cEmpleado
{
    friend class cLocal;
    static unsigned int SalarioPorHora;
    void modificarSalario(unsigned int nuevo) { SalarioPorHora = nuevo; };
    string EstadodeAnimo;
public:
    cEncargado(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0);
    ~cEncargado();
    void SolicitarCerveza(cCerveza* cerveza, unsigned int cantidad);//PedirBarriles
    void Verificar();//verifica que haya cerveza disponible
    //friend ostream& operator<<(ostream& out, cEncargado& E);
    friend istream& operator>>(istream& in, cEncargado& M);//Sobrecarga del hijo
    string getEstadoAnimo(){return EstadodeAnimo;};
};
ostream& operator<<(ostream& out, cEncargado& E);