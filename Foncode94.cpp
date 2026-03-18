#include <iostream>
#include <algorithm>

/*
int main() {
	int size; std::cin >> size;
	int sum; std::cin >> sum;

	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin >> array[i];
	}

	std::sort(array, array + size);

	int min = 0;
	int max = size - 1;
	while(1) {
		if (array[min] + array[max] > sum) {
			max--;
		}
		else if (array[min] + array[max] < sum) {
			min++;
		}
		else {
			std::cout << array[min] << ' ' << array[max];
			break;
		}
	}

	delete[] array;
}
//*/