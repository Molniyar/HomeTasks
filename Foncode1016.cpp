#include <iostream>
#include <string>

/*
int main() {
	int size; std::cin >> size;
	std::int64_t min = 0;
	std::int64_t max = 0;

	int read_min = 0;
	int read_max = 0;
	char read;
	std::string input; std::getline(std::cin, input); std::getline(std::cin, input);

	for (int i = 0, a = 0; i < input.size(); i++,a++) {
		read = input[i];
		if (read == ' ') {
			//std::cout << "debug: " << read_min << ", " << read_max << "\n";
			min += read_min;
			max += read_max;
			read_min = 0;
			read_max = 0;
			a = -1;
			continue;
		}
		read_min *= 10;
		read_max *= 10;
		if (a < 2) {
			read_min += read-'0';
			read_max += read-'0';
		}
		else {
			read_min += 0;
			read_max += 9;
		}
	}
	//std::cout << "debug: " << read_min << ", " << read_max << "\n";
	min += read_min;
	max += read_max;
	std::cout << min << ' ' << max;
	return 0;
}
//*/