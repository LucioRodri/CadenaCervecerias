#define _CRT_SECURE_NO_WARNINGS
#include "Bar.h"
#include"PuntoDeVenta.h"
#include <ctime>
#include "cEncargado.h"
#include "cMesero.h"
#include "cVendedor.h" 
#include "Cerveceria.h"
#include "cListaMesas.h"
#include <thread>
#include <chrono>
using std::this_thread::sleep_for;

using namespace std;//Podriamos cambiar numero por codigo en cLocal y hacerlo static
void Tick(cLista<cLocal>* lista_locales);
ostream& operator<<(ostream& out, Cerveceria& C);

int main() {
	srand(time(NULL));
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
	cEmpleado* encargado = new cEncargado("27-28033514-8", time, times,bar);
	cEmpleado* vendedor = new cVendedor("47-321231232-5", time, times, bar);
	cEmpleado* mesero = new cMesero("42-89578425-2", time, times, bar);
	Cerveceria* empresa = new Cerveceria();
	cCerveza* cerveza1 = new cCerveza(4, 50, "Rubia");
	//--------Asignamos punteros a la listas para poder modificar este atributo privado--------
	cLista<cLocal>* lista = empresa->getLista();
	cLista<cEmpleado>* listaEmpleados = bar->getListaEmpleados();
	//--------Probamos a agregar empleados al bar--------
	try {
		*listaEmpleados + encargado;
		*listaEmpleados + vendedor;
		*listaEmpleados + mesero;
		*listaEmpleados + new cVendedor("32-432332531-3", time, times, bar);
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
	encargado = new cEncargado("56-26043864-4", time, times, puntoVenta);
	vendedor = new cVendedor("52-23276412-1", time, times, puntoVenta);
	listaEmpleados = puntoVenta->getListaEmpleados();
	try {
		*listaEmpleados + encargado;
		*listaEmpleados + vendedor;
		*listaEmpleados + new cVendedor("21-344331521-3", time, times, puntoVenta);
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
	cMesas* Mesa = new cMesas(true);
	try {
		*lMesas + Mesa;
		Mesa = new cMesas();
		*lMesas + Mesa;
		Mesa = new cMesas();
		*lMesas + Mesa;
		Mesa = new cMesas();
		*lMesas + Mesa;
	}
	catch(exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	//Agregamos la cerveza a la lista
	*(bar->getListaCervezas()) + cerveza1;
	cerveza1 = new cCerveza(3,30,"Colorada");
	*(bar->getListaCervezas()) + cerveza1;
	cerveza1 = new cCerveza(2, 25, "Negra");
	*(puntoVenta->getListaCervezas()) + cerveza1;
	/*try {
		*lista + puntoVenta;
	}
	catch (exception* error) {
		cout << error->what();
		delete error;
	}*/
	time->tm_hour = 9;
	try {
		bar->setAbierto(true);//Abro el bar
		for (int i = 0; i < bar->getListaEmpleados()->getCA(); i++)
			bar->getListaEmpleados()->getItem(i)->setEntrada(time);
		puntoVenta->setAbierto(true);//Abro el punto de venta
		for (int i = 0; i < puntoVenta->getListaEmpleados()->getCA(); i++)
			puntoVenta->getListaEmpleados()->getItem(i)->setEntrada(time);
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		cout << error << endl;
	}
	Tick(lista);
	cout << *empresa;
	time->tm_hour = 17;
	try {
		bar->setAbierto(false);
		for (int i = 0; i < bar->getListaEmpleados()->getCA(); i++) {
			bar->getListaEmpleados()->getItem(i)->setEntrada(time);
			bar->getListaEmpleados()->getItem(i)->CalcularHorasTrabajadas();
		}
		puntoVenta->setAbierto(false);
		for (int i = 0; i < puntoVenta->getListaEmpleados()->getCA(); i++) {
			puntoVenta->getListaEmpleados()->getItem(i)->setEntrada(time);
			puntoVenta->getListaEmpleados()->getItem(i)->CalcularHorasTrabajadas();
		}
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		cout << error << endl;
	}
	//(bar->getListaEmpleados())[1];Probar despues
	/*
	Podemos agregar un metodo polimorfico en cEmpleado que sirva para calcular los sueldos de cada clase de empleado?
	O convendria hacerlo de otra forma?
	*/
	//------------------------------Prueba-----------------------------//
	bool Algo = (*(empresa->getLista()))[1]->getAbierto();
	//cLista<int>* Numeros = new cLista<int>();
	//delete Numeros;
	bar = new Bar(time, "Nombre raro", "Malta");
	delete bar;
	delete empresa;//Acordarse de cambiar la hora del Tick para que solo lo haga una vez
	return 0;//Preguntar time
}

void Tick(cLista<cLocal>* lista_locales) {
	/*int segundos = 0, minutos = 0, horas = 0;
	time_t now = time(0);
	tm* time = localtime(&now);
	if (time->tm_hour >= 8 && time->tm_hour < 17) { //nos fijamos que este en la hora de trabajo
		while (1) {
			clock_t t = clock();
			if (clock() - t / CLOCKS_PER_SEC == 1)
				segundos++;
			if (segundos == 60)
				minutos++;
			if (minutos == 60)
				horas++;
			if (horas == 1)
				break;
		}
		for (int i = 0; i < lista_locales->getCA(); i++)
		{
			lista_locales[0][i]->SimularCliente();
		}
		do {
			Tick(lista_locales);
		} while (time->tm_hour < 17);
	}*/
	time_t now = time(0);
	tm* time = localtime(&now);
	do {
		for (int i = 0; i < lista_locales->getCA(); i++)
		{
			try {
				if ((*lista_locales)[i]->getAbierto())//Reviso que el local este abierto
				{
				lista_locales->getItem(i)->SimularCliente();
				}
			}
			catch (exception* error)
			{
				cout << error->what()<<endl;
				delete error;
				(*lista_locales)[i]->setAbierto(false);//Cierro el local si me quedo sin suministros y el gerente no esta presente
			}
		}
		sleep_for(1s); //lo pusimos en 10 segundos en vez de 1 hora para probarlo
		time = localtime(&now);
	} while (time->tm_hour != 18);
}
ostream& operator<<(ostream& out, Cerveceria& C)
{
	unsigned int monto;
	for (int i = 0; i < C.listaLocales->getCA(); i++)
	{
		try {
			out << *(C.listaLocales->getItem(i));
			out << "\n-----------------------------------------------------------------\n";
		}
		catch (exception* ex) {
			string error = ex->what();
			delete ex;
			cout << error << endl;
		}
	}
	C.CalcularMontoTotal();
	monto = C.getMontoTotal();
	out << monto;
	return out;
}

