#pragma once
#include <string>
#include "cLocal.h"
#include "cLista.h"
class Cerveceria
{
	cLista<cLocal>* listaLocales; //hacer con una lista template?
	unsigned int MontoTotalFinal;
public:
	Cerveceria(unsigned int monto = 0);
	~Cerveceria();
	void CalcularMontoTotal();
	cLista<cLocal>* getLista() { return listaLocales; };
	string to_string();
	void imprimir();
};

