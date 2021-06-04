#include "cLocal.h"

cLocal::cLocal(tm* fecha, string nombre, unsigned int numero, string ubicacion, cLista<cEmpleado>* lista_empleados, cLista<cCerveza>* lista_cerveza, float litros, unsigned monto)
{
	this->Fecha = fecha;
	this->Nombre = nombre;
	this->Numero = numero;
	this->Ubicacion = ubicacion;
	this->listaEmpleados = lista_empleados;
	this->listaCervezas = lista_cerveza;
}

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
