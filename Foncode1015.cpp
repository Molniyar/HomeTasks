#include <iostream>
#include <algorithm>

//*
int main() {
	int size; std::cin >> size;
	int changing_size = size;

	int empty = 101;

	int* array = new int[size+2];
	array++;
	array[-1] = -101;
	array[size] = 102;
	for (int i = 0; i < size; i++) { 
		std::cin >> array[i];
	}
	int deleted = 0;
	int min;
	int max;
	while (deleted < size-1) {
		min = size;
		max = -1;
		for (int i = 0; i < size; i++) {
			if (array[i] == empty) continue;
			if (array[i] < array[min]) min = i;
			if (array[i] > array[max]) max = i;
		}
		array[min] = empty;
		array[max] = empty;
		if (min > max) std::swap(min, max);
		for (int i = min + 1; i < max; i++) {
			if (array[i] == empty) continue;
			array[i] = -array[i];
		}
		deleted += 2;
	}
	for (int i = 0; i < size; i++) {
		if (array[i] != empty) {
			std::cout << array[i] << '\n';
			break;
		}
	}

	array--;
	delete[] array;
}
//*/