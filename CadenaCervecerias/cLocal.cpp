#include "cLocal.h"
#define NMAX 200

cLocal::cLocal(tm* fecha, string nombre, string ubicacion, float litros, unsigned monto)
{
	this->Fecha = fecha;
	this->Nombre=nombre;
	this->Ubicacion = ubicacion;
	listaEmpleados =new cLista<cEmpleado>[NMAX];
	listaCervezas = new cLista<cCerveza>[5];
	Codigo++;
}
unsigned int Codigo=0;

cLocal::~cLocal()
{
	delete listaEmpleados;
	delete listaCervezas;
}

void cLocal::ActualizarSuministros()
{
}

void cLocal::SimularCliente()
{
}

void cLocal::SumarMontoyLitros(cCerveza* cerveza)
{
}

void cLocal::Tick()
{
}

string cLocal::to_string()
{
	return string();
}

void cLocal::imprimir()
{
}
