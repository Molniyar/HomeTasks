#include <iostream>

/*
int main() {
	int size; std::cin >> size;

	bool** matrix = new bool*[size];//init
	for (int i = 0; i < size; i++) {
		matrix[i] = new bool[size];
		for (int j = 0; j < size; j++) {std::cin >> matrix[i][j];}
	}

	int result = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (matrix[i][j] != matrix[j][i]) result++;
		}
	}

	for (int i = 0; i < size; i++) {delete[] matrix[i];}//del
	delete[] matrix;

	std::cout << result;
}
//*/