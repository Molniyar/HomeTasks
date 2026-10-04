/*
#include <iostream>
using namespace std;

bool tunnel(int width, int height, int x, int y) {
	return (
		x == 0 || x == width - 1 ||
		(!(y & 1) && x != (y & 2 ? 1 : height - 2)) ||
		y == 0
		);
}
bool random(int width, int height, int x, int y) {
	return rand() & 1;
}

int main() {
	int width = 1000;
	int height = 1000;
	std::cout << width << ' ' << height << '\n';
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (0)
				cout << '#';
			else
				cout << '.';
		}
		cout << '\n';
	}
}
//*/