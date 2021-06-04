#include "cMesero.h"

cMesero::cMesero(string cuit, tm* hora_entrada, tm* hora_salida, unsigned int horas_trabajadas):cEmpleado(cuit, hora_entrada, hora_salida, horas_trabajadas)
{
}
const unsigned int cMesero::SalarioPorHora = 500;
cMesero::~cMesero()
{
}
