#include <iostream>
#include <algorithm>

//*
int main() {
	int size; std::cin >> size;

	int* b = new int[size];
	int* g = new int[size];
	int* dec_shifts = new int[size];

	for (int i = 0; i < size; i++) std::cin >> b[i];
	std::string read;
	for (int i = 0; i < size; i++) { 
		std::cin >> read;

		dec_shifts[i] = 1;
		for (int j = 0; j < read.size(); j++) {
			dec_shifts[i] *= 10;
		}

		g[i] = 0;
		for (int j = read.size() - 1; j >= 0; j--) {
			g[i] *= 10;
			g[i] += read[j]-'0';
		}
	}

	std::sort(b, b + size);
	std::sort(g, g + size);
	std::sort(dec_shifts, dec_shifts + size);


	std::int64_t sum = 0;

	for (int i = 0; i < size; i++) {
		sum += b[i] * dec_shifts[i];
		sum += g[i];
	}

	std::cout << sum;

	delete[] b;
	delete[] g;
	delete[] dec_shifts;
}
//*/