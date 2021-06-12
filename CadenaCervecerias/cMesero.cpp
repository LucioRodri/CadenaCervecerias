#include "cMesero.h"

cMesero::cMesero(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas):cEmpleado(cuit, hora_entrada, hora_salida, local,horas_trabajadas)
{
}
unsigned int cMesero::SalarioPorHora = 500;
cMesero::~cMesero()
{
}
void cMesero::LimpiarMesa(cMesas* mesa)
{
	if(mesa->getLimpio()==false)
		mesa->LimpiarMesa();
}