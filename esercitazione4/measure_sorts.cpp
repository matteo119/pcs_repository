#include <iostream>
#include <algorithm>
#include <vector>

#include "randfiller.h"
#include "sort.hpp"
#include "timecounter.h"

int main(void) {
	int lunghezza = 2;
	randfiller rf;
	for (int i=2; i<14; i++){
		lunghezza *= 2;
		std::vector<double> V;
		V.resize(lunghezza);
		rf.fill(V, -10.0, 10.0);
		std::cout << "Lunghezza vettore: " << lunghezza << "\n";
		for (int j=0; j<4; j++){
			std::vector<double> v = V;
			timecounter tc;
			switch (j) {
				case 0: {
					tc.tic();
					bubblesort(v);
					double secs = tc.toc();
					std::cout << "(Bubblesort)      Elapsed time: " << secs << " seconds\n";
					break;
				}	
				case 1: {
					tc.tic();
					insertionsort(v);
					double secs = tc.toc();
					std::cout << "(Insertionsort)   Elapsed time: " << secs << " seconds\n";
					break;
				}
				case 2: {
					tc.tic();
					selectionsort(v);
					double secs = tc.toc();
					std::cout << "(Selectionsort)   Elapsed time: " << secs << " seconds\n";
					break;
				}
				case 3: {
					tc.tic();
					std::sort(v.begin(), v.end());
					double secs = tc.toc();
					std::cout << "('standard' sort) Elapsed time: " << secs << " seconds\n";
					break;
				}
			}
		}
		std::cout << "\n";
	}
	
	return 0;
}