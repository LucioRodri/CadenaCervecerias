#include "PuntoDeVenta.h"

PuntoDeVenta::PuntoDeVenta(tm* fecha, string nombre, unsigned int numero, string ubicacion, cLista<cEmpleado>* lista_empleados, cLista<cCerveza>* lista_cerveza, float litros, unsigned monto):cLocal(fecha, nombre, numero, ubicacion, lista_empleados, lista_cerveza, litros, monto)
{
}

PuntoDeVenta::~PuntoDeVenta()
{
}

void PuntoDeVenta::ActualizarSuministros()
{
}

void PuntoDeVenta::SimularCliente()
{
}

string PuntoDeVenta::to_string()
{
	return string();
}

void PuntoDeVenta::imprimir()
{
}
