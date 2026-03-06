#include <iostream>
#include <iomanip>


/* uncomment here to make it work
int main() {
	double input; std::cin >> input;
	if (input == 1) { 
		std::cout << '1'; 
		return 0; 
	}
	std::cout << std::setprecision(10);

	double max = input;
	double min = 0;

	for (int i = 0;i < 64;i++) {
		double x = (min + max) / 2;
		double x2 = x * x;
		double compare = x2 * x2 * x;

		if (compare == input || min == max) {
			std::cout << (max + min) / 2;
			return 0;
		}
		else if (compare > input) max = x;
		else min = x;

		//std::cout << max << ' ' << min << '\n';
	}
	std::cout << (max+min)/2;

	return 0;
}
//*/
