#include <iostream>

/*
int main() {
	int arg1; std::cin >> arg1;
	int arg2; std::cin >> arg2;

	while (arg1 != arg2 && arg1 && arg2) {
		//std::cout << "|" << arg1 << ' ' << arg2 << '\n';
		if (arg1 > arg2) {
			arg1 %= arg2;
			continue;
		}
		arg2 %= arg1;
	}
	if (arg2 > arg1)arg1 = arg2;
	arg2 = arg1;
	//std::cout << arg1 << '\n';

	for (int i = 1;i <= arg2 ; i++) {
		if (arg1 % i == 0) {
			//std::cout << i << '\n';
			if (arg1/i <= i) {
				std::cout << arg1/i;
				return 0;
			}
		}
	}
}
//*/