#include "Cerveceria.h"

Cerveceria::Cerveceria(cLista<cLocal>* lista_locales, unsigned int monto)
{
	this->listaLocales = lista_locales;
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
