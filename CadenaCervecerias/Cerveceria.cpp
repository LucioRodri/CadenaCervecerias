#include "Cerveceria.h"
#define NMAX 100
Cerveceria::Cerveceria(unsigned int monto)
{
	this->listaLocales = new cLista<cLocal>[NMAX];
	this->MontoTotalFinal = monto;
}

Cerveceria::~Cerveceria()
{
	delete listaLocales;
}

void Cerveceria::CalcularMontoTotal()
{
}

string Cerveceria::to_string()
{
	return string();
}

void Cerveceria::imprimir()
{
}
