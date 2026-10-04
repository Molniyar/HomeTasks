/*
#include <iostream>
using namespace std;

int matrix[50][50];
int height; 
int width; 

bool is_in_bounds(int x, int y) {
	return x >= 0 && x < width && y >= 0 && y < height;
}

bool calculate(int x, int y) {
	if (!is_in_bounds(x, y)) return false;
	if (is_in_bounds(x - 1, y - 2)) {
		matrix[y][x] += matrix[y - 2][x - 1];
	}
	if (is_in_bounds(x - 2, y - 1)) {
		matrix[y][x] += matrix[y - 1][x - 2];
	}
	return true;
}

int main() {
	cin >> height;
	cin >> width;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;

	int X = 0;
	int Y = 0;
	while (is_in_bounds(X, Y)) {
		int x = X;
		int y = Y;
		while (is_in_bounds(x,y)) {
			calculate(x, y);
			x += 2;
			y += 1;
		}
		X += 1;
		Y += 2;
	}

	cout << matrix[height - 1][width - 1];


	return 0;
}

//*/