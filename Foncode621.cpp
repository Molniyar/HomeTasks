#include <iostream>
#include <algorithm>

/*
int main() {
	int size; std::cin >> size;

	int count = 0;
	int max = 0;

	int prev_width = 101;
	int sum_height = 0;
	int width;
	int height;
	for (int i = 0; i < size; i++) {
		std::cin >> width;
		std::cin >> height;
		if (width < prev_width) {
			sum_height += height;
			prev_width = width;
			continue;
		}
		if (sum_height > max) max = sum_height;
		count++;
		prev_width = width;
		sum_height = height;
	}

	if (sum_height > max) max = sum_height;
	count++;

	std::cout << count << ' ' << max;
}
//*/