#include "Bar.h"
#include "cMesero.h"
#define NMAX 50
Bar::Bar(tm* fecha, string nombre, string ubicacion, float litros , unsigned monto):cLocal(fecha,nombre,ubicacion,litros,monto)
{
	this->Mesas = new cListaMesas(NMAX);
}

Bar::~Bar()
{
	delete Mesas;
}


void Bar::DistribuirEnMesas(unsigned int cant_grupos)
{
	if (Mesas->getCA() < cant_grupos)
		throw new exception("No hay mesas suficientes");
	for(int i=0;i<cant_grupos;i++)
	{
		Mesas->getItem(i)->EnsuciarMesa();
	}
}

void Bar::SimularCliente()
{
	int cant_grupos=random(1, Mesas->getCA());
	try
	{
		this->DistribuirEnMesas(cant_grupos);
	}
	catch(exception* error)
	{
		cout<<error->what()<<endl;//Borrar despues.Solo sirve para buscar errores, no tiene ninguna utilidad en el programa 
		delete error;
	}
	unsigned int ClientesXGrupo;
	unsigned int TipoCerveza;
	for(int i=0;i<cant_grupos;i++)
	{
		ClientesXGrupo = random(2, 6);
		for(int j=0;j<ClientesXGrupo;j++)
		{
			TipoCerveza = random(0, listaCervezas->getCA());
			SumarMontoyLitros(listaCervezas->getItem(TipoCerveza));
		}
	}
	ActualizarSuministros();
}

void Bar::VerificarMesas()
{
	int i;
	cMesero* mesero = NULL;
	for(i=0;i<listaEmpleados->getCA();i++)
	{
		mesero=dynamic_cast<cMesero*>(listaEmpleados->getItem(i));
		if(mesero!=NULL && mesero->getPresente())
			break;
		else
		{
			mesero = NULL;
		}
	}
	if (mesero == NULL)
		throw new exception("No hay meseros trabajando");
	for (i = 0; i < Mesas->getCA(); i++)
		mesero->LimpiarMesa(Mesas->getItem(i));
}

