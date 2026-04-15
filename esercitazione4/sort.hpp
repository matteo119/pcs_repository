#include <vector>

template<typename T>
void bubblesort(std::vector<T>& vec) {
	int length_vec = vec.size();
	for (int i=0; i < length_vec-1; i++) {
		for (int j=length_vec-1; j > i; j--) {
			if (vec[j] < vec[j-1]) {
				T scambio = vec[j];
				vec[j] = vec[j-1];
				vec[j-1] = scambio;
			}
		}
	}
}

template<typename T>
void selectionsort(std::vector<T>& vec) {
	int length_vec = vec.size();
	for (int i=0; i <length_vec-1; i++) {
		int min = i;
		for (int j=i+1; j < length_vec; j++) {
			if (vec[j] < vec[min]) {
					min = j;
			}
		}
		T scambio = vec[min];
		vec[min] = vec[i];
		vec[i] = scambio;
	}
}

template<typename T>
void insertionsort(std::vector<T>& vec) {
	int length_vec = vec.size();
	for (int j=1; j < length_vec; j++) {
		T key = vec[j];
		int i = j;
		while (i > 0 && vec[i-1] > key) {
			vec[i] = vec[i-1];
			i--;
		}
		vec[i] = key;
	}
}