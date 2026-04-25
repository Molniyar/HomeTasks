#include <iostream>

//*
struct TPoint
{
	int x = 0;
	int y = 0;

	TPoint operator+(const TPoint& b) { return { x + b.x, y + b.y }; }

	TPoint operator-(const TPoint& b) { return { x - b.x, y - b.y }; }

	void operator<<=(int trash) {
		x = -x;
		std::swap(x, y);
	}

	void operator>>=(int trash) {
		y = -y;
		std::swap(x, y);
	}
};

TPoint dirs[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int size;
int depth;
char matrix[1000][1000];
bool is_in_bounds(TPoint p) {
	return p.x >= 0 && p.x < size && p.y >= 0 && p.y < size;
}
bool is_next(int prev, int curr) {
	return (curr - prev == 1 || prev - curr == depth - 1);
}
int snake_left_length(int prev, TPoint coord, TPoint dir) {
	int count = 0;
	int width = 1;
	
	while (true) {
		for (int i = 0; i < width; i++) {
			if (!is_in_bounds(coord) || !is_next(prev,matrix[coord.y][coord.x])) return count;
			//std::cout << coord.x << ' ' << coord.y << ' ' << prev << ' ' << matrix[coord.y][coord.x]+0 << '\n';
			prev = matrix[coord.y][coord.x];
			coord = coord + dir;
			count++;
		}
		dir <<= 1;
		for (int i = 0; i < width; i++) {
			if (!is_in_bounds(coord) || !is_next(prev, matrix[coord.y][coord.x])) return count;
			//std::cout << coord.x << ' ' << coord.y << ' ' << prev << ' ' << matrix[coord.y][coord.x]+0 << '\n';
			prev = matrix[coord.y][coord.x];
			coord = coord + dir;
			count++;
		}
		dir <<= 1;
		width++;
	}
	return count;
}
int snake_right_length(int prev, TPoint coord, TPoint dir) {
	int count = 0;
	int width = 1;

	while (true) {
		for (int i = 0; i < width; i++) {
			if (!is_in_bounds(coord) || !is_next(prev, matrix[coord.y][coord.x])) return count;
			//std::cout << coord.x << ' ' << coord.y << ' ' << prev << ' ' << matrix[coord.y][coord.x]+0 << '\n';
			prev = matrix[coord.y][coord.x];
			coord = coord + dir;
			count++;
		}
		dir >>= 1;
		for (int i = 0; i < width; i++) {
			if (!is_in_bounds(coord) || !is_next(prev, matrix[coord.y][coord.x])) return count;
			//std::cout << coord.x << ' ' << coord.y << ' ' << prev << ' ' << matrix[coord.y][coord.x]+0 << '\n';
			prev = matrix[coord.y][coord.x];
			coord = coord + dir;
			count++;
		}
		dir >>= 1;
		width++;
	}
	return count;
}
int main() {
	std::cin >> size;
	std::cin >> depth;

	char read;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cin >> read;
			matrix[i][j] = read - '0';
		}
	}

	int result = 0;
	int X = -1;
	int Y = -1;
	
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (matrix[y][x]) { continue; }
			int r = std::max(
				std::max(std::max(snake_left_length(-1, { x,y }, dirs[0]), snake_left_length(-1, { x,y }, dirs[1])), std::max(snake_left_length(-1, { x,y }, dirs[2]), snake_left_length(-1, { x,y }, dirs[3]))),
				std::max(std::max(snake_right_length(-1, { x,y }, dirs[0]), snake_right_length(-1, { x,y }, dirs[1])), std::max(snake_right_length(-1, { x,y }, dirs[2]), snake_right_length(-1, { x,y }, dirs[3])))
			);
			for (int i = 1;; i += 2) {
				if (i * i > r) {
					i-=2;
					r = i * i;
					break;
				}
			}
			if (r > result) {
				result = r;
				X = x;
				Y = y;
			}
		}
	}
	std::cout << result << '\n' << Y+1 << ' ' << X+1;

	return 0;
}
//*/