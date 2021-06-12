#include "cEncargado.h"

cEncargado::cEncargado(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas):cEmpleado(cuit,hora_entrada, hora_salida,local,horas_trabajadas)
{
}

unsigned int cEncargado::SalarioPorHora = 1500;
cEncargado::~cEncargado()
{
}

void cEncargado::SolicitarCerveza(cCerveza* cerveza, unsigned int cantidad)
{
	cerveza->setBarriles(cantidad);
}

void cEncargado::Verificar()
{
	for (int i = 0; i < local_actual->getListaCervezas()->getCA(); i++) //va revisando para el local actual cada elemento de la lista cervezas
	{
		if (local_actual->listaCervezas->getItem(i)->getCantBarriles() <= 1)//si la cantidad del elemento i de la lista es menor a 1, pide mas
			SolicitarCerveza(local_actual->listaCervezas->getItem(i), 5);//pasa por parametro el elemento cerveza con cantidad baja
	}
}
