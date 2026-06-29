/*

#include <iostream>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;

bool debug = false;




constexpr int gcd(int a, int b) {
	while (a != b && a!=0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else b %= a;
	}
	return std::max(a,b);
}
static_assert(gcd(4, 4) == 4);
static_assert(gcd(4*2, 4) == 4);
static_assert(gcd(3*5, 5*5) == 5);

constexpr int64_t multiply(uint64_t a, uint64_t b) {
	uint64_t x = a * b;
	return (x <= 0x7FFFFFFFFFFFFFFF && x / a == b) ? x : 0;//
}

constexpr int64_t pow_64(int64_t x, int64_t n) {
	int64_t multiple = x;
	//std::cout << multiple << '\n';
	int64_t result = 1;
	for (int64_t i = 0; i <= 61; i++) {
		if (n & (1ll << i)) {
			result = multiply(result, multiple);
			n ^= (1ll << i);
		}
		if (!n) break;
		int64_t a = multiply(multiple, multiple);
		if (!a) return 0;
		multiple = a;
	}
	return result;
}
static_assert(pow_64(2, 8) == 256);
static_assert(pow_64(5, 2) == 25);
static_assert(pow_64(256, 1) == 256);
static_assert(pow_64(2, 62) == 4611686018427387904);
static_assert(pow_64(2, 63) == 0);


constexpr int64_t root(int64_t a, int p) {
	//std::cout << a << ' ' << p << '\n';
	int64_t result = 1;
	int64_t bits = 1;
	while (pow_64(result,p) <= a){
		if (pow_64(result, p) == 0) break;
		//std::cout << "pow_64(" << result << ", " << p << ") = " << pow_64(result, p) << '\n';
		result <<= 1;
		bits++;
	}result >>= 1;
	bits--;
	for (int64_t i = bits-1; i >= 0; i--) {
		int64_t check = pow_64(result | (1ll << i), p);
		if (check <= a && check != 0) {
			result |= (1ll << i);
		}
	}

	return result;
}
constexpr pair<int64_t, int64_t> root_auto(int64_t a) {
	int64_t x = a;
	int64_t p = 1;
	for (int i = 62; i >= 1; i--) {
		int64_t x_ = root(a, i);
		if (x_ > 1 && pow_64(x_, i) == a) {
			x = x_;
			p = i;
			break;
		}
	}
	return { x,p };
}
//static_assert(root_auto(27).first == 3 && root_auto(27).second == 3);
//static_assert(root_auto(1728).first == 12 && root_auto(1728).second == 3);


map<int64_t, int64_t> get_prime_factors(int64_t num) {
	map<int64_t, int64_t> multiples;

	int64_t div = 2;
	while (num / div >= div) {
		if (num % div == 0) {
			multiples[div]++;
			num /= div;
		}
		else {
			if (debug) std::cout << "%%% " << multiples[div] << '\n';
			div++;
		}
	}multiples[num]++;
	if (debug) std::cout << "%%% " << multiples[div] << '\n';

	return multiples;
}

int64_t solution(int64_t num) {
	if (num == 1) return 1;

	auto r = root_auto(num);
	int64_t x = r.first;
	int64_t p = r.second;

	if (p == 1) {
		return x;
	}
	if (p == 2) {
		return x;
	}
	
	map<int64_t, int64_t> prime_factors = get_prime_factors(x);


	int64_t result = -1;
	for (int i = 1; i <= p; i++) {
		int64_t power = 1;
		for (auto obj : prime_factors) {
			//power *= obj.second * i + 1;
			power = multiply(power, multiply(obj.second, i) + 1);
		}
		//power *= i;
		power = multiply(power, i);
		power /= 2;
		if (power >= p) {
			return pow_64(x, i);
		}
		//result = pow_64(x, i);
	}

	return result;
}

int main() {
	//*
	std::int64_t num; std::cin >> num;
	std::cout << solution(num);
	//
	//std::cout << solution(0x7FFFFFFFFFFFFFCF);
	//cout << pow_64(264, 8); // MUST return 18
	/*
	int failed = 0;
	for (int i = 2; i < 1000'000; i++) {
		int64_t input = -1;
		int64_t power = 1;
		map<int64_t, int64_t> prime_factors = get_prime_factors(i);
		for (auto obj : prime_factors) {
			power = multiply(power, obj.second + 1);
		}
		if (power & 1) {
			input = root(i, 2);
			input = pow_64(input, power);
		}
		else {
			power /= 2;
			input = pow_64(i, power);
		}
		if (input == 0) { continue; }
		//std::cout << "==  testing " << i << ": " << input;
		int64_t r = solution(input);
		if (r == i) {
			//std::cout << "\t--  passed: " << i << '\n';
		}
		else { 
			std::cout << "\t--  FAILED - expected: " << i << ", but got " << r << " instead;" << '\n';
			failed++;
			//std::cout << ">>> fails: " << failed << '\n';

			string _;std::cin >> _;
			if (1) continue;
			return 0;
		}
	}
	


	std::cout << ">> FAILS: " << failed << '\n';
	//

	return 0;
}

//*/