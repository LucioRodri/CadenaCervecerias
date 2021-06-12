#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include "cLocal.h"
#pragma once
using namespace std;
class cEmpleado
{
protected:
	string CUIT;
	tm* HoraEntrada;
	tm* HoraSalida;
	unsigned int HorasTrabajadas;
	cLocal* local_actual;
public:
	cEmpleado(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0);
	virtual ~cEmpleado() {};
	void setEntrada(tm* hora) {HoraEntrada = hora;};
	void setSalida(tm* hora) { HoraSalida = hora; };
	string getclave() { return CUIT; };
	void CalcularHorasTrabajadas();
	void Cobrar();//Resetea HorasTrabajadas cuando inicia el mes
};

