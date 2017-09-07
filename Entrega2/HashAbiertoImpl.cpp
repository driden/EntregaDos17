#ifndef HASH_ABIERTO_IMPL_CPP_
#define HASH_ABIERTO_IMPL_CPP_

#include "HashAbiertoImpl.h"

template <class K, class V>
const nat HashAbiertoImpl<K, V>::siguiente_primo(const nat num)
{
	return 0; // hacer la funcion de primo
}

template <class K, class V>
HashAbiertoImpl<K, V>::HashAbiertoImpl(Puntero<FuncionHash<K>> f, nat cantidadRegistros)
{
	func = f;
	table = Array<Puntero<ListaOrd<Tupla<K, V>>>>(siguiente_primo(cantidadRegistros*1.7));
}


#endif