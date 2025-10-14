#include <iostream>
#include <vector>
#include <queue>

struct Point {
	int x;
	int y;
};
struct MyPoint {
	int x;
	int y;
	int n;
};

class OrderedQueue {
	std::vector<MyPoint> vec;
public:
	void add(MyPoint point) {
		vec.push_back(point);
	}
	bool is_empty() {
		return vec.empty();
	}
	void heapify() {
		heapify(0);
	}
	void heapify(int i) {
		int len = vec.size();
		if (i > len) { return; }

		int curr = i;
		int left = i * 2 + 1;
		int right = i * 2 + 2;

		if (left < len && vec.at(curr).n > vec.at(left).n) {
			curr = left;
		}
		if (right < len && vec.at(curr).n > vec.at(right).n) {
			curr = right;
		}

		if (curr != i) {
			std::swap(vec.at(curr).n, vec.at(i).n);
			heapify(curr);
		}
	}
	MyPoint pop() {
		MyPoint result = vec.front();
		vec.at(0) = vec.back();
		vec.pop_back();
		heapify(0);
		return result;
	}
};

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
		printMatrix(dMatrix, ySize, xSize);
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
	if (xStart == xEnd || yStart == yEnd) { return; }

	int** dMatrix = new int* [ySize];
	for (int y = 0; y < ySize; y++) {
		dMatrix[y] = new int[xSize];
		for (int x = 0; x < xSize; x++) { dMatrix[y][x] = -1; }
	}


	dMatrix[yStart][xStart] = 0;

	OrderedQueue queue_;
	queue_.add({ xStart, yStart, 0 });
	bool pathFound = false;

	int X_[] = { -1, 1, 0, 0 };
	int Y_[] = { 0, 0, -1, 1 };
	for (; !queue_.is_empty();) {
		MyPoint current = queue_.pop();
		std::cout << current.x << ' ' << current.y << ' ' << current.n << '\n';

		//int nz = current.n + matrix[current.y][current.x];

		for (int i = 0; i < 4; i++) {
			int nx = X_[i] + current.x;
			int ny = Y_[i] + current.y;
			std::cout << nx << ' ' << ny << '\n';
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (matrix[ny][nx] != -1 && (dMatrix[ny][nx] == -1 || dMatrix[ny][nx] > current.n + matrix[ny][nx])) {
				queue_.add({ nx,ny,current.n + matrix[ny][nx] });
				dMatrix[ny][nx] = current.n + matrix[ny][nx];

				//matrix[ny][nx] = -8;
			}
		}
		printMatrix(dMatrix, ySize, xSize);
		
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

int main() {
	int __ = 1;
	int WW = -1;
	int II = 8;
	int x1[] = { WW,WW,WW,WW,WW,WW,WW,WW,WW,WW,WW,WW };
	int x2[] = { WW,__,__,__,__,__,__,__,__,__,__,__ };
	int x3[] = { WW,__,WW,WW,WW,WW,WW,WW,WW,WW,WW,__ };
	int x4[] = { WW,__,WW,__,__,__,WW,__,__,__,WW,__ };
	int x5[] = { WW,__,WW,__,WW,WW,WW,__,WW,__,WW,__ };
	int x6[] = { WW,II,WW,__,WW,WW,WW,__,WW,__,WW,__ };
	int x7[] = { __,__,__,__,__,__,__,__,WW,__,__,__ };
	int x8[] = { __,__,__,WW,WW,WW,WW,WW,WW,WW,WW,WW };
	int* M[] = { x1,x2,x3,x4,x5,x6,x7,x8 };
	find_path_with_priorities(M, 8, 12, 1, 1, 6, 3);

	printMatrix_(M, 8, 12);

	return 0;
}