#include "Bar.h"

Bar::Bar(tm* fecha, string nombre, unsigned int numero, string ubicacion, cLista<cEmpleado>* lista_empleados, cLista<cCerveza>* lista_cerveza, cLista <cMesas>* lista_mesas, unsigned int capacidad, float litros , unsigned monto):cLocal(fecha,nombre,numero,ubicacion,lista_empleados,lista_cerveza,litros,monto)
{
	this->Mesas = lista_mesas;
	CapCLientes = capacidad;
}

Bar::~Bar()
{
	delete Mesas;
}

void Bar::ActualizarSuministros()
{
}

void Bar::DistribuirEnMesas(unsigned int mesa)
{
}

void Bar::SimularCliente()
{
}

void Bar::VerificarMesas()
{
}

string Bar::to_string()
{
	return string();
}

void Bar::imprimir()
{
}
