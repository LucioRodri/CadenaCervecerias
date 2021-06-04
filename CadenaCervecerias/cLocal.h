#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <ctime>
#include <string>
#include "cEmpleado.h"
#include "cLista.h"
#include "cCerveza.h"
using namespace std;
class cCerveza;
class cMesas;
class cLocal
{
	friend class Cerveceria;
protected:
	tm* Fecha;
	float LitroPorDia;
	unsigned int MontoTotal;
	string Nombre;
	static unsigned int Codigo;
	string Ubicacion;
	cLista<cEmpleado>* listaEmpleados;//hacerlo con una lista template?
	cLista<cCerveza>* listaCervezas;
public:
	cLocal(tm* fecha, string nombre, string ubicacion, float litros = 0, unsigned monto = 0);
	~cLocal();
	virtual void ActualizarSuministros();
	virtual void SimularCliente();
	void SumarMontoyLitros(cCerveza* cerveza);
	void Tick();
	cLista<cEmpleado>* getListaEmpleados() { return listaEmpleados; };
	cLista<cCerveza>* getListaCervezas() { return listaCervezas; };
	virtual cLista<cMesas>* getListaMesas() = 0;
	string to_string();
	void imprimir();
};

