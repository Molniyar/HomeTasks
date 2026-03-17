#include <iostream>

//*
int main() {
	std::string input; std::cin >> input;

	int result = 0;

	for (int i = 0; i < 9; i++) {
		result += (i + 1) * (input[8 - i]-'0');
	}


	if (result >= 101) { result %= 101; }
	if (result == 100) { result = 0; }


	if (result < 10) {std::cout << '0';}
	std::cout << result;
}
//*/