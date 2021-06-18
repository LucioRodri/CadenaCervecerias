#pragma once
#include <string>
#include "cLocal.h"
#include "cLista.h"
class Cerveceria
{
	cLista<cLocal>* listaLocales; //hacer con una lista template?
	unsigned int MontoTotalFinal;
public:
	Cerveceria();
	~Cerveceria();
	void CalcularMontoTotal();
	cLista<cLocal>* getLista() { return listaLocales; };
	void imprimir();
	unsigned int getMontoTotal()  {  return MontoTotalFinal;  };
	friend ostream& operator<<(ostream& out, Cerveceria& C);
};


