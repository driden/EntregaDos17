#pragma once

#include "Tabla.h"
#include "ListaEncadenadaImp.h"
#include "Array.h"
#include "FuncionHash.h"

template <class K, class V>
class HashAbiertoImpl : Tabla<K,V>
{
private:
	Array<Puntero<ListaOrd<Tupla<K, V>>>> table;
	Puntero<FuncionHash<K>> func;
	nat tope;

	const nat siguiente_primo(const nat num);

public:
	HashAbiertoImpl(Puntero<FuncionHash<K>>, nat cantidadRegistros);
	~HashAbiertoImpl() {}

	/* CONSTRUCTORAS */

	//PRE: T(c) no está definida y la tabla no está llena
	//POS: Define T(c) = v
	void Agregar(const C& c, const V& v) override;

	//PRE: T(c) está definida
	//POS: Borra la asociación ligada a 'c'
	void Borrar(const C& c) override;

	//PRE: - 
	//POS: Borra todas las asociaciones
	void BorrarTodos() override;

	/* PREDICADOS */

	//PRE: - 
	//POS: Retorna true si está vacía, false sino.
	bool EstaVacia() const override;

	//PRE: - 
	//POS: Retorna true si está llena, false sino.
	bool EstaLlena() const override;

	//PRE: - 
	//POS: Retorna true si T(c) está definida, es decir, si la clave c está definida. False sino.
	bool EstaDefinida(const C& c) const override;

	/* SELECTORAS */

	//PRE: T(c) está definida
	//POS: Retorna 'v', tal que T(c) = v
	const V& Obtener(const C& c) const override;

	//PRE: -
	//POS: Retorna el largo de la tabla
	nat Largo() const override;

	//PRE: -
	//POS: Devuelve un clon de la tabla, no comparten memoria
	Puntero<Tabla<C, V>> Clonar() const override;

	// PRE: -
	// POS: Devuelve un iterador de las tuplas de la tabla
	Iterador<Tupla<C, V>> ObtenerIterador() const override;
};
#include "HashAbiertoImpl.cpp"
