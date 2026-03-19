#include <iostream>

/*
int main() {
	int size; std::cin >> size;

	int colors[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int required[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	char read;
	for (int i = 0; i < size; i++) {
		std::cin >> read;
		//std::cout << "|" << read << '\n';
		colors[read - 'A']++;
	}

	int sum = 0;
	int read_int;
	while (sum < size) {
		std::cin >> read_int;
		std::cin >> read;
		//std::cout << "||" << read_int << ' ' << read << '\n';
		required[read - 'A'] = read_int;
		sum += read_int;
		if (sum >= size) break;
	}
	int result = 0;
	for (int i = 0; i < 26; i++) {
		result += std::max(0,required[i]-colors[i]);
	}

	std::cout << result;
}
//*/