#pragma once
#include <string>
#include "cLocal.h"
#include "cLista.h"
class Cerveceria
{
	cLista<cLocal>* listaLocales; //hacer con una lista template?
	unsigned int MontoTotalFinal;
public:
	Cerveceria(cLista<cLocal>* lista_locales, unsigned int monto = 0);
	~Cerveceria();
	void CalcularMontoTotal();
	string to_string();
	void imprimir();
};

