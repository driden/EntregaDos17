#include "CasoDePrueba.h"
#include "PruebaMemoria.h"
#include "ConductorPrueba.h"
#include "Sistema.h"

#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

Puntero<Sistema> Inicializar()
{
	//return new Sistema("diccionario");
	return new Sistema("D:/ORT/A2/EntregaDos17/Entrega2/listado-general.txt");

}

//template <class T>
//void MergeSort(Array<T> &arr, int low, int high, Comparador<T> comp)
//{
//	if (low >= high)
//		return;
//	else {
//		int mid = (low + high) / 2;
//		MergeSort(arr, low, mid, comp);
//		MergeSort(arr, mid + 1, high, comp);
//		Merge(arr, low, mid, mid + 1, high, comp);
//	}
//}
//template <class T>
//void Merge(Array<T> &arr, int left_low, int left_high, int right_low, int right_high, Comparador<T> comp)
//{
//	int length = right_high - left_low + 1;
//	Array<T> temp(length);
//	int left = left_low;
//	int right = right_low;
//
//	for (int i = 0; i < length; ++i) {
//
//		if (left > left_high)
//			temp[i] = arr[right++];
//
//		else if (right > right_high)
//			temp[i] = arr[left++];
//
//		else if (comp.EsMenor(arr[left], arr[right]) || comp.SonIguales(arr[left], arr[right]))
//			temp[i] = arr[left++];
//
//		else
//			temp[i] = arr[right++];
//	}
//
//	for (int i = 0; i < length; ++i)
//		arr[left_low++] = temp[i];
//}
//
//Cadena OrdenarCadena(Cadena c)
//{
//	Array<char> letras(c.Largo);
//	for (nat i = 0; i < letras.Largo; i++)
//		letras[i] = c[i];
//	Comparador<char> comp = Comparador<char>::Default;
//	MergeSort(letras, 0, letras.Largo - 1, comp);
//	
//	string palabra = "";
//	for (nat i = 0; i < letras.Largo; i++)
//		palabra+=letras[i];
//	
//	
//	return Cadena(palabra.c_str());
//}

void main()
{
	Puntero<ConductorPrueba> cp = new ConductorPrueba();
	Array<Puntero<Prueba>> pruebas = Array<Puntero<Prueba>>(3);
	pruebas[0] = new PruebaMemoria();
	pruebas[1] = new CasoDePrueba(Inicializar);
	pruebas[2] = pruebas[0];
	cp->CorrerPruebas(pruebas.ObtenerIterador());

	/*string line;
	ifstream miarchivo("diccionario.txt");
	Puntero<Tabla<Cadena, Cadena>> hash = new HashAbiertoImpl<Cadena, Cadena>(new CadenaFuncionHash(), 10, Comparador<Cadena>::Default);
	
	if (miarchivo.is_open()) {

		while (getline(miarchivo, line)) {
			
			std::transform(line.begin(), line.end(), line.begin(), ::tolower);
			
			Cadena original(line.c_str());
			Cadena ordenada = OrdenarCadena(original);		

			
			hash->Agregar(ordenada, original);
			
		}

		miarchivo.close();
	}

	Iterador<Tupla<Cadena, Cadena>> it = hash->ObtenerIterador();
	while (it.HayElemento())
	{
		std::cout << "Clave: " <<it.ElementoActual().Dato1 << " Valor: " << it.ElementoActual().Dato2 << "\n";
		it.Avanzar();
	}*/

	system("pause");
}

