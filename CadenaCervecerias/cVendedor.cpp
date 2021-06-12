#include "cVendedor.h"

cVendedor::cVendedor(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas):cEmpleado(cuit, hora_entrada, hora_salida,local, horas_trabajadas)
{
}
unsigned int cVendedor::SalarioPorHora = 1000;
cVendedor::~cVendedor()
{
}
