#include <iostream>

/*
int main() {
	std::string input; 
	std::cin >> input; // чтение длинны просто по приколу
	std::cin >> input;
	int del = 0;
	int pos = input.size() - 1;
	for (int i = input.size() - 1; i >= 0; i--) {
		if (input[i] == '<') {
			del++;
			continue;
		}
		if (del == 0) {
			input[pos] = input[i];
			pos--;
			continue;
		}
		del--;
	}
	std::cout << input.substr(pos+1);
}
//*/