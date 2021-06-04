#include "cEmpleado.h"

cEmpleado::cEmpleado(string cuit, tm* hora_entrada, tm* hora_salida, unsigned int horas_trabajadas)
{
	this->CUIT=cuit;
	this->HoraEntrada = hora_entrada;
	this->HoraSalida = hora_salida;
	this->HorasTrabajadas = horas_trabajadas;
}
 
cEmpleado::~cEmpleado()
{
}

void cEmpleado::CalcularHorasTrabajadas()
{
}
