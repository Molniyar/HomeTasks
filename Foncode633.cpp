#include <iostream>

/*

int count; 
int* cubes;

std::int64_t experiment(int to_drop, int to_destroy) {
	std::int64_t energy = 0;
	int up = to_drop - 1;
	int down = to_drop;

	for (int i = 0; i < to_destroy && up >= 0 && down < count; i++) {
		energy += cubes[up] * cubes[down];
		if (cubes[up] < cubes[down]) 
			up--;
		else
			down++;
	}

	return energy;
}

int main() {
	std::cin >> count;
	cubes = new int[count];
	for (int i = 0; i < count; i++) {
		std::cin >> cubes[i];
	}

	int tests; std::cin >> tests;

	int to_drop; 
	int to_destroy; 
	for (int i = 0; i < tests; i++) {
		std::cin >> to_drop;
		std::cin >> to_destroy;

		std::cout << experiment(to_drop, to_destroy) << '\n';
	}
	
	delete[] cubes;
}
//*/