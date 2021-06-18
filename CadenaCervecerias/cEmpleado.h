#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include <iostream>
#pragma once
using namespace std;
class cLocal;
class cEmpleado
{
protected:
	string CUIT;
	tm* HoraEntrada;
	tm* HoraSalida;
	unsigned int HorasTrabajadas;
	cLocal* local_actual=NULL;
	bool Presente;
public:
	cEmpleado(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0);
	virtual ~cEmpleado();
	void setEntrada(tm* hora) { HoraEntrada = hora; Presente = true; };
	void setSalida(tm* hora) { HoraSalida = hora; Presente = false; };
	string getclave() { return CUIT; };
	void CalcularHorasTrabajadas();
	void Cobrar();//Resetea HorasTrabajadas cuando inicia el mes
	bool getPresente() { return Presente; };
	friend ostream& operator<<(ostream& out, cEmpleado& M);
	friend istream& operator>>(istream& in, cEmpleado& M);
};

