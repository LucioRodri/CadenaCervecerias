#include "PuntoDeVenta.h"

PuntoDeVenta::PuntoDeVenta(tm* fecha, string nombre, string ubicacion, float litros, unsigned monto):cLocal(fecha, nombre, ubicacion, litros, monto)
{
}

PuntoDeVenta::~PuntoDeVenta()
{
}

void PuntoDeVenta::SimularCliente()
{
	int cant_clientes = random(1, 10);
	int tipo_cerveza;
	for (int i = 0; i < cant_clientes; i++) {
		tipo_cerveza = random(0, listaCervezas->getCA());
		SumarMontoyLitros(listaCervezas->getItem(tipo_cerveza));
	}
	ActualizarSuministros();
}
