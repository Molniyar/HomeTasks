#include <iostream>
#include <vector>
using namespace std;

double myPow(double x, int n) {
	bool is_negative = false;
	double result = 1;
	double multiple = x;
	int current_bit = 0x1;
	if (n < 0) {
		is_negative = true;
		n = -n;
	}

	for (int i = 0; i < 32; i++) {
		cout << "curr_bit=" << current_bit << ";\tmultiple=" << multiple << ";\tresult=" << result << ";\tbit=" << bool(n & current_bit) << '\n';
		if (n & current_bit) {result *= multiple;}
		multiple *= multiple;
		current_bit <<= 1;
	}
	return is_negative ? 1.0 / result : result;
}

int main() {
	cout << myPow(2, 8) << '\n';
	cout << myPow(2, -1) << '\n';
	cout << myPow(2, -200000000) << '\n';
	cout << myPow(1.00001, 123456) << '\n';
	cout << myPow(2, -2147483648) << '\n'; 
	return 0;
}