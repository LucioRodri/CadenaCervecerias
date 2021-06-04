#define _CRT_SECURE_NO_WARNINGS
#include "Bar.h"
#include"PuntoDeVenta.h"
#include <ctime>
#include "cEncargado.h"
#include "cMesero.h"
#include "cVendedor.h"
#include "Cerveceria.h"
#include "cListaMesas.h"

using namespace std;//Podriamos cambiar numero por codigo en cLocal y hacerlo static
int main() {
	time_t now = time(0);
	tm* time = localtime(&now);
	tm* times = time;
	if (time->tm_hour >= 22)
		times -= 2;
	else
	times->tm_hour += 2;
	//--------Creamos los punteros que vamos a usar para la simulacion y prueba--------
	cLocal* bar = new Bar(time, "La Taberna de Moe", "Wakanda");
	cLocal* puntoVenta = new PuntoDeVenta(time, "Express", "Argentina");
	cEmpleado* encargado = new cEncargado("27-28033514-8", time, times);
	cEmpleado* vendedor = new cVendedor("47-321231232-5", time, times);
	cEmpleado* mesero = new cMesero("42-89578425-2", time, times);
	Cerveceria* empresa = new Cerveceria();
	//--------Asignamos punteros a la listas para poder modificar este atributo privado--------
	cLista<cLocal>* lista = empresa->getLista();
	cLista<cEmpleado>* listaEmpleados = bar->getListaEmpleados();
	//--------Probamos a agregar empleados al bar--------
	try {
		*listaEmpleados + encargado;
		*listaEmpleados + vendedor;
		*listaEmpleados + mesero;
		*listaEmpleados + new cVendedor("32-432332531-3", time, times);
	}
	catch(exception* error){
		cout << error->what() << endl;
		delete error;
	}
	//--------Probamos a eliminar a un vendedor y agregar el bar a la cadena--------
	try {
		*listaEmpleados - vendedor->getclave();
		*lista + bar;
	}
	catch (exception* error) {
		cout << error->what() << endl;
		delete error;
	}
	//--------Apuntamos los punteros creados para agregar nuevos empleados al punto de venta--------
	encargado = new cEncargado("56-26043864-4", time, times);
	vendedor = new cVendedor("52-23276412-1", time, times);
	mesero = new cMesero("13-14135512-3", time, times);
	listaEmpleados = puntoVenta->getListaEmpleados();
	try {
		*listaEmpleados + encargado;
		*listaEmpleados + vendedor;
		*listaEmpleados + new cVendedor("21-344331521-3", time, times);
	}
	catch (exception* error) {
		cout << error->what() << endl;
		delete error;
	}
	//--------Probamos a eliminar a un vendedor y agregar el punto de venta a la cadena--------
	try {
		*listaEmpleados - vendedor->getclave();
		*lista + puntoVenta;
	}
	catch (exception* error) {
		cout << error->what() << endl;
		delete error;
	}

	//Agrego las mesas del bar--------------------------------------------------
	cListaMesas* lMesas = ((Bar*)bar)->getListaMesas();
	cMesas* Mesa = new cMesas(20, true);
	try {
		*lMesas + Mesa;
		Mesa = new cMesas();
		*lMesas + Mesa;
		Mesa = new cMesas(6);
		*lMesas + Mesa;
		Mesa = new cMesas(10);
		*lMesas + Mesa;
	}
	catch(exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	Tick(lista);

	/*
	Podemos agregar un metodo polimorfico en cEmpleado que sirva para calcular los sueldos de cada clase de empleado?
	O convendria hacerlo de otra forma?
	*/
	return 0;
}

void Tick(cLista<cLocal>* lista_locales) {
	for (int i = 0; i < lista_locales->getCA(); i++)
	{
		lista_locales[0][i]->SimularCliente();
	}
}