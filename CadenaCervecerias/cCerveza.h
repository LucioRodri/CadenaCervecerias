
#include <string>
using namespace std;
class cCerveza
{
	unsigned int CantidadBarriles;
	float CantidadLitros;
	unsigned int PrecioJarra;
	string Tipo;
	friend class cLocal;
public:
	cCerveza(unsigned int barriles, float litros, unsigned int precio, string tipo) { CantidadBarriles = barriles, CantidadLitros = litros, PrecioJarra = precio, Tipo = tipo; };
	~cCerveza() {};
};