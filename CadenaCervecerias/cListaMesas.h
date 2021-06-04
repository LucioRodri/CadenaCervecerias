#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "cMesas.h"
#include <string>
#define NMAX 100
using namespace std;
class cListaMesas
{
	cMesas** vector;
	int CA, TAM;
	bool eliminar_lista;
public:
	cListaMesas(unsigned int TAM = NMAX, bool eliminar_lista = true);
	~cListaMesas();

	bool AgregarItem(cMesas* item);
	cMesas* BuscarItem(cMesas* mesa);
	void operator+(cMesas* item);
	cMesas* getItem(unsigned int pos);

	void EliminarEnPos(unsigned int pos);
	void operator-();
	cMesas* operator [](unsigned int pos);
	void Listar();

	void Redimensionalizar();
	unsigned int getItemPos(cMesas* mesa);
	unsigned int getCA();
	unsigned int getTAM();


};

