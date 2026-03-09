#include <iostream>

/* not finished yet (╯‵□′)╯︵┻━┻
int main() {
	int n_commands; std::cin >> n_commands;
	int pos_in_queue; std::cin >> pos_in_queue;

	int S = 0;
	int M = 0;
	int L = 0;
	char read;
	for (int i = 0; i < n_commands * 3; i++) {
		std::cin >> read;
		switch (read) {
		case 'S': { S++; break; }
		case 'M': { M++; break; }
		case 'L': { L++; break; }
		}
	}
	if (S < (pos_in_queue-1)*3 || M < (pos_in_queue - 1)*3 || L < (pos_in_queue - 1)*3) {
		std::cout << "NO";
	}
	else std::cout << "YES";
}
//*/