#ifndef AVL_H
#define AVL_H

//#include "Iterable.h"

template <class T>
class AVL // :public  Iterable<T> 
{
public:

	virtual ~AVL() { }

	/**** Constructoras ****/
	// construye el AVL vacío
	virtual void Vacio() abstract;
	/* construye un AVL con x insertado en la posición correcta */	
	virtual void Insertar(const T &x) abstract;

	/**** Predicado ****/
	// retorna true si el árbol es vacío
	virtual bool EsVacio() const abstract; 

	/**** Selectoras y otras ****/
	/* pre : el árbol no es vacío
     * post: retorna la raíz del árbol */
	virtual const T& Raiz() const abstract;
	/* pre : el árbol no es vacío
     * post: retorna el máximo elemento del AVL */
	virtual const T& Maximo() const abstract;
	/* pre : el árbol no es vacío
     * post: retorna el mínimo elemento del AVL */
	virtual const T& Minimo() const abstract;
	// retorna true si x está en el árbol
	virtual bool Existe(const T &x) const abstract; 
	/* pre: no posee (la asumimos total)
 	 * post: retorna el AVL del que se ha borrado el elemento con clave x (si está). */
	virtual void Borrar (const T &x) abstract;
	/* pre : el elemento está presente en el árbol
     * post: retorna el elemento */
	virtual const T& Recuperar(const T&) const abstract;

	virtual void Imprimir() abstract;
};
#endif