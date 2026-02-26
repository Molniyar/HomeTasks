#include <iostream>

/*
int main() {
	unsigned long long inp1; std::cin >> inp1;
	unsigned long long inp2; std::cin >> inp2;
	unsigned long long hits1 = 0;
	unsigned long long hits2 = 0;
	while (inp1 - inp2) {
		unsigned long long& MAX = inp1 > inp2 ? inp1 : inp2;
		unsigned long long& HITS = inp1 < inp2 ? hits1 : hits2;
		unsigned long long MIN = inp1 < inp2 ? inp1 : inp2;
		unsigned long long keep = MAX % MIN;
		HITS += keep > 0 ? MAX/MIN : MAX/MIN-1;
		MAX = keep > 0 ? keep : MIN;
		std::cout << "||" << inp1 << ' ' << inp2 << '\n';
	}
	std::cout << hits1 << ' ' << hits2 << ' ' << inp1;
	return 0;
}
//*/