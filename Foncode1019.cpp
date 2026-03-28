#include <iostream>

/*
int main() {
	int size; std::cin >> size;

	std::int8_t* array = new std::int8_t[size];
	int read;
	for (int i = 0; i < size;i++) {
		std::cin >> read;
		array[i] = ((read & 1) ? -1 : 1);
		//std::cout << (int)array[i] << ',';
	}

	int result = 0;
	int balance;
	for (int i = 0; i < size; i++) {
		balance = 0;
		for (int j = i; j < size-1; j+=2) {
			balance += array[j];
			balance += array[j + 1];
			if (balance == 0) result++;
		}
	}

	std::cout << result;

	delete[] array;
}
//*/