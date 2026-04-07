#include <iostream>

//*

double lambda_test(double a, double b, double k) {
	return (a * b * (k + 1)) + ((a - b) * ((k + 1) * k / 2)) - (k * (k + 1) * (2 * k + 1) / 6);
}
std::int64_t lambda(std::int64_t a, std::int64_t b, std::int64_t k) {
	return (a * b * (k + 1))  +  ((a - b) * ((k + 1) * k / 2))  -  (k * (k + 1) * (2 * k + 1) / 6);
}
int main() {
	bool debug = true;

	int size; std::cin >> size;
	std::int64_t a;
	std::int64_t b;
	std::int64_t r;
	for (int i = 0; i < size; i++) {
		std::cin >> a;
		std::cin >> b;
		std::cin >> r;


		std::int64_t PREV_MIN = 0;
		std::int64_t MIN = 1;
		for (double x = 0;x > 1e18 && x < -1e18; ) {
			PREV_MIN = MIN;
			MIN <<= 1;
			x = lambda_test(a, b, MIN);
			if (debug) std::cout << "||||" << PREV_MIN << ' ' << MIN << ' ' << x << '\n';
		}
		//*
		for (int iter = 0; iter < 256 && PREV_MIN + 1 < MIN; iter++) {
			int mid = (PREV_MIN + MIN) >> 1;

			if (debug) std::cout << "|||" << PREV_MIN << ' ' << mid << ' ' << MIN << " | " << lambda_test(a, b, mid) << '\n';

			if (lambda_test(a, b, mid) <= 1e18 || lambda_test(a, b, mid) >= -1e18) {
				MIN = mid;
			}
			else PREV_MIN = mid;
		}//*/
		MIN = PREV_MIN;

		if (debug) std::cout << "MIN = " << MIN << '\n';

		std::int64_t PREV_MAX = 1;
		std::int64_t MAX = MIN+1;// everything`s not that easy

		for (double x = 0;x <= 1e18 && x >= -1e18; ) {
			PREV_MAX = MAX;
			MAX <<= 1;
			x = lambda_test(a, b, MAX);
			if (debug) std::cout << "||||" << PREV_MAX << ' ' << MAX << ' ' << x << '\n'; 
		}
		//*
		for (int iter = 0; iter < 256 && PREV_MAX + 1 < MAX; iter++) {
			int mid = (PREV_MAX + MAX) >> 1;

			if (debug) std::cout << "|||" << PREV_MAX << ' ' << mid << ' ' << MAX << " | " << lambda_test(a,b,mid) << '\n';

			if (lambda_test(a, b, mid) > 1e18 || lambda_test(a, b, mid) < -1e18) {
				MAX = mid;
			}
			else PREV_MAX = mid;
		}//*/

		MAX = PREV_MAX;

		if (debug) std::cout << "MAX = " << MAX << '\n';

		std::int64_t min = MIN;
		std::int64_t max = MAX;

		for (int iter = 0; iter < 256 && min + 1 < max; iter++) {
			std::int64_t mid = (min + max) >> 1;

			std::int64_t left = lambda(a, b, mid - 1);
			std::int64_t current = lambda(a, b, mid);
			std::int64_t right = lambda(a, b, mid + 1);

			if (debug) std::cout << "||" << min << ' ' << mid << ' ' << max << " | " << left << ' ' << current << ' ' << right << " | " << std::abs(current - left) << ' ' << std::abs(right - current) << '\n';

			if (std::abs(current - left) < std::abs(right - current)) {
				max = mid;
			}
			else min = mid;
		}
		if (debug) std::cout << "|" << min << ' ' << max << '\n';

		std::int64_t min1 = 0;
		std::int64_t max1 = max;
		std::int64_t min2 = max;
		std::int64_t max2 = MAX;

		if (lambda(a, b, 0) > lambda(a, b, min)) {
			std::swap(min1, min2);
			std::swap(max1, max2);
		}

		for (int iter = 0; iter < 512 && min1 + 1 < max1; iter++) {//  / up
			std::int64_t mid = (min1 + max1) >> 1;
			if (debug) std::cout << "//" << min1 << ' ' << mid << ' ' << max1 << '\n';
			if (lambda(a, b, mid) < r) {
				min1 = mid;
			}
			else max1 = mid;
		}

		for (int iter = 0; iter < 512 && min2 + 1 < max2; iter++) {//  \ down
			std::int64_t mid = (min2 + max2) >> 1;
			if (debug) std::cout << "\\\\" << min2 << ' ' << mid << ' ' << max2 << '\n';
			if (lambda(a, b, mid) > r) {
				min2 = mid;
			}
			else max2 = mid;
		}
		int res1 = lambda(a, b, min1) == r ? min1 : lambda(a, b, max1) == r ? max1 : -1;
		int res2 = lambda(a, b, min2) == r ? min2 : lambda(a, b, max2) == r ? max2 : -1;
		if (res1 == res2) {
			res2 = -1;
		}

		if (lambda(a, b, 0) > lambda(a, b, min)) {
			std::swap(res1, res2);
		}

		std::cout << (bool)(res1 + 1) + (bool)(res2 + 1) << ' ';
		if (res1 != -1) {
			std::cout << res1 << ' ';
		}
		if (res2 != -1) {
			std::cout << res2 << ' ';
		}
		std::cout << '\n';
	}
}
//*/