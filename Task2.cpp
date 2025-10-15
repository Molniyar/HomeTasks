#include <iostream>
#include <vector>
#include <queue>
#include "OrderedQueue.h"

struct Point {
	int x;
	int y;
};
struct MyPoint {
	int x;
	int y;
	int n;
};

bool DEBUG = false;

void printMatrix_(int** matrix, int ySize, int xSize) {
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			switch (matrix[i][j]) {
			case -1: { std::cout << "##"; break; }
			case 1: { std::cout << "__"; break; }
			case 8: { std::cout << "=="; break; }
			case -2: { std::cout << "()"; break; }
			case -128: { std::cout << "ST"; break; }
			case 127: { std::cout << "EN"; break; }
			case -8: { std::cout << "??"; break; }
			default: std::cout << "  ";
			}
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void printMatrix(int** matrix, int ySize, int xSize) {
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void find_path(int** matrix, int ySize, int xSize, int yStart, int xStart, int yEnd, int xEnd) {
	if (xStart == xEnd || yStart == yEnd) { return; }

	int** dMatrix = new int* [ySize];
	for (int i = 0; i < ySize; i++) {
		dMatrix[i] = new int[xSize];
		for (int j = 0; j < xSize; j++) { dMatrix[i][j] = -1; }
	}


	dMatrix[yStart][xStart] = 0;

	std::queue<MyPoint> queue_;
	queue_.push({ xStart,yStart,0 });
	bool pathFound = false;

	int X_[] = { -1, 1, 0, 0 };
	int Y_[] = { 0, 0, -1, 1 };
	for (; !queue_.empty();) {
		MyPoint current = queue_.front();
		std::cout << current.x << ' ' << current.y << ' ' << current.n << '\n';

		int nz = current.n + 1;

		for (int i = 0; i < 4; i++) {
			int nx = X_[i] + current.x;
			int ny = Y_[i] + current.y;
			std::cout << nx << ' ' << ny << '\n';
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (matrix[ny][nx] != -1 && dMatrix[ny][nx] == -1) {
				queue_.push({ nx,ny,nz });
				dMatrix[ny][nx] = nz;

				//matrix[ny][nx] = -8;
			}
		}
		//printMatrix(dMatrix, ySize, xSize);
		queue_.pop();
	}
	printMatrix(dMatrix, ySize, xSize);
	int x = xEnd;
	int y = yEnd;
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = X_[j] + x;
			int ny = Y_[j] + y;
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (dMatrix[ny][nx] != -1 && dMatrix[ny][nx] < dMatrix[y][x]) {
				x = nx;
				y = ny;
				matrix[y][x] = -2;
			}
		}
		if (x == xStart && y == yStart) break;
	}
	matrix[yStart][xStart] = -128;//start
	matrix[yEnd][xEnd] = 127;//end
}


void find_path_with_priorities(int** matrix, int ySize, int xSize, int yStart, int xStart, int yEnd, int xEnd) {
	if (xStart == xEnd && yStart == yEnd) { return; }

	int** dMatrix = new int* [ySize];
	for (int y = 0; y < ySize; y++) {
		dMatrix[y] = new int[xSize];
		for (int x = 0; x < xSize; x++) { dMatrix[y][x] = -1; }
	}


	dMatrix[yStart][xStart] = 0;

	OrderedQueue<MyPoint> queue_;
	queue_.add({ xStart, yStart, 0 });
	bool pathFound = false;

	int X_[] = { -1, 1, 0, 0 };
	int Y_[] = { 0, 0, -1, 1 };
	for (; !queue_.is_empty();) {
		MyPoint current = queue_.pop();
		if (DEBUG) std::cout << current.x << ' ' << current.y << ' ' << current.n << '\n';

		//int nz = current.n + matrix[current.y][current.x];

		for (int i = 0; i < 4; i++) {
			int nx = X_[i] + current.x;
			int ny = Y_[i] + current.y;
			if (DEBUG) std::cout << nx << ' ' << ny << '\n';
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (matrix[ny][nx] != -1 && (dMatrix[ny][nx] == -1 || dMatrix[ny][nx] > current.n + matrix[ny][nx])) {
				queue_.add({ nx,ny,current.n + matrix[ny][nx] });
				dMatrix[ny][nx] = current.n + matrix[ny][nx];

				//matrix[ny][nx] = -8;
			}
		}
		if (DEBUG) printMatrix(dMatrix, ySize, xSize);
		
	}
	printMatrix(dMatrix, ySize, xSize);
	int x = xEnd;
	int y = yEnd;
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = X_[j] + x;
			int ny = Y_[j] + y;
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (dMatrix[ny][nx] != -1 && dMatrix[ny][nx] < dMatrix[y][x]) {
				x = nx;
				y = ny;
				matrix[y][x] = -2;
			}
		}
		if (x == xStart && y == yStart) break;
	}
	matrix[yStart][xStart] = -128;//start
	matrix[yEnd][xEnd] = 127;//end
}

void test() {
	OrderedQueue<MyPoint> queue;


	queue.add({ 0,0,8 });
	queue.add({ 0,1,2 });
	queue.add({ 1,0,4 });
	queue.add({ 0,2,0 });
	std::cout << "added { 0,0,8 },{ 0,1,2 },{ 1,0,4 },{ 0,2,0 } \n";


	std::cout << "heapifying to get a point that has the smallest N \n";


	MyPoint p;
	while (!queue.is_empty()){
		p = queue.pop();
		std::cout << "popped - X:Y - " << p.x << ":" << p.y << " N:" << p.n << '\n';
	}

	std::cout << "checking is the quque empty: " << queue.is_empty();
}

int main() {
	test();
	

	return 0;
}