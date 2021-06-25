#include "cEmpleado.h"

cEmpleado::cEmpleado(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas, string Nombre):CUIT(cuit)
{
	this->HoraEntrada = hora_entrada;
	this->HoraSalida = hora_salida;
	this->HorasTrabajadas = horas_trabajadas;
	this->local_actual = local;
	this->Nombre = Nombre;
	this->Presente = false;
}
 
cEmpleado::~cEmpleado()
{

}

void cEmpleado::CalcularHorasTrabajadas()//Le pago por hora, no tengo en cuenta los minutos
{
	if(*HoraEntrada == *HoraSalida)//Ocurre en el mismo año
	{
		if (HoraEntrada->tm_mon == HoraSalida->tm_mon)//En el mismo mes
		{
			if (HoraEntrada->tm_mday == HoraSalida->tm_mday)//Entro y salio el mismo dia
				HorasTrabajadas += HoraSalida->tm_hour - HoraEntrada->tm_hour;
			else if(HoraEntrada->tm_mday == HoraSalida->tm_mday+1)//Salio al dia siguiente
			{
				HorasTrabajadas += 24 - HoraEntrada->tm_hour + HoraSalida->tm_hour;
			}
		}
		else if (HoraEntrada->tm_mon + 1 == HoraSalida->tm_mon)//Cambio el mes mientras trabajaba
		{
			if (HoraSalida->tm_mday == 1)//Unica posibilidad logica
				HorasTrabajadas += 24 - HoraEntrada->tm_hour + HoraSalida->tm_hour;
			else
				throw new exception("Esta intentando enganiar al sistema o hay que denunciar a alguien");//Fijarse si dejo la excepcion o la reemplazo con otra cosa
		}
		else
			throw new exception("Esta intentando enganiar al sistema o hay que denunciar a alguien");
	}
	else if(*HoraEntrada != *HoraSalida)
	{
		if(HoraSalida->tm_mon==0 &&HoraSalida->tm_mday==1)//Unica posibilidad real
			HorasTrabajadas += 24 - HoraEntrada->tm_hour + HoraSalida->tm_hour;
		else
			throw new exception("Esta intentando enganiar al sistema o hay que denunciar a alguien");//Fijarse si dejo la excepcion o la reemplazo con otra cosa
	}
	
		

}

void cEmpleado::Cobrar()
{
	this->HorasTrabajadas = 0;
}


ostream& operator<<(ostream& out, cEmpleado& M)
{
	out << "\nCuit: " + M.CUIT + "\nHoras trabajadas: " + std::to_string(M.HorasTrabajadas);
	return out;
}

istream& operator>>(istream& in, cEmpleado& M)
{
	// TODO: insert return statement here
	string nombre;
	cout << "\nIngrese su nombre: " << endl;
	in >> nombre;
	M.Nombre = nombre;
	return in;
}

/*int& operator=(const int& hora)
{
	this->setEntrada(hora);
	return hora;
}

bool operator==(tm& T1, tm& T2)
{
	bool Algo = T1.tm_year == T2.tm_year;
	return Algo;
}
bool operator!=(tm& T1, tm& T2)
{
	bool Algo = T1.tm_year != T2.tm_year;
	return Algo;
}

bool operator<(tm& derecha, tm& izquierda)
{
	if (izquierda.tm_year < derecha.tm_year)
		return true;
	else if (izquierda.tm_year == derecha.tm_year && izquierda.tm_mon < derecha.tm_mon)
		return true;
	else if (izquierda.tm_year == derecha.tm_year && izquierda.tm_mon == derecha.tm_mon && izquierda.tm_mday < derecha.tm_mday)
		return true;
	else 
		return false;
}

bool operator>(tm& derecha, tm& izquierda)
{
	if (izquierda.tm_year > derecha.tm_year)
		return true;
	else if (izquierda.tm_year == derecha.tm_year && izquierda.tm_mon > derecha.tm_mon)
		return true;
	else if (izquierda.tm_year == derecha.tm_year && izquierda.tm_mon == derecha.tm_mon && izquierda.tm_mday > derecha.tm_mday)
		return true;
	else
		return false;
}
*/