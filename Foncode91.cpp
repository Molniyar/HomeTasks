#include <iostream>
#include <queue>

//*
int main() {
	int size; std::cin >> size;
	int array[50000];
	for (int i = 0; i < size; i++) {
		std::cin >> array[i];
	}
	int result = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (array[i] > array[j])
				result++;
		}
	}

	std::cout << result;

	return 0;
}
//*/