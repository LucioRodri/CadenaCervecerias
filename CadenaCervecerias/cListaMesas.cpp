#include "cListaMesas.h"

cListaMesas::cListaMesas(unsigned int TAM, bool eliminar_lista)
{
	vector = new cMesas* [TAM];
	for (unsigned int i = 0; i < TAM; i++)
		vector[i] = NULL;

	this->TAM = TAM;
	this->eliminar_lista = eliminar_lista;
	CA = 0;
}

cListaMesas::~cListaMesas()
{
	if (vector != NULL)
	{
		if (eliminar_lista) {
			for (unsigned int i = 0; i < CA; i++)
			{
				if (vector[i] != NULL)
					delete vector[i];
			}
		}
		delete[] vector;
	}
}

bool cListaMesas::AgregarItem(cMesas* item)
{
	cMesas* i_f = BuscarItem(item);
	if (i_f != NULL)
		throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		vector[CA++] = item;
	else
		throw new exception("No hay tamaño suficiente para agregar el item");
	return true;
}
cMesas* cListaMesas::BuscarItem(cMesas* mesa)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i] == mesa)
			return vector[i];
	}
	return NULL;
}

void cListaMesas::operator+(cMesas* item)
{
	AgregarItem(item);
}

cMesas* cListaMesas::getItem(unsigned int pos)
{
	if (pos < CA && pos >= 0)
		return vector[pos];
	else
		throw new exception("Posición inválida");
}

void cListaMesas::EliminarEnPos(unsigned int pos)
{
	if (pos >= CA || pos < 0)
		throw new exception("Posicion invalida");

	cMesas* aux = vector[pos];

	for (unsigned int i = pos; i < CA - 1; i++)
		vector[i] = vector[i + 1];

	vector[CA - 1] = NULL;
	CA--;
	delete aux;
}

void cListaMesas::operator-()
{
	EliminarEnPos(CA);
}

cMesas* cListaMesas::operator[](unsigned int pos)
{
	return getItem(pos);
}

void cListaMesas::Listar()
{
}

void cListaMesas::Redimensionalizar()
{
//defino nuevo tamaño
	TAM += 10;
	//creo nuevo vector auxiliar
	cMesas** aux = new cMesas* [TAM];

	//copio los datos al nuevo vector y pongo el resto en NULL
	for (int i = 0; i < TAM; i++)
	{
		if (i < CA)
			aux[i] = vector[i];
		else
			aux[i] = NULL;
	}

	//borro el vector anterior
	delete[] vector;

	//guardo mi nuevo vector
	vector = aux;
}

unsigned int cListaMesas::getItemPos(cMesas* mesa)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i] == mesa)
			return i;
	}
	return -1;
}

unsigned int cListaMesas::getCA()
{
	return CA;
}

unsigned int cListaMesas::getTAM()
{
	return TAM;
}
