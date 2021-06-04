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
	cEmpleado(string cuit, tm* hora_entrada, tm* hora_salida, unsigned int horas_trabajadas = 0);
	~cEmpleado();
	void CalcularHorasTrabajadas();
};

