#include "cEncargado.h"

cEncargado::cEncargado(string cuit, tm* hora_entrada, tm* hora_salida, unsigned int horas_trabajadas):cEmpleado(cuit,hora_entrada, hora_salida,horas_trabajadas)
{
}

const unsigned int cEncargado::SalarioPorHora = 1500;
cEncargado::~cEncargado()
{
}

void cEncargado::SolicitarCerveza(cCerveza* cerveza, unsigned int cantidad)
{
}

void cEncargado::Verificar()
{
}
