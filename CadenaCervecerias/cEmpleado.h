#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime>
#include <iostream>
#include "Funciones.h"

using namespace std;
class cLocal;
class cEmpleado
{
protected:
	const string CUIT;//Atributo constante
	string Nombre;
	tm* HoraEntrada;
	tm* HoraSalida;
	unsigned int HorasTrabajadas;
	cLocal* local_actual=NULL;
	bool Presente;
public:
	cEmpleado(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas = 0, string Nombre = "Pepepo");
	virtual ~cEmpleado();
	void setEntrada(tm* hora) { HoraEntrada = hora; Presente = true; };
	void setSalida(tm* hora) { HoraSalida = hora; Presente = false; };
	string getclave() { return CUIT; };
	void CalcularHorasTrabajadas();
	void Cobrar();//Resetea HorasTrabajadas cuando inicia el mes
	bool getPresente() { return Presente; };
	friend ostream& operator<<(ostream& out, cEmpleado& M);//Friend. Sobrecarga del padre
	friend istream& operator>>(istream& in, cEmpleado& M);
	//friend int& operator=(const int& hora);
};
//bool operator==(tm& T1, tm& T2);
//bool operator!=(tm& T1, tm& T2);
//bool operator<(tm& derecha, tm& izquierda);
//bool operator>(tm& derecha, tm& izquierda);
