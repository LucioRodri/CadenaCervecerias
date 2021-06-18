#include "Cerveceria.h"
#define NMAX 100
Cerveceria::Cerveceria()
{
	this->listaLocales = new cLista<cLocal>(NMAX);
	this->MontoTotalFinal = 0;
}

Cerveceria::~Cerveceria()
{
	delete listaLocales;
}

void Cerveceria::CalcularMontoTotal()
{
	for (int i = 0; i < listaLocales->getCA(); i++)
		MontoTotalFinal += listaLocales->getItem(i)->MontoTotal;
}


/*ostream& operator<<(ostream& out, Cerveceria& C)
{
	unsigned int monto;
	for(int i=0;i<C.listaLocales->getCA();i++)
	{
		out << *(C.listaLocales->getItem(i));
		out<<"\n-----------------------------------------------------------------\n";
	}
	C.CalcularMontoTotal();
	monto = C.getMontoTotal();
	out << monto;
	return out;
}*/

void Cerveceria::imprimir()
{
	cout << *this;
}
