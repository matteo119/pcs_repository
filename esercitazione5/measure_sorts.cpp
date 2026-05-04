#include <iostream>
#include <algorithm>
#include <vector>

#include "randfiller.h"
#include "sort.hpp"
#include "timecounter.h"

int main(void) {
	int lunghezza = 2;
	randfiller rf;
	int n = 100; //numero di vettori su cui fare la media
	std::cout << "\nConfronto su vettori di dimensione crescente\n\n";
	for (int l=2; l<14; l++){
		lunghezza *= 2;
		std::cout << "Lunghezza vettore: " << lunghezza << "\n";
		std::vector<std::vector<double>> V;
		V.resize(n);
		for (int i=0;i<n;i++) {
			V[i].resize(lunghezza);
			rf.fill(V[i], -10.0, 10.0);
		}
		for (int j=0; j<6; j++){
			std::vector<std::vector<double>> v = V;
			timecounter tc;
			switch (j) {
				case 0: {
					tc.tic();
					for (int i=0;i<n;i++) {
						bubblesort(v[i]);
					}
					double secs = tc.toc();
					std::cout << "(Bubblesort)      Elapsed time: " << secs/n << " seconds\n";
					break;
				}	
				case 1: {
					tc.tic();
					for (int i=0;i<n;i++) {
						insertionsort(v[i]);
					}
					double secs = tc.toc();
					std::cout << "(Insertionsort)   Elapsed time: " << secs/n << " seconds\n";
					break;
				}
				case 2: {
					tc.tic();
					for (int i=0;i<n;i++) {
						selectionsort(v[i]);
					}
					double secs = tc.toc();
					std::cout << "(Selectionsort)   Elapsed time: " << secs/n << " seconds\n";
					break;
				}
				case 3: {
					tc.tic();
					for (int i=0;i<n;i++) {
						mergesort(v[i]);
					}
					double secs = tc.toc();
					std::cout << "(Mergesort)       Elapsed time: " << secs/n << " seconds\n";
					break;
				}
				case 4: {
					tc.tic();
					for (int i=0;i<n;i++) {
						quicksort(v[i]);
					}
					double secs = tc.toc();
					std::cout << "(Quicksort)       Elapsed time: " << secs/n << " seconds\n";
					break;
				}
				case 5: {
					tc.tic();
					for (int i=0;i<n;i++) {
						std::sort(v[i].begin(), v[i].end());
					}
					double secs = tc.toc();
					std::cout << "('standard' sort) Elapsed time: " << secs/n << " seconds\n";
					break;
				}
			}
		}
		std::cout << "\n";
	}
	
	
	std::cout << "Confronto su vettori di piccole dimensioni\n\n";
	int lungh = 0;
	for (int l=0; l<10; l++){
		lungh += 10;
		std::cout << "Lunghezza vettore: " << lungh << "\n";
		std::vector<std::vector<double>> W;
		W.resize(n);
		for (int i=0;i<n;i++) {
			W[i].resize(lungh);
			rf.fill(W[i], -10.0, 10.0);
		}
		for (int j=0; j<6; j++){
			std::vector<std::vector<double>> w = W;
			timecounter tc;
			switch (j) {
				case 0: {
					tc.tic();
					for (int i=0;i<n;i++) {
						bubblesort(w[i]);
					}
					double secs = tc.toc();
					std::cout << "(Bubblesort)      Elapsed time: " << secs/n << " seconds\n";
					break;
				}	
				case 1: {
					tc.tic();
					for (int i=0;i<n;i++) {
						insertionsort(w[i]);
					}
					double secs = tc.toc();
					std::cout << "(Insertionsort)   Elapsed time: " << secs/n << " seconds\n";
					break;
				}
				case 2: {
					tc.tic();
					for (int i=0;i<n;i++) {
						selectionsort(w[i]);
					}
					double secs = tc.toc();
					std::cout << "(Selectionsort)   Elapsed time: " << secs/n << " seconds\n";
					break;
				}
				case 3: {
					tc.tic();
					for (int i=0;i<n;i++) {
						mergesort(w[i]);
					}
					double secs = tc.toc();
					std::cout << "(Mergesort)       Elapsed time: " << secs/n << " seconds\n";
					break;
				}
				case 4: {
					tc.tic();
					for (int i=0;i<n;i++) {
						quicksort(w[i]);
					}
					double secs = tc.toc();
					std::cout << "(Quicksort)       Elapsed time: " << secs/n << " seconds\n";
					break;
				}
				case 5: {
					tc.tic();
					for (int i=0;i<n;i++) {
						std::sort(w[i].begin(), w[i].end());
					}
					double secs = tc.toc();
					std::cout << "('standard' sort) Elapsed time: " << secs/n << " seconds\n";
					break;
				}
			}
		}
		std::cout << "\n";
	}
	return 0;
}