#include <iostream>
#include <cmath>

int size;

const int OUT_OF_BOUNDS = -1;
const int EMPTY = 0;
const int WHITE = 1;
const int BLACK = 2;
const int BLACK_X = 3;
const int EATEN = 4;

int is_in_bounds(int x, int y) {
	return x >= 0 && x < size && y >= 0 && y < size;
}

struct TPoint
{
	int x = 0;
	int y = 0;

	TPoint operator+(const TPoint& b) { return { x + b.x, y + b.y}; }

	TPoint operator-(const TPoint& b) { return { x - b.x, y - b.y }; }
};

//*
struct TPole
{
	int map[10][10];

	//int* operator[](int y) { return map[y]; }

	int get(int x, int y) { return is_in_bounds(x,y) ? map[y][x] : OUT_OF_BOUNDS; }

	void set(int x, int y, int value) { if (is_in_bounds(x,y)) map[y][x] = value; }
	void set(const TPoint &p, int value) { if (is_in_bounds(p.x,p.y)) map[p.y][p.x] = value; }

	int operator()(int x, int y) { return get(x,y); }
	int operator()(const TPoint &v) { return get(v.x, v.y); }
};



TPole board;
TPole test_board;
TPole prev_board;

const TPoint dirs[4] = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };

int eats(TPoint pos, int count) {
	//std::cout << x << ' ' << y << '\n';
	int min = 101;
	
	for (TPoint dir : dirs){
		if (test_board(pos + dir) == WHITE && test_board(pos + dir + dir) == EMPTY) {
			test_board.set(pos+dir, EATEN);
			min = std::min(min,eats(pos + dir + dir, count+1));
			//std::cout << "+x +y\n";
		}
	}
	//std::cout << min << ' ' << count << '\n';
	if (min == 101) {
		return count;
	}
	return min;
}



int eats_x(TPoint point, int count) {
	int min = 101;
	for (TPoint dir : dirs) {
		int eaten = 0;
		for (TPoint p = point + dir;test_board(p) != OUT_OF_BOUNDS ; p = p + dir) {
			if (test_board(p) == WHITE) {
				test_board.set(p, EATEN);
				if (eaten == 1)
					break;
				eaten++;
			}
			else if (test_board(p) == EMPTY) {
				if (eaten == 1) {
					int f = eats_x(p, count + 1);
					if (f > count) min = std::min(min, f);
				}
			}
			else {
				break;
			}
		}
	}
	
	if (min == 101) {
		std::cout << count << '\n';
		return count;
	}
	return min;
}

int main() {
	std::cin >> size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board.set(j, i, EMPTY);
		}
	}
	int whites; std::cin >> whites;
	int blacks; std::cin >> blacks;
	int blacks_x; std::cin >> blacks_x;
	int x;
	int y;
	for (int i = 0; i < whites; i++) {
		std::cin >> x;
		std::cin >> y;
		board.set(x-1, y-1, WHITE);
	}
	for (int i = 0; i < blacks; i++) {
		std::cin >> x;
		std::cin >> y;
		board.set(x-1, y-1, BLACK);
	}
	for (int i = 0; i < blacks_x; i++) {
		std::cin >> x;
		std::cin >> y;
		board.set(x-1, y-1, BLACK_X);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board(j, i) == BLACK) {
				//copy(board,test_board);
				test_board = board;
				if (eats({ j, i }, 0) == whites) {
					std::cout << "Yes";
					return 0;
				}
			}
			//*
			if (board(j, i) == BLACK_X) {
				//copy(board, test_board)
				test_board = board;
				if (eats_x({i, j}, 0) >= whites) {
					std::cout << "Yes";
					return 0;
				}
			}
			//*/
		}
	}
	std::cout << "No";
	return 0;
}
//*/