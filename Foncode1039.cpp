#include <iostream>

/*
int mul(int a, int b) {
	return (a * b) % 10;
}
int pow(int n, int p) {
	int result = 1;
	for (int j = 0; j < 31; j++, n = mul(n,n)) {
		if (p & (1<<j)) {
			result = mul(result,n);
			//std::cout << result << ' ' << j << '\n';
		}
	}
	return result;
}
int main() {
	int read;
	int result = 1;
	bool had_non_zero = false;
	for (int i = 0; i < 10; i++) {
		std::cin >> read;
		if (read && i) had_non_zero = true;
		result = mul(result,pow(i, read));
	}

	std::cout << (had_non_zero?result:0);
}

//*/