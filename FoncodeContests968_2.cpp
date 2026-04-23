#include <iostream>
#include <cmath>

/*
bool debug = true;
int dif(int a, int b) {
	return std::max(a, b) - std::min(a, b);
}
int points[100000][2];
int lines[100000][4];
int main() {
	int size; std::cin >> size;
	int p_size = 0;
	int l_size = 0;
	char type;
	int read;
	for (int i = 0; i < size; i++) {
		std::cin >> type;
		if (type == 'P') {
			std::cin >> points[p_size][0];
			std::cin >> points[p_size][1];
			//std::cout << p_size << ' ' << points[p_size][0] << ' ' << points[p_size][1] << '\n';
			p_size++;
			continue;
		}
		std::cin >> lines[l_size][0];
		std::cin >> lines[l_size][1];
		std::cin >> lines[l_size][2];
		std::cin >> lines[l_size][3];
		l_size++;
	}

	for (int i = 0; i < p_size; i++) {
		int crosses_lines = 0;
		int crosses_points_up = 0;
		int crosses_points_down = 0;
		for (int j = 0; j < l_size; j++) {
			bool c = false;
			if (lines[j][1] == lines[j][3] || (points[i][1] < lines[j][1] && points[i][1] < lines[j][3]) || (points[i][1] > lines[j][1] && points[i][1] > lines[j][3])) {
				continue;
			}
			if (points[i][1] == lines[j][1] && lines[j][0] >= points[i][0]) {
				crosses_points_up++;
				c = true;
			}
			if (points[i][1] == lines[j][3] && lines[j][2] >= points[i][0]) {
				crosses_points_down++;
				c = true;
			}
			if (c) continue;
			int a = dif(lines[j][1], points[i][1]);
			int b = dif(lines[j][1], lines[j][3]);
			if (b == 0) {
				//crosses_lines++;
				std::cout << "AAA\n";
				continue;
			}
			int cross_coord = std::min(lines[j][0], lines[j][2]) + dif(lines[j][0], lines[j][2]) * (a / b);
			std::cout << "|]" << cross_coord << '\n';
			if (cross_coord >= points[i][0])
				crosses_lines++;
			std::cout << "||" << lines[j][0] << ' ' << lines[j][1] << ' ' << lines[j][2] << ' ' << lines[j][3] << ' ' << crosses_lines << '\n';
		}
		std::cout << crosses_lines << ' ' << crosses_points_up << ' ' << crosses_points_down << '\n';
		crosses_lines += std::min(crosses_points_up, crosses_points_down);
		std::cout << crosses_lines << '\n';
		if (crosses_lines & 1) {
			std::cout << "Yes";
			return 0;
		}
	}

	std::cout << "No";

	return 0;
}
//*/