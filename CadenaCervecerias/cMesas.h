#pragma once
using namespace std;
class cMesas
{
	const unsigned int Capacidad;
	bool Limpio;
public:
	cMesas(unsigned int cantidad = 4, bool limpio = true);
	~cMesas();
	void LimpiarMesa();
};

