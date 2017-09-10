#pragma once
#include "Iteracion.h"
#include "HashAbiertoImpl.h"

template <class K, class V>
class TablaIteracion : public Iteracion<Tupla<K,V>>
{
private:
	Tupla<nat, nat> posicion;
	const HashAbiertoImpl<K, V> &hashAbierto;

	Puntero<ListaOrd<nat>> cubetas;
	Iterador<nat> iteradorCubeta;
	int proxima_cubeta() const;
public:

	~TablaIteracion(){}
	TablaIteracion(const HashAbiertoImpl<K,V> &abierto);
	bool HayElemento() const override;
	const Tupla<K, V>& ElementoActual() const override;
	void Avanzar() override;
	void Reiniciar() override;

	
	Puntero<Iteracion<Tupla<K, V>>> Clonar() const { return nullptr; }
	
};

template <class K, class V>
int TablaIteracion<K, V>::proxima_cubeta() const
{
	return - 1;

}

#include "TablaIteracion.cpp"
