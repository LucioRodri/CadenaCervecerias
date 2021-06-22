#include "Funciones.h"

int random(int limite_inferior, int limite_superior)
{
    int random = rand() % limite_superior + limite_inferior;
    return random;
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