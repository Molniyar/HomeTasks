#include <iostream>

//*

int main() {
	int balls; std::cin >> balls;
	int switches; std::cin >> switches;

	if (switches & 1) {
		std::cout << "Yes";
		return 0;
	}

	int read_off = 0;
	int read_on = 0;
	for (int i = 0; i < switches-1; i+=2) {
		std::cin >> read_off;
		std::cin >> read_on;
		balls -= read_on - read_off;
	}

	//std::cout << balls << '\n';
	std::cout << (balls > 0 ? "No" : "Yes");

	return 0;
}
//*/