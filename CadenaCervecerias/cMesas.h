#pragma once
using namespace std;
class cMesas
{
	bool Limpio;
public:
	cMesas(bool limpio = true);
	~cMesas();
	bool getLimpio() { return Limpio; };
	void LimpiarMesa();
	void EnsuciarMesa();
};

