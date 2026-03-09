#include <iostream>

//*
int main() {
	int k1; std::cin >> k1;
	int k2; std::cin >> k2;

	int result = ((k1 << 1) + k2) * ((k2 << 1) + k1) - (k1 * k2) * 3;

	std::cout << result;
}