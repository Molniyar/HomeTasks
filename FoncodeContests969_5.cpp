#include <iostream>

/*
struct TPoint
{
	int x = 0;
	int y = 0;

	TPoint operator+(const TPoint& b) { return { x + b.x, y + b.y }; }

	TPoint operator-(const TPoint& b) { return { x - b.x, y - b.y }; }

	TPoint operator*(int b) { return { x * b, y * b }; }

	void operator<<=(int trash) {
		x = -x;
		std::swap(x, y);
	}
	TPoint operator<<(int trash) {
		int X = x;
		int Y = y;
		X = -X;
		std::swap(X, Y);
		return { X,Y };
	}

	void operator>>=(int trash) {
		y = -y;
		std::swap(x, y);
	}
	TPoint operator>>(int trash) {
		int X = x;
		int Y = y;
		Y = -Y;
		std::swap(X, Y);
		return { X,Y };
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
	return prev == -255 || (curr - prev == 1 || prev - curr == depth - 1);
}


int snake(TPoint coord, TPoint dir, bool rotation, int scale) {
	std::cout << "||| " << scale << '\n';
	int current = ((scale - 2) * (scale - 2)) % depth;
	scale--; 
 
	int count = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < scale; i++) {
			std::cout << j << " | " << current << " | " << coord.x << ' ' << coord.y << " | " << scale << '\n';
			if (matrix[coord.y][coord.x] != current) return 0;
			current = (current + 1) % depth;
			coord = coord + dir;
			count++;
		}
		if (rotation) dir >>= 1;
		else dir <<= 1;
	}
	return count;
}


int snake_scale(TPoint coord, TPoint dir, bool rotation, int scale) {
	coord = coord + (dir >> 1) * (scale / 2) + (dir >> 1 >> 1) * (scale / 2-1);
	int max_scale = std::min(std::min(coord.x + 1, size - coord.x), std::min(coord.y + 1, size - coord.y)) * 2 + 1;

	TPoint keep_coord = coord;
	if (!snake(coord,dir, rotation, scale)) {
		std::cout << "FAILED\n";
		return 0;
	}
	for (int i = scale-2; i > 1; i -= 2) {
		coord = coord + dir;
		coord = coord + (dir << 1);
		if (!snake(coord, dir, rotation, i)) {
			return 0;
		}
	}
	coord = keep_coord;
	int snake_scale = scale;
	for (;snake_scale <= max_scale; snake_scale +=2) {
		coord = coord - dir;
		coord = coord - (dir << 1);
		if (!snake(coord, dir, rotation, snake_scale)) {
			break;
		}
	}
	snake_scale -= 2;
	return snake_scale;
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

	int final_scale = 1;
	int X = -1;
	int Y = -1;
	
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (matrix[y][x]) { continue; }
			int r = 0;
			for (int b = 0; b <= 1; b++) {
				for (int i = 0; i < 4; i++) {
					r = std::max(r,snake_scale({ x,y }, dirs[i], b, final_scale + 2));
				}
			}
			for (int i = 1;; i += 2) {
				if (i * i > r) {
					i-=2;
					r = i * i;
					break;
				}
			}
			if (r > final_scale) {
				final_scale = r;
				X = x;
				Y = y;
			}
		}
	}
	std::cout << final_scale * final_scale << '\n' << Y+1 << ' ' << X+1;

	return 0;
}
//*/