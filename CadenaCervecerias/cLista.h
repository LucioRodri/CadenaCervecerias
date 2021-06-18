#pragma once
#define NMAX 20
#include <string>
#include <iostream>
using namespace std;
template<class T>
class cLista
{
protected:
	T** vector;
	unsigned int CA, TAM;
	bool eliminar_lista;

public:
	cLista(unsigned int TAM = NMAX, bool eliminar_lista = true);
	~cLista();

	bool AgregarItem(T* item);
	void operator+(T* item);

	T* Quitar(string clave);
	T* QuitarenPos(unsigned int pos);

	void Eliminar(string clave);
	void operator-(string clave);

	void Eliminar(unsigned int pos) {

		T* dato = NULL;
		try {
			dato = QuitarenPos(pos);
		}
		catch(exception* error)
		{
			throw error;
		}

		if (dato != NULL)
			delete dato;
	}

	void Listar();
	T* BuscarItem(string clave);
	T* operator [](unsigned int pos);
	T* getItem(unsigned int pos);
	string To_String();

	void Redimensionalizar();
	unsigned int getItemPos(string clave);
	unsigned int getCA();
	unsigned int getTAM();
	//friend ostream& operator<<(ostream& os, const cListaT<T>& Lista);
};

template<class T>
unsigned int cLista<T>::getTAM()
{
	return TAM;
}

template<class T>
unsigned int cLista<T>::getCA()
{
	return CA;
}

template<class T>
void cLista<T>::Redimensionalizar()
{
	//defino nuevo tamaño
	TAM += 10;
	//creo nuevo vector auxiliar
	T** aux = new T * [TAM];

	//copio los datos al nuevo vector y pongo el resto en NULL
	for (int i = 0; i < TAM; i++)
	{
		if (i < CA)
			aux[i] = vector[i];
		else
			aux[i] = NULL;
	}

	//borro el vector anterior
	delete[] vector;

	//guardo mi nuevo vector
	vector = aux;

}

template<class T>
cLista<T>::cLista(unsigned int TAM, bool eliminar_lista)
{
	vector = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++)
		vector[i] = NULL;

	this->TAM = TAM;
	this->eliminar_lista = eliminar_lista;
	CA = 0;
}

template<class T>
cLista<T>::~cLista()
{
	if (vector != NULL)
	{
		if (eliminar_lista) {
			for (unsigned int i = 0; i < CA; i++)
			{
				if (vector[i] != NULL)
					delete vector[i];
			}
		}
		delete[] vector;
	}
}

template<class T>
void cLista<T>::Listar()
{
	for (unsigned int i = 0; i < CA; i++)
		vector[i]->Imprimir();// imprimir
}

template<class T>
bool cLista<T>::AgregarItem(T* item)
{
	T* i_f = BuscarItem(item->getclave());
	if (i_f != NULL)
		throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		vector[CA++] = item;
	else
		throw new exception("No hay tamaño suficiente para agregar el item");
	return true;
}


template<class T>
T* cLista<T>::Quitar(string clave)
{
	unsigned int pos;
	try{
	pos= getItemPos(clave);
	}
	catch(exception* error)
	{
		throw error;
	}
	T* aux = NULL;

	try {
		aux = QuitarenPos(pos);
	}
	catch (exception* error) {
		throw error;
	}
	return aux;
}

template<class T>
T* cLista<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA || pos < 0)
		throw new exception("Posicion invalida");

	T* aux = vector[pos];

	for (unsigned int i = pos; i < CA - 1; i++)
		vector[i] = vector[i + 1];

	vector[CA - 1] = NULL;
	CA--;

	return aux;
}


template<class T>
void cLista<T>::Eliminar(string clave) {
	try {
		unsigned int pos = getItemPos(clave);
		Eliminar(pos);
	}
	catch (exception* error) {
		throw error;
	}
}


template<class T>
T* cLista<T>::BuscarItem(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)
			return vector[i];
	}
	return NULL;
}

template<class T>
T* cLista<T>::getItem(unsigned int pos)
{
	if (pos < CA && pos >= 0)
		return vector[pos];
	else
		throw new exception("Posición inválida");
}

template<class T>
string cLista<T>::To_String()
{
	string Total;
	for (unsigned int i = 0; i < CA; i++)
	{
		Total += vector[i]->To_string();// imprimir
	}
	return Total;
}

template<class T>
unsigned int cLista<T>::getItemPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)
			return i;
	}
	return -1;
}


template <class T>
void cLista<T>::operator+(T* item)
{
	AgregarItem(item);
}

template<class T>
inline T* cLista<T>::operator[](unsigned int pos)
{
	if (pos < CA)
		return vector[pos];
	return NULL;
}

template<class T>
void cLista<T>::operator-(string clave)
{
	Eliminar(clave);
}

template <class T>
ostream& operator<<(ostream& os, cLista<T>& Lista)
{
	os << Lista.To_String() << endl;
	return os;
}