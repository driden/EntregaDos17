#ifndef NODOAVL_CPP
#define NODOAVL_CPP
#include "NodoAVL.h"

//Getters
template <class T>
const T& NodoAVL<T>::GetDato() const{
	return _dato;
}
template <class T>
Puntero<NodoAVL<T>>& NodoAVL<T>::GetIzq(){
	return _izq;
}
template <class T>
Puntero<NodoAVL<T>>& NodoAVL<T>::GetDer(){
	return _der;
}
template <class T>
int NodoAVL<T>::GetHeight() const{
	return _height;
}

//Setters
template <class T>
void NodoAVL<T>::SetHeight(const int h){
	_height = h;
}
template <class T>
void NodoAVL<T>::SetDato(const T &dato){
	_dato = dato;
}
template <class T>
void NodoAVL<T>::SetIzq(const Puntero<NodoAVL<T>> &izq){
	_izq = izq;
}
template <class T>
void NodoAVL<T>::SetDer(const Puntero<NodoAVL<T>> &der){
	_der = der;
}
#endif // !NODOAVL_CPP