#include <iostream>

//*
int main() {
	int inp; std::cin >> inp;

	for (int i = 2; inp/i >= i;) {
		if (inp % i != 0) { i++; continue; }
		std::cout << i << ' ';
		inp /= i;
	}
	std::cout << inp;

	return 0;
}

//*/