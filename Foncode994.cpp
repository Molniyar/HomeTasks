#include <iostream>
#include <algorithm>

/*
int main() {
	int size0; std::cin >> size0;
	int size1; std::cin >> size1;

	int* arr0 = new int[size0];
	int* arr1 = new int[size1];
	for (int i = 0; i < size0; i++) std::cin >> arr0[i];
	for (int i = 0; i < size1; i++) std::cin >> arr1[i];

	std::sort(arr0, arr0 + size0);
	std::sort(arr1, arr1 + size1);

	int wins = 0;

	for (int i = 0, j = 0; i < size0 && j < size1; i++, j++) {
		if (arr0[i] >= arr1[j]) {
			i--;
			continue;
		}
		wins++;
	}

	std::cout << ((wins >= size0) ? "YES" : "NO");

	delete[] arr0;
	delete[] arr1;
}
//*/