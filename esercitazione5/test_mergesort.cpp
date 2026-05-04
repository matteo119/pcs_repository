#include <iostream>
#include <vector>
#include "randfiller.h"
#include "sort.hpp"
#include "is_sorted.hpp"

int main(void)
{
    randfiller rf;

	std::vector<int> lunghezza;
	lunghezza.resize(100);
	rf.fill(lunghezza, 0, 10000);
	
	for (int i=0; i<100; i++) {
		std::vector<int> vi;
		vi.resize(lunghezza[i]);
		rf.fill(vi, -30, 30);
		mergesort(vi);
		if (!is_sorted(vi)) {
			return EXIT_FAILURE;
		}
	}
	
	for (int i=0; i<100; i++) {
		std::vector<float> vf;
		vf.resize(lunghezza[i]);
		rf.fill(vf, -3.0f, 3.0f);
		mergesort(vf);
		if (!is_sorted(vf)) {
			return EXIT_FAILURE;
		}
	}
	
	for (int i=0; i<100; i++) {
		std::vector<double> vd;
		vd.resize(lunghezza[i]);
		rf.fill(vd, -3.0, 3.0);
		mergesort(vd);
		if (!is_sorted(vd)) {
			return EXIT_FAILURE;
		}
	}
	
	std::vector<std::string> vs = {"Casa", "Gioco", "Anno", "squadra", "cielo", "anno", "Diario", "Spada", "aquila", "Italia"};
	mergesort(vs);
	if (!is_sorted(vs)) {
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}