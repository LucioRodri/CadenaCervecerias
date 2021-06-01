#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <ctime>
#include <string>
#include "cEmpleado.h"
#include "cLista.h"
#include "cCerveza.h"
using namespace std;
class cCerveza;
class cLocal
{
	friend class Cerveceria;
protected:
	tm* Fecha;
	float LitroPorDia;
	unsigned int MontoTotal;
	string Nombre;
	unsigned int Numero;
	string Ubicacion;
	cLista<cEmpleado>* listaEmpleados;//hacerlo con una lista template?
	cLista<cCerveza>* listaCervezas;
public:
	cLocal();
	~cLocal();
	virtual void ActualizarSuministros();
	virtual void SimularCliente();
	void SumarMontoyLitros(cCerveza* cerveza);
	void Tick();
	string to_string();
	void imprimir();
};

