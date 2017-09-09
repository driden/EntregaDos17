#ifndef TABLAITERACION_H
#define TABLAITERACION_H

#include "TablaIteracion.h"

template <class K, class V>
TablaIteracion<K, V>::TablaIteracion(const HashAbiertoImpl<K, V>& abierto)
{
	this->posicion = 0;
	this->tabla = abierto;
	hashAbierto = abierto;	
}

template <class K, class V>
bool TablaIteracion<K, V>::HayElemento() const
{
	
	return false;
}

template <class K, class V>
const Tupla<K, V>& TablaIteracion<K, V>::ElementoActual() const
{
	return Tupla<K, V>(K(), V());
}

template <class K, class V>
void TablaIteracion<K, V>::Avanzar()
{
}

template <class K, class V>
void TablaIteracion<K, V>::Reiniciar()
{
}

#endif
