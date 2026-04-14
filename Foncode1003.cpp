#include <iostream>

//*

int main() {
	int rows; std::cin >> rows;
	int cols; std::cin >> cols;

	int read;
	int sum = 0;
	for (int j = 0; j < cols; j++) {
		std::cin >> read;
		sum += read;
	}
	if (sum != 0 && sum != cols) {
		std::cout << "no";
		return 0;
	}
	bool prev = sum;

	for (int i = 1; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < cols; j++) {
			std::cin >> read;
			sum += read;
		}
		if (sum != 0 && sum != cols) {
			std::cout << "No";
			return 0;
		}
		if ((bool)(sum)==prev) {
			std::cout << "NO";
			return 0;
		}
		prev = sum;
	}
	std::cout << "Yes";

	return 0;
}
//*/