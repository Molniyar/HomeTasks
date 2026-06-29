#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
/*
bool debug = 0;

struct TPoint
{
	int x = 0;
	int y = 0;

	TPoint operator+(const TPoint& b) { return { x + b.x, y + b.y }; }
	void operator+=(const TPoint& b) { x += b.x; y += b.y; }

	TPoint operator-(const TPoint& b) { return { x - b.x, y - b.y }; }
	void operator-=(const TPoint& b) { x -= b.x; y -= b.y; }

	TPoint operator*(int b) { return { x * b, y * b }; }
	void operator*=(int b) { x *= b; y *= b; }

	bool operator==(const TPoint& p) const {
		return (x == p.x && y == p.y);
	}

	bool operator < (const TPoint& other) const {
		if (x == other.x) return y < other.y;
		return x < other.x;
	}

	double length() const {
		return std::sqrt(x*x + y*y);
	}

	void print() {
		std::cout << " {" << x << ';' << y << "} ";
	}
};

struct Node {
	Node* prev = nullptr;
	TPoint data;
	Node* next = nullptr;

	void print() {
		std::cout << " {" << data.x << ';' << data.y << "} ";
	}
};

double get_length(TPoint from, TPoint to) {
	return (from - to).length();
}

int get_line(const TPoint& from, const TPoint& to, const TPoint& curr) {// maybe swap to and from
	int A = -from.y + to.y;
	int B = from.x - to.x;
	int C = -to.y*B -to.x*A;
	int X = curr.x;
	int Y = curr.y;

	return A * X + B * Y + C;
}

double scalar(const TPoint& vec1, const TPoint& vec2) {
	return (vec1.x * vec2.x + vec1.y * vec2.y);
}

double scalar_cos(const TPoint& vec1, const TPoint& vec2) {
	return scalar(vec1, vec2) / (vec2.length() * vec2.length());
}

TPoint array[1000];
TPoint up[1000];
TPoint down[1000];
int main() {
	int size; std::cin >> size;

	for (int i = 0; i < size; i++) {
		std::cin >> array[i].x;
		std::cin >> array[i].y;
	}

	std::sort(array, array + size);

	int i = 0;
	for (int j = 0; j < size; i++, j++) {
		while (i >= 2 && get_line(up[i - 2], array[j], up[i - 1]) < 0) {
			i--;
			if (debug) std::cout << "^ X \n";
		}
		up[i] = array[j];

		if (debug) {
			std::cout << "^^ ";
			up[i].print();
			std::cout << '\n';
		}
	}
	
	int I = 0;
	for (int j = 0; j < size; I++, j++) {
		while (I >= 2 && get_line(down[I - 2], array[j], down[I - 1]) >= 0) {
			I--;
			if (debug) std::cout << "v X \n";
		}
		down[I] = array[j];

		if (debug) {
			std::cout << "vv ";
			down[I].print();
			std::cout << '\n';
		}
	}

	double result = 0;
	for (int j = 0; j < i - 1; j++) {
		result += get_length(up[j], up[j + 1]);
	}
	for (int j = 0; j < I - 1; j++) {
		result += get_length(down[j], down[j + 1]);
	}

	std::cout << result;
}
// */