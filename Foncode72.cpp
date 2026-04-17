#include <iostream>
#include <queue>

/*
struct coord {
	int x;
	int y;

	bool operator==(const coord& c) const { return (x == c.x && y == c.y); };
};

const int VOID = -1;
const int WALL = -2;
const int START = -3;
const int END = -4;
const int PATH = -5;

bool is_in_bounds(coord a, int size) {
	return a.x >= 0 && a.x < size && a.y >= 0 && a.y < size;
}

void debug_output(int size, int map[40][40]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			switch (map[i][j]) {
			case START: {
				std::cout << '@';
				break;
			}
			case END: {
				std::cout << 'X';
				break;
			}
			case WALL: {
				std::cout << 'O';
				break;
			}
			case PATH: {
				std::cout << '+';
				break;
			}
			case VOID: {
				std::cout << '.';
				break;
			}
			default: {
				std::cout << (char)(map[i][j] % 10 + '0');
			}
			}
		}
		std::cout << '\n';
	}
}

int main() {
	int size; std::cin >> size;
	coord start;
	coord end;
	int map[40][40];
	char read;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cin >> read;
			map[i][j] = VOID;
			switch (read) {
			case 'X': {
				end.y = i;
				end.x = j;
				break;
			}
			case '@': {
				start.y = i;
				start.x = j;
				break;
			}
			case 'O': {
				map[i][j] = WALL;
			}
			}
		}
	}
	
	std::queue<coord> coords;
	coords.push(start);
	map[start.y][start.x] = 0;

	while (coords.size()) {
		//debug_output(size, map);
		coord current = coords.front();
		coords.pop();
		if (is_in_bounds({ current.x + 1,current.y }, size) && (map[current.y][current.x + 1] == VOID || map[current.y][current.x + 1] > map[current.y][current.x]+1)) {
			coords.push({ current.x + 1,current.y });
			map[current.y][current.x+1] = map[current.y][current.x] + 1;
		}
		if (is_in_bounds({ current.x - 1,current.y }, size) && (map[current.y][current.x - 1] == VOID || map[current.y][current.x - 1] > map[current.y][current.x]+1)) {
			coords.push({ current.x - 1,current.y });
			map[current.y][current.x-1] = map[current.y][current.x] + 1;
		}
		if (is_in_bounds({ current.x,current.y + 1 }, size) && (map[current.y + 1][current.x] == VOID || map[current.y + 1][current.x] > map[current.y][current.x]+1)) {
			coords.push({ current.x,current.y + 1 });
			map[current.y+1][current.x] = map[current.y][current.x] + 1;
		}
		if (is_in_bounds({ current.x,current.y - 1 }, size) && (map[current.y - 1][current.x] == VOID || map[current.y - 1][current.x] > map[current.y][current.x]+1)) {
			coords.push({ current.x,current.y - 1 });
			map[current.y-1][current.x] = map[current.y][current.x] + 1;
		}
	}

	//debug_output(size, map);

	bool found_path = false;

	coord path = end;
	map[path.y][path.x] = PATH;
	while (map[path.y][path.x]) {
		coord next = {-1,-1};
		if (is_in_bounds({ path.x + 1,path.y }, size) && map[path.y][path.x + 1] > -1 && (next == coord{ -1, -1 } ? 1 : (map[path.y][path.x + 1] < map[next.y][next.x]))) {
			next.x = path.x + 1;
			next.y = path.y;
		}
		if (is_in_bounds({ path.x - 1,path.y }, size) && map[path.y][path.x - 1] > -1 && (next == coord{ -1,-1 } ? 1 : (map[path.y][path.x - 1] < map[next.y][next.x]))) {
			next.x = path.x - 1;
			next.y = path.y;
		}
		if (is_in_bounds({ path.x,path.y + 1 }, size) && map[path.y + 1][path.x] > -1 && (next == coord{ -1,-1 } ? 1 : (map[path.y + 1][path.x] < map[next.y][next.x]))) {
			next.x = path.x;
			next.y = path.y+1;
		}
		if (is_in_bounds({ path.x,path.y - 1 }, size) && map[path.y - 1][path.x] > -1 && (next == coord{ -1,-1 } ? 1 : (map[path.y - 1][path.x] < map[next.y][next.x]))) {
			next.x = path.x;
			next.y = path.y-1;
		}
		//std::cout << path.y << ' ' << path.x << '\n';
		if (next == coord{ -1, -1 } || next == start) break;
		path = next;
		map[path.y][path.x] = PATH;
		found_path = true;
	}

	if (!found_path) {
		std::cout << "N" << std::endl;
		return 0;
	}
	std::cout << "Y" << std::endl;

	map[start.y][start.x] = START;
	map[end.y][end.x] = PATH;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			switch (map[i][j]) {
			case START: {
				std::cout << '@';
				break;
			}
			case END: {
				std::cout << 'X';
				break;
			}
			case WALL: {
				std::cout << 'O';
				break;
			}
			case PATH: {
				std::cout << '+';
				break;
			}
			default: std::cout << '.';
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
//*/