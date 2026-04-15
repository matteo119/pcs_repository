#include <iostream>
#include <vector>
#include "randfiller.h"
#include "sort.hpp"
#include "is_sorted.hpp"

int main(void)
{
    randfiller rf;

	for (int i=0; i<100; i++) {
		std::vector<int> vi;
		vi.resize(10);
		rf.fill(vi, -30, 30);
		insertionsort(vi);
		if (!is_sorted(vi)) {
			return EXIT_FAILURE;
		}
	}
	
	for (int i=0; i<100; i++) {
		std::vector<float> vf;
		vf.resize(10);
		rf.fill(vf, -3.0f, 3.0f);
		insertionsort(vf);
		if (!is_sorted(vf)) {
			return EXIT_FAILURE;
		}
	}
	
	for (int i=0; i<100; i++) {
		std::vector<double> vd;
		vd.resize(10);
		rf.fill(vd, -3.0, 3.0);
		insertionsort(vd);
		if (!is_sorted(vd)) {
			return EXIT_FAILURE;
		}
	}
	
	std::vector<std::string> vs = {"Casa", "Gioco", "Anno", "squadra", "cielo", "anno", "Diario", "Spada", "aquila", "Italia"};
	insertionsort(vs);
	if (!is_sorted(vs)) {
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}