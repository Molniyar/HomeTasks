/*
#include <iostream>
#include <algorithm>

bool debug = false;

int res_ind;
int check(int* array, int size, int x, int k) {
	int* keep = new int[size];
	for (int i = 0; i < size; i++) {
		keep[i] = array[i] - x >= 0 ? 1 : -1;
		if (debug) std::cout << keep[i] << ' ';
	}if (debug) std::cout << '\n';

	for (int i = 1; i < size; i++) {
		keep[i] += keep[i - 1];
		if (debug) std::cout << keep[i] << ' ';
	}if (debug) std::cout << " || \n";

	int res = -1;

	if (debug) std::cout << keep[k-1] << ' ';
	if (keep[k-1] >= 0 && res < k-1) {
		res = k-1;
	}
	for (int i = k; i < size; i++) {
		if (debug) std::cout << keep[i] - keep[i - k] << ' ';
		if (keep[i] - keep[i - k] >= 0 && res < i) {
			res = i;
		}
	}if (debug) std::cout << '\n';

	delete[] keep;

	return res;
}

int main() {
	int size; std::cin >> size;
	int k; std::cin >> k;
	
	
	int max_res = 0;
	int* tasks = new int[size];
	int* sorted = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin >> tasks[i];
		sorted[i] = tasks[i];

		if (tasks[i] > max_res)
			max_res = tasks[i];
	}

	std::sort(sorted, sorted + size);

	int result[3] = { 0, 0, 0 };

	int prev = -1;
	for (int i = 0; i < size; i++) {
		if (sorted[i] == prev) { continue; }
		if (debug) std::cout << " ,.,. " << sorted[i] << '\n';
		int ch = check(tasks, size, sorted[i], k);
		if (ch == -1) { break; }
		
		result[0] = sorted[i];
		result[1] = ch - k + 1;
		result[2] = ch;

		prev = sorted[i];
	}
	if (debug) std::cout << '\n';

	std::cout << result[0] << '\n' << result[1]+1 << ' ' << result[2]+1;

	delete[] tasks;
	delete[] sorted;

	return 0;
}

//*/