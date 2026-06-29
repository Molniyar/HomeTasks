/*
#include <iostream>
using namespace std;

int64_t length = 0; 
int64_t expected; 
int64_t* arr;

int64_t solution_special_for_1() {
	int64_t result = 0;
	int64_t in_row = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] != 1) {
			result += (in_row * (in_row + 1)) / 2;
			in_row = 0;
			continue;
		}
		in_row++;
	}
	result += (in_row * (in_row + 1)) / 2;

	return result;
}

int64_t solution() {
	int64_t result = 0;

	int64_t addition = 1;

	for (int64_t i = 0; i < length; i++) {
		if (arr[i] == 1) {
			addition++;
			continue;
		}
		int64_t check = 1;
		for (int64_t j = i; j < length && check <= expected; j++) {
			if (arr[j] != 1) {
				int64_t keep = check;
				check *= arr[j];
				if (check / arr[j] != keep) {
					break;
				}
			}
			if (check == expected) {
				result += addition;
			}
		}
		addition = 1;
	}

	return result;
}


int main() {
	cin >> length;
	std::cin >> expected;

	arr = new int64_t[length];
	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}

	if (expected == 1) {
		std::cout << solution_special_for_1();
	}
	else if (expected == 0) {
		std::cout << '0';
	}
	else {
		std::cout << solution();
	}
	
	delete arr;
	
	return 0;
}
//*/