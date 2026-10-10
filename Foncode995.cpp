/*

#include <iostream>

using namespace std;


int mod = 1'000'000'007;
int64_t mod_pow(int64_t A, int p) {
	int64_t a = A;
	int64_t result = 1;
	while (p) {
		if (p & 1) {
			result *= a;
			result %= mod;
		}
		a *= a;
		a %= mod;
		p >>= 1;
	}
	return result;
}
//static_assert(mod_pow(2, 3) == 8);

int main() {
	int size;
	std::cin >> size;
	


	int64_t result = 1;

	int max_neg_val = 0;
	bool exclude = false;
	bool all_zeros = true;
	bool has_zero = false;
	int num_count = 0;
	for (int i = 0; i < size; i++) {
		int in; cin >> in;
		if (in != 0)
			all_zeros = false;
		else { 
			has_zero = true; 
			continue;
		}
		if (in < 0) {
			exclude = !exclude;

			if (max_neg_val == 0) {
				max_neg_val = in;
			}
			else if (in > max_neg_val) {
				max_neg_val = in;
			}
		}
		result *= in;
		num_count++;
		result %= mod;


	}

	if (all_zeros) {
		cout << '0';
		return 0;
	}
	
	if (exclude && max_neg_val != 0 && num_count > 1) {
		result *= mod_pow(max_neg_val, mod-2);
		num_count--;
		result %= mod;
	}


	if (num_count == 0) {
		if (has_zero) {
			cout << 0;
			return 0;
		}
	}
	if (result < 0 && has_zero) {
		result = 0;
	}

	while (result < 0) {
		result += mod;
	}


	cout << result;
}

//*/