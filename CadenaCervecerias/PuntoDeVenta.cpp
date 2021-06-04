#include "PuntoDeVenta.h"

PuntoDeVenta::PuntoDeVenta(tm* fecha, string nombre, string ubicacion, float litros, unsigned monto):cLocal(fecha, nombre, ubicacion, litros, monto)
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
