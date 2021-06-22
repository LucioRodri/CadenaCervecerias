#include "cCerveza.h"

cCerveza& operator=(const cCerveza& C)
{
	Tipo = C.getclave();
	PrecioJarra = C.getPrecioJarra();
	CantidadLitros = C.getCantLitros();
	CantidadBarriles = C.getCantBarriles();
	return C;
}
