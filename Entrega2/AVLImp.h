#ifndef AVLIMP_H
#define AVLIMP_H

#include "Comparador.h"
#include "AVL.h"
#include "NodoAVL.h"

template <class T>
class AVLImp : public AVL<T>
{
private:
	Puntero<NodoAVL<T>> _root;
	Puntero<Comparador<T>> _comparador;
public:
	/**** Constructoras ****/
	AVLImp<T>(){
		_root = NULL;
	};
	AVLImp<T>(const Puntero<Comparador<T>> cmp){
		_root = NULL;
		_comparador = cmp;
	}
	// construye el AVL vacío
	void Vacio();
	/* construye un AVL con x insertado en la posición correcta */
	void Insertar(const T &x);

	/**** Predicado ****/
	// retorna true si el árbol es vacío
	bool EsVacio() const;

	/**** Selectoras y otras ****/
	/* pre : el árbol no es vacío
	* post: retorna la raíz del árbol */
	const T& Raiz() const;
	/* pre : el árbol no es vacío
	* post: retorna el máximo elemento del AVL */
	const T& Maximo() const;
	const T& Maximo(const Puntero<NodoAVL<T>> avl) const;
	/* pre : el árbol no es vacío
	* post: retorna el mínimo elemento del AVL */
	const T& Minimo() const;
	// retorna true si x está en el árbol
	bool Existe(const T &x) const;
	/* pre: no posee (la asumimos total)
	* post: retorna el AVL del que se ha borrado el elemento con clave x (si está). */
	void Borrar(const T &x);
	/* pre : el elemento está presente en el árbol
	* post: retorna el elemento */
	const T& Recuperar(const T&) const;
	//Funciones extra
	void Insertar(const T &x, const Puntero<Comparador<T>> &cmp, Puntero<NodoAVL<T>> &root);
	void RotacionSimpleIzq(Puntero<NodoAVL<T>> &root);
	void RotacionSimpleDer(Puntero<NodoAVL<T>> &root);
	void RotacionDobleIzq(Puntero <NodoAVL<T>> &root);
	void RotacionDobleDer(Puntero <NodoAVL<T>> &root);
	int GetHeight(Puntero<NodoAVL<T>> nodo) const;

	void SetComparador(const Puntero<Comparador<T>> &cmp);
	Puntero<Comparador<T>> GetComparador() const;
	virtual void Imprimir();
	void postorder(Puntero<NodoAVL<T>> p, int indent = 0);
};
#include "AVLImp.cpp"
#endif