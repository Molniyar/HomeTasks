/*

#include <iostream>

using namespace std;

int64_t to_compare_with(int64_t p1, int64_t p2, int64_t p3, int64_t res) {
	return (p1 >> 1) - res + (((p2 >> 1) + (p3 >> 1) - res) >> 1);
}

int main() {
	int64_t p1; cin >> p1;
	int64_t p2; cin >> p2;
	int64_t p3; cin >> p3;

	int64_t min = 0;
	int64_t max = 0;
	if (p1 > max) max = p1;
	if (p2 > max) max = p2;
	if (p3 > max) max = p3;


	int64_t mid = (max + min) >> 1;
	while (min < max-1) {
		int64_t dif = (max - min) >> 1;
		mid = (max + min) >> 1;

		//cout << min << ' ' << max << ' ' << dif << '\n';

		if (to_compare_with(p1, p2, p3, mid) < mid) {
			max -= dif;
		}
		else if (to_compare_with(p1, p2, p3, mid) > mid) {
			min += dif;
		}
		else break;
	}
	//cout << min << ' ' << max << '\n';
	
	cout << mid;
	return 0;
}

//*/