#ifndef NODOAVL_H
#define NODOAVL_H

#include "Puntero.h"
#include "Comparador.h"

template <class T>
class NodoAVL
{
private:
	T _dato;
	Puntero<NodoAVL<T>> _izq;
	Puntero<NodoAVL<T>> _der;
	int _height;

public:

	//Getters
	const T& GetDato() const;
	Puntero<NodoAVL<T>>& GetIzq();
	Puntero<NodoAVL<T>>& GetDer();
	int GetHeight() const;

	//Setters
	void SetHeight(const int h);
	void SetDato(const T &dato);
	void SetIzq(const Puntero<NodoAVL<T>> &izq);
	void SetDer(const Puntero<NodoAVL<T>> &der);

};

#include "NodoAVL.cpp"
#endif