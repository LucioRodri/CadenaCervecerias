#include "cMesas.h"

cMesas::cMesas(bool limpio)
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
