#include <iostream>

//*
int main() {
	int size; std::cin >> size;
	int min_x = 0;
	int min_y = 0;
	int x;
	int y;
	for (int i = 0; i < size; i++) {
		std::cin >> x;
		std::cin >> y;
		if (x < min_x) min_x = x;
		if (y < min_y) min_y = y;
	}
	std::cout << min_x << ' ' << min_y << '\n';
}
//*/