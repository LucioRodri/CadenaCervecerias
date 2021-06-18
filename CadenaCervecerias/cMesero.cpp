#include "cMesero.h"

cMesero::cMesero(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas):cEmpleado(cuit, hora_entrada, hora_salida, local,horas_trabajadas)
{
	this->Apodo = "Capi";
}
unsigned int cMesero::SalarioPorHora = 500;
cMesero::~cMesero()
{
}
void cMesero::LimpiarMesa(cMesas* mesa)
{
	if(mesa->getLimpio()==false)
		mesa->LimpiarMesa();
}
ostream& operator<<(ostream& out, cMesero& M)
{
	out << (cEmpleado&)M;
	out<<M.Apodo<<endl;
	return out;
}

istream& operator>>(istream& in, cMesero& M)
{
	// TODO: insert return statement here
	string apodo;
	in >> (cEmpleado&)M;
	cout << "\nIngrese su apodo: " << endl;
	in >> apodo;
	M.Apodo = apodo;
	return in;
}
