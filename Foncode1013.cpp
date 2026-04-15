#include <iostream>
#include <algorithm>

/*

int main() {
	std::int64_t in1; std::cin >> in1;
	std::int64_t in2; std::cin >> in2;
	std::int64_t in3; std::cin >> in3;

	std::int64_t results[6];
	results[0] = in1 * in3 % in2 == 0 ? in1 * in3 / in2 : -1;// mods[0] += in1 % (in2 / in3 == 0 ? 1 : in2 / in3);
	results[1] = in2 * in3 % in1 == 0 ? in2 * in3 / in1 : -1;// mods[1] += in2 % (in1 / in3 == 0 ? 1 : in1 / in3);
	results[2] = in1 * in2 % in3 == 0 ? in1 * in2 / in3 : -1;// mods[2] += in1 % (in3 / in2 == 0 ? 1 : in3 / in2);
	results[3] = in3 * in2 % in1 == 0 ? in3 * in2 / in1 : -1;// mods[3] += in3 % (in1 / in2 == 0 ? 1 : in1 / in2);
	results[4] = in2 * in1 % in3 == 0 ? in2 * in1 / in3 : -1;// mods[4] += in2 % (in3 / in1 == 0 ? 1 : in3 / in1);
	results[5] = in3 * in1 % in2 == 0 ? in3 * in1 / in2 : -1;// mods[5] += in3 % (in2 / in1 == 0 ? 1 : in2 / in1);

	std::sort(results, results + 6);

	std::int64_t prev = -1;
	for (int i = 0; i < 6; i++) {
		if (results[i] != -1 && results[i] != prev) {
			std::cout << results[i] << ' ';
			prev = results[i];
		}
	}
	if (prev == -1)
		std::cout << -1;
	return 0;
}
//*/