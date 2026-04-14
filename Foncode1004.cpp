#include <iostream>

//*

int main() {
	int days; std::cin >> days;
	int to_forget; std::cin >> to_forget;
	int temp; std::cin >> temp;

	int forgot = 0;

	int prev_days = 100;
	bool is_colder = 0 < temp;
	int read;

	for (int i = 0; i < days; i++) {
		std::cin >> read;
		prev_days++;
		bool current_colder = read < temp;
		if (is_colder != current_colder) {
			if (prev_days >= to_forget) {
				forgot++;
			}
			prev_days = 0;
		}
		is_colder = current_colder;
	}

	std::cout << forgot;

	return 0;
}
//*/