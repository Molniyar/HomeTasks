#include <iostream>
#include <algorithm>

//*
std::int64_t div_(std::int64_t a, std::int64_t b) {
	return a / b + (a % b != 0);
}

int main() {
	std::int64_t to_find; std::cin >> to_find;
	std::int64_t rows; std::cin >> rows;
	std::int64_t cols; std::cin >> cols;

	int floor = ((to_find - 1) / (rows * cols)) + 1;
	int floor_ = ((to_find - 1) % (rows * cols)) + 1;
	int y = ((floor_ - 1) / cols) + 1;
	int x = ((floor_ - 1) % cols) + 1;

	std::cout << floor << ' ' << y << ' ' << x;

	return 0;
}
//*/