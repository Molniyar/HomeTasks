#include <iostream>

/*
int main() {
	int size; std::cin >> size;

	int chars_in_first[26];
	int chars_in_second[26];
	for (int i = 0; i < 26; i++) {
		chars_in_first[i] = 0;
		chars_in_second[i] = 0;
	}

	char read;
	for (int i = 0; i < size; i++) {
		std::cin >> read;
		chars_in_first[read - 'a']++;
	}
	for (int i = 0; i < size; i++) {
		std::cin >> read;
		chars_in_second[read - 'a']++;
	}


	for (int i = 0; i < 26; i++) { 
		if (chars_in_first[i] != chars_in_second[i]) {
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES";
	return 0;
}
//*/