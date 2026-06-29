/*
#include <iostream>
using namespace std;


void add(int64_t& a, int64_t b) {
	if (b < 0) return;
	a += b;
}

int64_t ways_to_get_nums(int64_t x) {
	int64_t result = 0;

	add(result, x);
	add(result, x);
	add(result, x - 1);
	add(result, x - 3);

	//add(result, (((x - 1) >> 2) << 1) - (((x - 1) & ((1 << 2) - 1)) ? 0 : 1));
	//add(result, (((x - 1) >> 2) << 1) - (((x - 1) & ((1 << 2) - 1)) ? 0 : 1) -2);
	//add(result, x / 2 - 4);
	for (int i = 2; i < 60; i++) {
		int64_t addition = (((x - 1) >> i) << 1) - (((x - 1ll) & ((1ll << i) - 1ll)) ? 0 : 1);
		add(result, addition);
		add(result, addition - 2);
	}

	return result;
}

int main() {
	int64_t from; cin >> from;
	int64_t to;   cin >> to;

	cout << ways_to_get_nums(to) - ways_to_get_nums(from-1);
	return 0;
}
//*/