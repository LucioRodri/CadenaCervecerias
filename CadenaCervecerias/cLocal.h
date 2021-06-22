#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include "cEmpleado.h"
#include "cLista.h"
#include "cCerveza.h"
#include "cMesero.h"
#include "cEncargado.h"
#include "Funciones.h"
using namespace std;

class cMesas;
class cListaMesas;
class cLocal
{
	friend class Cerveceria;//Clase friend
	friend class cEncargado; //el encargado va a usar actualizar suministros de esta clase
protected:
	tm* Fecha;
	int HoraApertura, HoraCierre;
	float LitroPorDia;
	unsigned int MontoTotal;
	string Nombre;
	unsigned int Codigo;
	static unsigned int Contador;//Atributo static
	string Ubicacion;
	cLista<cEmpleado>* listaEmpleados;//hacerlo con una lista template?
	cLista<cCerveza>* listaCervezas;
	bool Abierto;
public:
	cLocal(tm* fecha, string nombre, string ubicacion, float litros = 0, unsigned monto = 0);
	virtual ~cLocal();
	//segun la cantidad de litros que se restaron por SumarMonto, actualiza la cantidad de barriles para cada elemento de la lista de cervezas
	virtual void ActualizarSuministros();
	virtual void SimularCliente()=0;//Metodo polimorfico
	//resta para cada elemento de la lista de cervezas una cantidad de litros
	void SumarMontoyLitros(cCerveza* cerveza);
	//void Tick(); //hacerlo en el main, llama a simular cliente de la lista de locales
	string getclave() { return Nombre; };
	cLista<cEmpleado>* getListaEmpleados() { return listaEmpleados; };
	cLista<cCerveza>* getListaCervezas() { return listaCervezas; };
	friend ostream& operator<<(ostream& out, cLocal& L);
	void imprimir();
	void ActualizarFecha(tm* fecha);
	void setAbierto(bool estado) { this->Abierto = estado; };
	bool getAbierto() { return Abierto; };
};
