#include <iostream>

/*
int main() {
	int ports; std::cin >> ports;
	int size; std::cin >> size;
	int empires; std::cin >> empires;

	int keep = 1;
	int ships = size;
	int prev = 1;

	int read;
	for (int i = 0; i < empires; i++) {
		std::cin >> read;// reading useless info
		std::cin >> read;

		if (read <= prev) { 
			continue; 
		}

		prev *= (read / prev) + (bool)(read % prev);
	}

	std::cout << (ships / prev) + (bool)(ships % prev);
}
//*/