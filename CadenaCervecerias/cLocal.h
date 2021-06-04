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
class cListaMesas;
class cLocal
{
	friend class Cerveceria;
	friend class cEmpleado; //el encargado va a usar actualizar suministros de esta clase
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
	virtual void ActualizarSuministros()=0;
	virtual void SimularCliente()=0;
	void SumarMontoyLitros(cCerveza* cerveza);
	//void Tick(); //hacerlo en el main, llama a simular cliente de la lista de locales
	string getclave() { return Nombre; };
	cLista<cEmpleado>* getListaEmpleados() { return listaEmpleados; };
	cLista<cCerveza>* getListaCervezas() { return listaCervezas; };
	string to_string();
	void imprimir();
};

