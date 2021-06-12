#include "cMesas.h"

cMesas::cMesas(unsigned int cantidad, bool limpio) : Capacidad(cantidad)
{
	Limpio = limpio;
}

cMesas::~cMesas()
{
}

void cMesas::LimpiarMesa()
{
	Limpio = true;
}

void cMesas::EnsuciarMesa()
{
	if (Limpio)
		Limpio = false;
}
