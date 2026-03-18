#include <iostream>

/*
int main() {
	int size; std::cin >> size;
	int width; std::cin >> width;

	int s1 = 0;
	int s2 = 0;

	int read;
	for (int i = 0; i < size - 1; i++) {
		std::cin >> read;
		s1 += read;
		s2 += width - read;
	}
	if (std::abs(s1 - s2) > width || (size*width)&1) {
		std::cout << "-1";
	}
	else std::cout << ((s2 - s1 + width) >> 1);
}
//*/