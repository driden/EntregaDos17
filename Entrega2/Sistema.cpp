
#ifndef SISTEMA_CPP
#define SISTEMA_CPP
#include "Sistema.h"

template <class T>
void MergeSort(Array<T> &arr, int low, int high, Comparador<T> comp)
{
	if (low >= high)
		return;
	else {
		int mid = (low + high) / 2;
		MergeSort(arr, low, mid, comp);
		MergeSort(arr, mid + 1, high, comp);
		Merge(arr, low, mid, mid + 1, high, comp);
	}
}

template <class T>
void Merge(Array<T> &arr, int left_low, int left_high, int right_low, int right_high, Comparador<T> comp)
{
	int length = right_high - left_low + 1;
	Array<T> temp(length);
	int left = left_low;
	int right = right_low;

	for (int i = 0; i < length; ++i) {

		if (left > left_high)
			temp[i] = arr[right++];

		else if (right > right_high)
			temp[i] = arr[left++];

		else if (comp.EsMenor(arr[left], arr[right]) || comp.SonIguales(arr[left], arr[right]))
			temp[i] = arr[left++];

		else
			temp[i] = arr[right++];
	}

	for (int i = 0; i < length; ++i)
		arr[left_low++] = temp[i];
}

Cadena OrdenarCadena(Cadena c)
{
	Array<char> letras(c.Largo);
	for (nat i = 0; i < letras.Largo; i++)
		letras[i] = c[i];
	Comparador<char> comp = Comparador<char>::Default;
	MergeSort(letras, 0, letras.Largo - 1, comp);

	string palabra = "";
	for (nat i = 0; i < letras.Largo; i++)
		palabra += letras[i];


	return Cadena(palabra.c_str());
}

Sistema::Sistema(const Cadena& nombreArchivoDiccionario)
{	
	// Inicialización de estructuras necesrias para resolver el problema.
	hash = new HashAbiertoImpl<Cadena, Cadena>(new CadenaFuncionHash(), 85000, Comparador<Cadena>::Default);
	
	// Vueltas para manejar que el input sea una Cadena
	string nombre ="";
	for (nat i = 0; i < nombreArchivoDiccionario.Largo; i++)
		nombre += nombreArchivoDiccionario[i];
	
	//leer el archivo y llenar el hash
	string line;
	ifstream miarchivo(nombre);
	
	if (miarchivo.is_open()) {

		while (getline(miarchivo, line)) {

			std::transform(line.begin(), line.end(), line.begin(), ::tolower);

			Cadena original(line.c_str());
			Cadena ordenada = OrdenarCadena(original);


			hash->Agregar(ordenada, original);

		}

		miarchivo.close();
	}
}

Cadena Sanitizar(Cadena cadena)
{
	// á, é, í, ó, ú
	return "";
	
}
Sistema::~Sistema()
{
}

// Ejercicio 1: Anagramas
Array<Cadena> Sistema::Anagramas(const Cadena& c)
{
	Cadena ordenada = OrdenarCadena(c);

	Iterador<Tupla<Cadena, Cadena>> iter = hash->ObtenerIterador();

	Comparador<Cadena> comp = Comparador<Cadena>::Default;

	Puntero<ListaOrd<Cadena>> lista = new ListaEncadenadaImp<Cadena>(comp);

	while (iter.HayElemento())
		if (comp.SonIguales(iter.ElementoActual().Dato1, ordenada))
			lista->InsertarOrdenado(iter.ElementoActual().Dato2);

	Array<Cadena> anagramas(lista->Largo());
	for (nat n = 0; n < anagramas.Largo; n++)
		anagramas[n] = lista->Obtener(n);
	
	return anagramas;
}
#endif