#include <iostream>
#include <map>
/*
int main() {
	int size; std::cin >> size;

	std::map<int, int> divs;
	int read;
	for (int i = 0; i < size; i++) { 
		std::cin >> read;
		for (int j = 2; (read/j) >= j; j++) {
			if (read % j == 0) {
				divs[j]++;
				while (read % j == 0) read /= j;
			}
		}
		if (read != 1) divs[read]++;
	}

	int result = 0;
	for (auto i:divs) {
		std::cout << i.first << ' ' << i.second << '\n';
		if (i.second > result) result = i.second;
	}

	std::cout << result;
}
//*/