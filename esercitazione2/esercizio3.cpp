#include <iostream>

int main()
{
	static const int N = 10;
	double arr[N] = {0.0, 1.1, 4.4, 2.2, 9.9, 6.6, 3.3, 5.5, 7.7, 8.8};
	bool scambi = 1;

	while (scambi) {
		scambi = 0;
		for(int i = 0; i<N-1 ;i++) {
			if (arr[i] > arr[i+1]) {
				double b = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = b;
				scambi = 1;
			}
		}
	}

	for (int i=0; i<N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	return 0;
}