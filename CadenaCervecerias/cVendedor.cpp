#include "cVendedor.h"

cVendedor::cVendedor(string cuit, tm* hora_entrada, tm* hora_salida, unsigned int horas_trabajadas):cEmpleado(cuit, hora_entrada, hora_salida, horas_trabajadas)
{
}
const unsigned int cVendedor::SalarioPorHora = 1000;
cVendedor::~cVendedor()
{
}
