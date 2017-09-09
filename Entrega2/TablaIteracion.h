#pragma once
#include "Iteracion.h"
#include "HashAbiertoImpl.h"

template <class K, class V>
class TablaIteracion : public Iteracion<Tupla<K,V>>
{
private:
	nat posicion;
	Puntero<Tabla<K, V>> tabla;
	const HashAbiertoImpl<K, V> hashAbierto;

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
	int prox = this->posicion +1;

	while (hashAbierto.table[prox]!=nullptr)
	{
		prox++;
	}

}

#include "TablaIteracion.cpp"
