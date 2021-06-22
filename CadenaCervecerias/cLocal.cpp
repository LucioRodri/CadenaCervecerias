#include "cLocal.h"
#define NMAX 200

cLocal::cLocal(tm* fecha, string nombre, string ubicacion, float litros, unsigned monto)
{
	this->Fecha = fecha;
	this->HoraApertura = 9;
	this->HoraCierre = 17;
	this->Nombre=nombre;
	this->Ubicacion = ubicacion;
	listaEmpleados =new cLista<cEmpleado>(NMAX);
	listaCervezas = new cLista<cCerveza>(5);
	this->Codigo = Contador;
	this->Abierto = false;
	Contador++;
}
unsigned int cLocal::Contador=1;

cLocal::~cLocal()
{
	delete listaCervezas;
	delete listaEmpleados;
}

void cLocal::ActualizarSuministros()
{
	for (int i = 0; i < listaCervezas->getCA(); i++)
		listaCervezas->getItem(i)->ConsumirBarriles();
}

void cLocal::SumarMontoyLitros(cCerveza* cerveza)
{
	cEncargado* ptr = NULL;
	for (int i = 0; i < listaEmpleados->getCA(); i++)
	{
		ptr = dynamic_cast<cEncargado*>(listaEmpleados->getItem(i));
		if (ptr != NULL)
			break;
	}
	if (ptr != NULL)
	{
		ptr->Verificar();
		MontoTotal += cerveza->getPrecioJarra();
		LitroPorDia += 0.5;
		cerveza->ConsumirJarra();
	}
	else
	{
		throw new exception("No hay un encargado y nos quedamos sin cerveza");
	}
}

void cLocal::ActualizarFecha(tm* fecha)
{
	if (fecha != NULL) {
		this->Fecha = fecha;
		MontoTotal = 0;
		LitroPorDia = 0;
	}
}


ostream& operator<<(ostream& out, cLocal& L)
{
	out << "Nombre: " << L.Nombre << "\nCodigo: " << L.Codigo << "\nLitro vendidos: " << L.LitroPorDia
		<< "\nMonto total: " << L.MontoTotal << "\nNombre: " << L.Nombre << "\nUbicacion: " << L.Ubicacion << endl;
	return out;
}

void cLocal::imprimir()
{
	cout << *this;
}
