
#include <string>

using namespace std;
class cCerveza
{
	friend class cLocal;
	unsigned int CantidadBarriles;
	float CantidadLitros;
	unsigned int PrecioJarra;
	string Tipo;
public:
	cCerveza(unsigned int barriles, unsigned int precio, string tipo) { CantidadBarriles = barriles, CantidadLitros = 20*barriles, PrecioJarra = precio, Tipo = tipo; };
	~cCerveza() {};
	void setBarriles(unsigned int cantidad) { CantidadBarriles += cantidad; };
	unsigned int getCantBarriles() { return CantidadBarriles; };
	unsigned int getPrecioJarra()  {  return PrecioJarra;  };
	string getclave() { return Tipo; };
	void ConsumirBarriles() { CantidadBarriles = (unsigned int)CantidadLitros % 20 + 1; };
	void ConsumirJarra() { CantidadLitros -= 0.5; };
};