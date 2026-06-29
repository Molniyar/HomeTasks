#include <iostream>

/*

bool has_up(const char& c) {
	return c == 'L' || c == 'B';
}
bool has_down(const char& c) {
	return c == 'R' || c == 'B';
}

int main() {
	std::string input; std::cin >> input;
	int up = 0;
	int down = 1;
	for (int i = 0; i < input.size(); i++) {
		if (has_up(input[i])) {
			up++;
		}
		if (has_down(input[i])) {
			down++;
		}
		if (up > down + 1) {
			up = down + 1;
		}
		if (down > up + 1) {
			down = up + 1;
		}
	}
	std::cout << down;

	return 0;
}

//*/