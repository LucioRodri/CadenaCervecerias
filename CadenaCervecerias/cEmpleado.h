#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#pragma once
using namespace std;
class cEmpleado
{
protected:
	string CUIT;
	tm* HoraEntrada;
	tm* HoraSalida;
	unsigned int HorasTrabajadas;
public:
	cEmpleado();
	~cEmpleado();
	void CalcularHorasTrabajadas();
};

