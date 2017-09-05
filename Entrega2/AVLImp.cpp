#ifndef AVLIMP_CPP
#define AVLIMP_CPP

#include <algorithm> //max
#include <iomanip>   
#include "AVLImp.h"


using namespace std;

template <class T>
void AVLImp<T> ::Vacio() {
	_root = NULL;
}

template <class T>
void AVLImp<T>::Insertar(const T &x) {
	if (_root != NULL) {
		Insertar(x, _comparador, _root);

	}
	else {
		_root = new NodoAVL<T>();
		_root->SetDato(x);
		_root->SetIzq(NULL);
		_root->SetDer(NULL);
		_root->SetHeight(0);
	}
}

template<class T>
void AVLImp<T> ::Insertar(const T &x, const Puntero<Comparador<T>> &cmp, Puntero<NodoAVL<T>> &root)
{
	if (root == NULL)
	{
		root = new NodoAVL<T>();
		root->SetDato(x);
		root->SetIzq(NULL);
		root->SetDer(NULL);
		root->SetHeight(0);
	}
	else if (cmp->EsMenor(x, root->GetDato()))
	{
		Insertar(x, cmp, root->GetIzq());
		if (GetHeight(root->GetIzq()) - GetHeight(root->GetDer()) == 2)
		{
			if (cmp->EsMenor(x, root->GetIzq()->GetDato()))
			{
				RotacionSimpleIzq(root); // right rotation
			}
			else
			{
				RotacionDobleIzq(root); //left-right rotation
			}
		}
	}
	else if (cmp->EsMayor(x, root->GetDato()))
	{
		Insertar(x, cmp, root->GetDer());
		if (GetHeight(root->GetIzq()) - GetHeight(root->GetDer()) == 2)
		{
			if (cmp->EsMenor(x, root->GetDer()->GetDato()))
			{
				RotacionSimpleDer(root);
			}
			else
			{
				RotacionDobleDer(root);
			}
		}
	}
	root->SetHeight(max(GetHeight(root->GetDer()), GetHeight(root->GetIzq())) + 1);
}

template<class T>
void AVLImp<T> ::RotacionSimpleIzq(Puntero<NodoAVL<T>> &root)
{
	if (root != NULL) {
		Puntero<NodoAVL<T>>  k1 = root->GetIzq();
		if (k1 != NULL)
		{
			root->GetIzq() = k1->GetDer();
			k1->GetDer() = root;
			root->SetHeight(max(GetHeight(root->GetIzq()), GetHeight(root->GetDer())) + 1);
			k1->SetHeight(max(GetHeight(k1->GetIzq()), GetHeight(k1->GetDer())) + 1);
			//faltaba terminar de enganchar el arbol!
			root = k1;

		}
	}
}

template<class T>
void AVLImp<T> ::RotacionSimpleDer(Puntero<NodoAVL<T>> &root)
{
	if (root != NULL) {
		Puntero<NodoAVL<T>> k2 = root->GetDer();
		if (k2 != NULL) {
			root->GetDer() = k2->GetIzq();
			k2->GetIzq() = root;
			root->SetHeight(max(GetHeight(root->GetIzq()), GetHeight(root->GetDer())) + 1);
			k2->SetHeight(max(GetHeight(k2->GetIzq()), GetHeight(k2->GetDer())) + 1);
			//faltaba terminar de enganchar el arbol!
			root = k2;
		}
	}
}

template<class T>
void AVLImp<T> ::RotacionDobleIzq(Puntero <NodoAVL<T>> &root)
{
	RotacionSimpleDer(root->GetIzq());
	RotacionSimpleIzq(root);
}

template<class T>
void AVLImp<T> ::RotacionDobleDer(Puntero <NodoAVL<T>> &root)
{
	RotacionSimpleIzq(root->GetDer());
	RotacionSimpleDer(root);
}
template<class T>
int AVLImp<T>::GetHeight(Puntero<NodoAVL<T>> nodo) const {
	return (nodo == NULL) ? -1 : nodo->GetHeight();
}

template <class T>
Puntero<Comparador<T>> AVLImp<T>::GetComparador() const {
	return _comparador;
}
template <class T>
void AVLImp<T>::SetComparador(const Puntero<Comparador<T>> &cmp) {
	_comparador = cmp;
}
/**** Predicado ****/
// retorna true si el árbol es vacío
template<class T>
bool AVLImp<T>::EsVacio() const {
	return _root == NULL;
}

template<class T>
const T& AVLImp<T>::Raiz() const {
	return _root->GetDato();
}

template<class T>
const T& AVLImp<T>::Maximo() const {
	Maximo(_root);
}
//const T& GetDato() const;
//Puntero<NodoAVL<T>>& GetIzq();
//Puntero<NodoAVL<T>>& GetDer();
template<class T>
const T& AVLImp<T>::Maximo(const Puntero<NodoAVL<T>> avl) const{

	if ((avl != NULL) && (avl->GetDer() != NULL)) {
		return avl->GetDato();
	}
	else if (avl != NULL) {
		return Maximo(avl->GetDer());
	}
}

template<class T>
const T& AVLImp<T>::Minimo() const {
	return Raiz();
}

template<class T>
bool AVLImp<T>::Existe(const T &x) const {
	return true;
}

template<class T>
void AVLImp<T>::Borrar(const T &x) {}

template<class T>
const T& AVLImp<T>::Recuperar(const T&) const {
	return Raiz();
}


template<class T>
void AVLImp<T>::Imprimir() {
	postorder(_root);
}

template <class T>
void AVLImp<T>::postorder(Puntero<NodoAVL<T>> p, int indent = 0)
{
	if (p != NULL) {
		if (p->GetIzq()) postorder(p->GetIzq(), indent + 4);
		if (p->GetDer()) postorder(p->GetDer(), indent + 4);
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		cout << p->GetDato() << "\n ";
	}
}
#endif // !AVLIMP_CPP