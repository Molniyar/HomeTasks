/*
#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int x;
	int y;

	Point operator +(Point p)const {
		return { x + p.x,y + p.y };
	}
};

Point dirs[4] { {1,0},{-1,0},{0,1},{0,-1} };

int height;
int width;
struct Matrix {
	int matrix[1000][1000];
	void set(int x, int y, int val) {
		matrix[y][x] = val;
	}
	int get(int x, int y) {
		if (x >= width || x < 0 || y >= height || y < 0) {
			return -1;
		}
		return matrix[y][x];
	}
	void set(Point p, int val) {
		matrix[p.y][p.x] = val;
	}
	int get(Point p) {
		if (p.x >= width || p.x < 0 || p.y >= height || p.y < 0) {
			return -1;
		}
		return matrix[p.y][p.x];
	}
};



const int WALL  = 1000001;
const int EMPTY = 1000000;

int char_to_int(char n) {
	return n == '#' ? WALL : EMPTY;
}

queue<Point> to_write;


Matrix matrix;

int main() {
	cin >> height;
	cin >> width;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			char read;
			cin >> read;
			if (read == '#') 
				matrix.set(x, y, WALL);
			else
				matrix.set(x, y, EMPTY);
		}
	}


	for (int y = 0; y < height; y++) {
		if (matrix.get({ 0,y }) == EMPTY) 
			to_write.push({ 0,y });
		if (matrix.get({ width - 1,y }) == EMPTY) 
			to_write.push({ width - 1,y });
	}
	for (int x = 1; x < width-1; x++) {
		if (matrix.get({ x,0 }) == EMPTY) 
			to_write.push({ x,0 });
		if (matrix.get({ x,height - 1 }) == EMPTY) 
			to_write.push({ x,height - 1 });
	}

	while (to_write.size()) {
		if (matrix.get(to_write.front()) == WALL) {
			to_write.pop();
			continue;
		}
		Point current = to_write.front();

		int m = 1000002;
		for (Point d : dirs) {
			m = min(m, matrix.get(current + d));
		}

		if (m > 999999) {
			continue;
		}
		matrix.set(current, m + 1);
		for (Point d : dirs) {
			if (matrix.get(current + d) == EMPTY) {
				to_write.push(current + d);
				matrix.set(current + d, 1000003);
			}
		}
		to_write.pop();
	}
	


	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int current = matrix.get(x, y);
			if (current == WALL) {
				cout << '#';
				continue;
			}
			if (current == EMPTY) {
				cout << '.';
				continue;
			}
			char dir_chars[4]{ '>','<','v','^' };
			for (int i = 0; i < 4; i++) {
				if (matrix.get(Point{x,y}+dirs[i]) < current) {
					cout << dir_chars[i];
					break;
				}
			}
			//cout << current;
		}
		cout << '\n';
	}

	return 0;
}//.#

//*/