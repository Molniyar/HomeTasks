#include <iostream>
#include <algorithm>

//*
int main() {
	std::string num; std::cin >> num;
	char denyed; std::cin >> denyed;

	char min = '0';
	if (denyed == 0) min = '1';

	int denyed_index = 0;
	for (; denyed_index < num.size() && num[denyed_index] != denyed; denyed_index++) {}
	
	if (denyed == '9') {
		num[denyed_index] = '0';
		if (denyed_index == 0) std::cout << '1';
		else num[denyed_index - 1]++;
	}
	else num[denyed_index]++;

	for (int i = denyed_index + 1; i < num.size(); i++) {
		num[i] = min;
	}

	std::cout << num;
}
//*/