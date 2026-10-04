/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int size; cin >> size;
	int price; cin >> price;
	
	int* components = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> components[i];
	}

	std::sort(components, components + size, std::greater<int>());

	for (int i = 0; i < size; i++) {
		std::cout << components[i] << ' ';
	}
	std::cout << '\n';

	int result = 1000000001;
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum = 0;
		for (int j = i; j < size; j++) {
			sum += components[j];
			if (sum >= price) {
				if (sum < result)
					result = sum;
				sum -= components[j];
			}
		}
	}

	cout << (result <= 1000000000 ? result : 0);

	delete[] components;
	return 0;
}
//*/