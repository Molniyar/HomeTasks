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
	Point operator -(Point p)const {
		return { x - p.x,y - p.y };
	}

	bool operator ==(Point p)const {
		return x == p.x && y == p.y;
	}
};

Point dirs[4]{ {1,0},{-1,0},{0,1},{0,-1} };

int height;
int width;
struct Matrix {
	int matrix[10][10];
	int OUT_OF_BOUNDS = 200;
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
			return OUT_OF_BOUNDS;
		}
		return matrix[p.y][p.x];
	}
};



const int POINT = 102;
const int WALL = 101;
const int EMPTY = 100;


Matrix matrix;
Matrix matrix_copy;

int find_path(Matrix matrix, Point from, Point to, int& priority, int& previous_path) {

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			matrix_copy.set(x, y, matrix.get(x, y));
		}
	}

	queue<Point> cells;
	matrix_copy.set(from, 0);
	for (Point dir : dirs) {
		if (matrix_copy.get(from + dir) == EMPTY)
			cells.push(from + dir);
	}

	while (cells.size()) {
		Point current = cells.front();
		if (matrix_copy.get(current) != EMPTY) {
			cells.pop();
			continue;
		}
		for (Point dir : dirs) {
			if (matrix_copy.get(current + dir) == EMPTY)
				cells.push(current + dir);
		}
		int m = 109;
		for (Point dir : dirs) {
			m = min(m, matrix_copy.get(current + dir));
			if (m > 99) {
				continue;
			}
			matrix_copy.set(current, m + 1);
		}
		if (current == to) {
			if (previous_path != matrix_copy.get(to)) {
				previous_path++;
				return matrix_copy.get(to);
			}
			return matrix_copy.get(to) + priority;
		}

		cells.pop();
	}
	return -1;
}

int main() {// Наличие клетки на координатах (10, 0) равной '.' гарантирует неверное выполнение
	cin >> height;
	cin >> width;

	vector<Point> HOLES;
	vector<Point> POINTS;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			char read;
			cin >> read;

			if (read == '#')
				matrix.set(x, y, WALL);
			else
				matrix.set(x, y, EMPTY);

			if (read == 'o')
				HOLES.push_back({ x,y });
			if (read == '*')
				POINTS.push_back({ x,y });
		}
	}


	//size_t sourceSize = sizeof(sourceArr) / sizeof(sourceArr[0]);
	size_t sourceSize = HOLES.size();

	std::vector<int> hole_used(sourceSize);
	for (int i = 0; i < sourceSize; i++)
		hole_used[i] = 0;

	std::vector<int> hole_last_path(sourceSize);
	for (int i = 0; i < sourceSize; i++)
		hole_last_path[i] = -1;


	int result = 0;

	for (int p = 0; p < POINTS.size(); p++) {
		Point point = POINTS[p];
		int hole = -1;
		int optimal_path = 0xFF;
		for (int h = 0; h < HOLES.size(); h++) {
			int path = find_path(matrix, point, HOLES[h], hole_used[h], hole_last_path[h]);
			cout << "distance " << path << " between {" << point.x << ',' << point.y << "} and {" << HOLES[h].x << ',' << HOLES[h].y << "}\n";
			if (path < optimal_path) {
				optimal_path = path;
				if (hole != -1) hole_used[hole]--;
				hole_used[h]++;
				hole = h;
			}
		}
		//hole_last_path[hole] = optimal_path;
		if (optimal_path > result) {
			result = optimal_path;
		}
	}

	cout << result;

	return 0;
}//.#


//*/