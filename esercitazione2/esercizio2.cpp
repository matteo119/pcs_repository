#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
//inizializzazione dell'array e di variabili
	static const int N = 10;
	double arr[N] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	double somma = arr[0], minimo = arr[0], massimo = arr[0], media, dff_qd = 0;

//calcolo della somma
	for(int i = 1; i<N ;i++) {
	somma += arr[i];

/*altri modi per trovare max,min
-->	if (arr[i] > massimo) {
		massimo = arr[i];
		}
	if (arr[i] < minimo) {
		minimo = arr[i];
		}
-->	massimo = std::max(arr[i],massimo); (in cmath si chiama fmax)
	minimo = std::min(arr[i],minimo);   (in cmath si chiama fmin)
*/
	}
	media = somma/N;
	massimo = *(std::max_element(&arr[0],&arr[N]));
	minimo = *(std::min_element(&arr[0],&arr[N]));

//calcolo della deviazione standard
	for(int i = 0; i<N ;i++) {
		dff_qd += (arr[i]-media)*(arr[i]-media);
	}
	double dev_st = std::sqrt(dff_qd/N);

//stampa
	std::cout << "Minimo: " << minimo << "\n";
	std::cout << "Massimo: " << massimo << "\n";
	std::cout << "Media: " << media << "\n";
	std::cout << "Deviazione standard: " << dev_st << "\n";

	return 0;
}