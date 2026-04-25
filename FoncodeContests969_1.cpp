#include <iostream>

/*

int main() {
	std::string str; std::cin >> str;
	int sum = 0;
	int curr = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			sum += curr;
			curr = 0;
			continue;
		}
		curr *= 10;
		curr += str[i] - '0';
	}
	sum += curr;
	std::cout << sum;
	return 0;
}
//*/