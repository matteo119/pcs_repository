#include <vector>
#include <limits> //usata per i valori sentinella nel mergesort
template<typename T>
void scambio(std::vector<T>& vec, int i, int j) {
	T scambio = vec[i];
	vec[i] = vec[j];
	vec[j] = scambio;
}

template<typename T>
void bubblesort(std::vector<T>& vec) {
	int length_vec = vec.size();
	for (int i=0; i < length_vec-1; i++) {
		for (int j=length_vec-1; j > i; j--) {
			if (vec[j] < vec[j-1]) {
				scambio(vec, j, j-1);
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
		scambio(vec, min, i);
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
//--------------------------------------
template <typename T>
T massimo() {
    return std::numeric_limits<T>::max();//uso <limits>
}

template <>
std::string massimo<std::string>() {
    return "zzzzz";
}

template<typename T>
void merge(std::vector<T>& vec, int p, int q, int r) {
	int n1 = q-p+1;
	int n2 = r-q;
	std::vector<T> L(n1+1), R(n2+1);
	for (int i=0; i<n1; i++) {
		L[i] = vec[p+i];
	}
	for (int j=0; j<n2; j++) {
		R[j] = vec[q+j+1];
	}
	L[n1] = massimo<T>();
	R[n2] = massimo<T>();
	int i=0, j=0;
	for (int k=p; k<=r; k++) {
		if (L[i] <= R[j]) {
			vec[k] = L[i];
			i++;
		} else {
			vec[k] = R[j];
			j++;
		}
		
	}
}

template<typename T>
void mergesort_iter(std::vector<T>& vec, int p, int r) {
	if (p<r) {
		int q = (p+r)/2;
		mergesort_iter(vec, p, q);
		mergesort_iter(vec, q+1, r);
		merge(vec, p, q, r);
	}
}

template<typename T>
void mergesort(std::vector<T>& vec) {
	int r=vec.size()-1;
	mergesort_iter(vec, 0, r);
}

template<typename T>
int partition(std::vector<T>& vec, int p, int r) {
	T x = vec[r];
	int i = p-1;
	for (int j=p; j<r; j++) {
		if (vec[j] <= x) {
			i++;
			scambio(vec, i, j);
		}
	}
	scambio(vec, i+1, r);
	return i+1;
}

template<typename T>
void quicksort_iter(std::vector<T>& vec, int p, int r) {
	if (p<r) {
		int q = partition(vec, p, r);
		quicksort_iter(vec, p, q-1);
		quicksort_iter(vec, q+1, r);
	}
}

template<typename T>
void quicksort(std::vector<T>& vec) {
	int r=vec.size()-1;
	quicksort_iter(vec, 0, r);
}