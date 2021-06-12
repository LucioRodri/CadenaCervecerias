#include "cEmpleado.h"

cEmpleado::cEmpleado(string cuit, tm* hora_entrada, tm* hora_salida, cLocal* local, unsigned int horas_trabajadas)
{
	this->CUIT=cuit;
	this->HoraEntrada = hora_entrada;
	this->HoraSalida = hora_salida;
	this->HorasTrabajadas = horas_trabajadas;
	this->loca_actual = local;
}
 
cEmpleado::~cEmpleado()
{
}

void cEmpleado::CalcularHorasTrabajadas()//Le pago por hora, no tengo en cuenta los minutos
{
	if(HoraEntrada->tm_year == HoraSalida->tm_year)//Ocurre en el mismo año
	{
		if (HoraEntrada->tm_mon == HoraSalida->tm_mon)//En el mismo mes
		{
			if (HoraEntrada->tm_mday == HoraSalida->tm_mday)//Entro y salio el mismo dia
				HorasTrabajadas = HoraSalida->tm_hour - HoraEntrada->tm_hour;
			else//Salio al dia siguiente
			{
				HorasTrabajadas = 24 - HoraEntrada->tm_hour + HoraSalida->tm_hour;
			}
		}
		else if (HoraEntrada->tm_mon + 1 == HoraSalida->tm_mon)//Cambio el mes mientras trabajaba
		{
			if (HoraSalida->tm_mday == 1)//Unica posibilidad logica
				HorasTrabajadas = 24 - HoraEntrada->tm_hour + HoraSalida->tm_hour;
			else
				throw new exception("Esta intentando enganiar al sistema o hay que denunciar a alguien");//Fijarse si dejo la excepcion o la reemplazo con otra cosa
		}
	}
	else
	{
		if(HoraSalida->tm_mon==0 &&HoraSalida->tm_mday==1)//Unica posibilidad real
			HorasTrabajadas = 24 - HoraEntrada->tm_hour + HoraSalida->tm_hour;
		else
			throw new exception("Esta intentando enganiar al sistema o hay que denunciar a alguien");//Fijarse si dejo la excepcion o la reemplazo con otra cosa
	}
	
		

}

void cEmpleado::Cobrar()
{
	HorasTrabajadas = 0;
}
