#include <iostream>
#include <cmath>

/*
int main() {
	int size; std::cin >> size;
	int score = 0;
	double x;
	double y;
	std::string num;
	for (int i = 0; i < size; i++) {
		std::cin >> x;
		std::cin >> y;
		bool c1 = (5 * x + -7.5 * y + 37.5) >= 0;
		bool c2 = (5 * x + 7.5 * y + -37.5) <= 0;
		bool c3 = (-15 * x + 2.5 * y + 37.5) >= 0;
		bool c4 = (-15 * x + -2.5 * y + -37.5) <= 0;
		bool c5 = y >= -3;
		
		bool c6 = (2 * x + -2 * y + 4) >= 0;
		bool c7 = (2 * x + 2 * y + 4) >= 0;
		bool c8 = x-y <= 0;
		bool c9 = x+y >= 0;
		std::cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << ' ' << c5 << " | " << c6 << ' ' << c7 << ' ' << c8 << ' ' << c9 << '\n';
		if (c1 && c2 && c3 && c4 && c5 && !(c6 && c7 && c8 && c9)) {
			//std::cout << "yes!\n";
			y -= 3.0;
			double distance = std::sqrt(x * x + y * y);
			if (distance <= 1) score += 10;
			else if (distance <= 2) score += 9;
			else if (distance <= 3) score += 8;
			else if (distance <= 4) score += 7;
			else if (distance <= 5) score += 6;
			else score += 5;
			//std::cout << score << '\n';
		}
		//else std::cout << "no\n";
	}

	std::cout << score;

	return 0;
}
//*/