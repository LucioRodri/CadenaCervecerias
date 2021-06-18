#include "cVendedor.h"

cVendedor::cVendedor(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas):cEmpleado(cuit, hora_entrada, hora_salida,local, horas_trabajadas)
{
	this->AniosAntiguedad = 2;
}
unsigned int cVendedor::SalarioPorHora = 1000;
cVendedor::~cVendedor()
{

}
ostream& operator<<(ostream& out, cVendedor& V)
{
	out<<(cEmpleado&)V;
	out<<V.AniosAntiguedad<<endl;
	return out;
}
istream& operator>>(istream& in, cVendedor& V)
{
	unsigned int Anios;
	in >> (cEmpleado&)V;
	cout << "Ingrese anios de antiguedad: ";
	in >> Anios;
	V.AniosAntiguedad = Anios;
	return in;
}