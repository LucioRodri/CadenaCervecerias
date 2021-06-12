#include "cLocal.h"
#define NMAX 200

cLocal::cLocal(tm* fecha, string nombre, string ubicacion, float litros, unsigned monto)
{
	this->Fecha = fecha;
	this->Nombre=nombre;
	this->Ubicacion = ubicacion;
	listaEmpleados =new cLista<cEmpleado>[NMAX];
	listaCervezas = new cLista<cCerveza>[5];
	Codigo++;
}
unsigned int cLocal::Codigo=0;

cLocal::~cLocal()
{
	delete listaEmpleados;
	delete listaCervezas;
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
}

void cLocal::ActualizarFecha(tm* fecha)
{
	this->Fecha = fecha;
	MontoTotal = 0;
	LitroPorDia = 0;
}


ostream& operator<<(ostream& out, cLocal& L)
{
	out << "Nombre: " << L.Nombre << "\nCodigo: " << L.Codigo << "\nLitro vendidos: " << L.LitroPorDia
		<< "\nMonto total: " << L.MontoTotal << "\nNombre: " << L.Nombre << "\nUbicacion: " << L.Ubicacion << endl;
	return out;
}

void cLocal::imprimir()
{
	cout << this;
}
