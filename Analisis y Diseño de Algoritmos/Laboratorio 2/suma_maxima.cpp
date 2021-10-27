#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


// Algoritmo trivial, por fuerza bruta: evalúa los O(n^2) subarreglos, siendo n
// la cantidad de elementos del arreglo A. Al invertir tiempo O(1) en cada uno
// de ellos, la complejidad temporal resulta ser O(n^2). Por otro lado, su
// complejidad espacial es constante.
template<class T>
T maxima_suma_0(const vector<T> &A)
{
	T max = A[0], suma;
	size_t n = A.size();

	for(size_t i = 0; i < n; ++i)
	{
		suma = T();
		for(size_t j = i; j < n; ++j)
		{
			suma += A[j];
			if(suma > max)
				max = suma;
		}
	}

	return max;
}

// Función auxiliar de maxima_suma_1: computa la máxima suma de un subarreglo
// comenzando en la mitad de arreglo A y extendiéndose hacia el extremo opuesto
// de la mitad que corresponda.
template<class T>
T maximo_secuencial(const vector<T> &A, ssize_t i, ssize_t j)
{
	#define _DESDE(i,j)   ((i < j) ? (i+1) : (i-1))
	#define _HASTA(k,i,j) ((i < j) ? (k < j) : (k > j))
	#define _SIG(k,i,j)   ((i < j) ? k++ : k--)

	T suma = A[i], max = suma;
	for(ssize_t k = _DESDE(i,j); _HASTA(k,i,j); _SIG(k,i,j))
	{
		suma += A[k];
		if(suma > max)
			max = suma;
	}

	return max;
}

// Algoritmo divide & conquer de complejidad O(n log n). Su complejidad
// espacial es O(log n).
template<class T>
T maxima_suma_1(const vector<T> &A, ssize_t i=0, ssize_t j=-1)
{
	if(j == -1)
		j = A.size();
	
	if(j - i == 1)
		return A[i];

	ssize_t m = i + (j-i)/2;
	T suma_izq = maxima_suma_1(A, i, m);
	T suma_der = maxima_suma_1(A, m, j);
	T t_izq = maximo_secuencial(A, m-1, i-1);
	T t_der = maximo_secuencial(A, m, j);
	
	return max({suma_izq, suma_der, t_izq + t_der});
}

// Otro algoritmo divide & conquer que extiende y mejora el anterior mediante
// la técnica de generalización de funciones. La clave del mismo radica en
// devolver valores adicionales con el objeto de computar en tiempo O(1) el
// máximo de un subarreglo con porciones no nulas en ambas mitades de A. 
// La complejidad espacial, por otra parte, sigue siendo logarítmica.
template<class T>
T maxima_suma_2(
	const vector<T> &A,
	ssize_t i=0, ssize_t j=-1,
	// vals representa la 4-upla <s, l, r, t> en donde
	//   * s es la máxima suma de un subarreglo cualquiera de A
	//   * l es la máxima suma de un subarreglo arrancando desde el extremo
	//     izquierdo de A
	//   * r es la máxima suma de un subarreglo arrancando desde el extremo
	//     derecho de A
	//   * t es la suma total de los elementos de A
	vector<T> *vals=nullptr)
{
	if(j == -1)
		j = A.size();

	if(j - i == 1)
	{
		if(vals != nullptr)
			*vals = {A[i], A[i], A[i], A[i]};
		return A[i];
	}

	vector<T> vals_izq(4), vals_der(4);
	T suma_max;

	ssize_t m = i + (j-i)/2;
	maxima_suma_2(A, i, m, &vals_izq);
	maxima_suma_2(A, m, j, &vals_der);
	
	suma_max = max({vals_izq[0], vals_der[0], vals_izq[2] + vals_der[1]});

	if(vals != nullptr)
	{
		(*vals)[0] = suma_max;
		(*vals)[1] = max(vals_izq[1], vals_izq[3] + vals_der[1]);
		(*vals)[2] = max(vals_der[2], vals_der[3] + vals_izq[2]);
		(*vals)[3] = vals_izq[3] + vals_der[3];
	}

	return suma_max;
}

int main()
{
	vector<int> A {3, -4, 5, -1, 5, 6, 10, -9, -2, 8};

	int s0 = maxima_suma_0(A);
	int s1 = maxima_suma_1(A);
	int s2 = maxima_suma_2(A);

	cout << "A = <3, -4, 5, -1, 5, 6, 10, -9, -2, 8>" << endl;
	cout << "S_0(A) = " << s0 << endl;
	cout << "S_1(A) = " << s1 << endl;
	cout << "S_2(A) = " << s2 << endl;
	cout << endl;

	vector<int> B {-3, -4, -8, -1, -9};

	s0 = maxima_suma_0(B);
	s1 = maxima_suma_1(B);
	s2 = maxima_suma_2(B);

	cout << "B = <-3, -4, -8, -1, -9>" << endl;
	cout << "S_0(B) = " << s0 << endl;
	cout << "S_1(B) = " << s1 << endl;
	cout << "S_2(B) = " << s2 << endl;

	return 0;
}