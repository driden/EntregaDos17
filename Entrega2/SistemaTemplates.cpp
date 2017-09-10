#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"
#include "HashAbiertoImpl.h"
#include "HashCerradoImpl.h"

template <class C, class V>
Puntero<Tabla<C, V>> Sistema::CrearTablaHashAbierto(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp)
{
	Puntero<Tabla<C, V>> pTabla = new HashAbiertoImpl<C, V>(fHash, cubetas, comp);
	return pTabla;
}

template <class C, class V>
Puntero<Tabla<C, V>> Sistema::CrearTablaHashCerrado(nat cubetas, Puntero<FuncionHash<C>> fHash, const Comparador<C>& comp)
{
	Puntero<Tabla<C, V>> pTabla = new HashCerradoImpl<C, V>(cubetas, fHash, comp);
	return pTabla;
}

template <class T>
bool Sistema::EsAVL(Puntero<NodoArbol<T>> raiz, const Comparador<T>& comp)
{
	return false;
}

#endif