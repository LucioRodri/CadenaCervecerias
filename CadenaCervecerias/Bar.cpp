#include "Bar.h"
#define NMAX 50
Bar::Bar(tm* fecha, string nombre, string ubicacion, unsigned int capacidad, float litros , unsigned monto):cLocal(fecha,nombre,ubicacion,litros,monto)
{
	this->Mesas = new cListaMesas[NMAX];
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
