/*
#include <iostream>
void check_price_sum(int& sum, int& res_a, int& res_b, int check_a, int check_b, int index_a, int index_b) {
	if (check_a > 100 || check_b > 100) return;

	if (check_a + check_b < sum) {
		res_a = index_a;
		res_b = index_b;
		sum = check_a + check_b;
		return;
	}
	if (check_a + check_b == sum) {
		if (res_a > index_a) { 
			res_a = index_a;
			res_b = index_b;
			return;
		}
		if (res_a == index_a && res_b > index_b) {
			//res_a = index_a;
			res_b = index_b;
			return;
		}
	}
}

int main() {
	int len; std::cin >> len;

	int a_index = -1;
	int b_index = -1;
	int prev_both_index = -1;
	int both_index = -1;

	int a_price = 256;
	int b_price = 256;
	int prev_both_price = 256;
	int both_price = 256;

	int a_cont = 1;
	int b_cont = 2;
	int prev_both_cont = 3;
	int both_cont = 3;

	std::string read;
	int price;
	for (int i = 0; i < len; i++) {
		std::cin >> read;
		std::cin >> price;
		int contains = 0;
		for (int j = 0; j < read.size() && contains != 3; j++) {
			if (read[j] == 'a' || read[j] == 'A') contains |= 1;
			if (read[j] == 'b' || read[j] == 'B') contains |= 2;
			//std::cout << read[j];
		}
		//std::cout << contains << '\n';
		switch (contains) {
		case 1: {
			if (a_price <= price) break;
			a_index = i;
			a_price = price;
			break; 
		}
		case 2: {
			if (b_price <= price) break;
			b_index = i;
			b_price = price;
			break; 
		}
		case 3: {
			if (prev_both_price <= price) {
				if (both_price <= price) break;
				//prev_both_index = both_index;
				//prev_both_price = both_price;
				both_index = i;
				both_price = price;
				break;
			};
			both_index = prev_both_index;
			both_price = prev_both_price;
			prev_both_index = i;
			prev_both_price = price;
			break;
		}
		}
	}

	//std::cout << a_index << ' ' << both_index << ' ' << prev_both_index << ' ' << b_index << " --\n";

	int res_price_sum = 512;
	int res_a = -1;
	int res_b = -1;

	check_price_sum(res_price_sum, res_a, res_b, a_price, both_price,      a_index, both_index);
	check_price_sum(res_price_sum, res_a, res_b, a_price, prev_both_price, a_index, prev_both_index);
	check_price_sum(res_price_sum, res_a, res_b, a_price, b_price,         a_index, b_index);

	check_price_sum(res_price_sum, res_a, res_b, both_price, prev_both_price, both_index, prev_both_index);
	check_price_sum(res_price_sum, res_a, res_b, both_price, b_price,         both_index, b_index);

	check_price_sum(res_price_sum, res_a, res_b, prev_both_price, b_price, prev_both_index, b_index);
	//swapped
	check_price_sum(res_price_sum, res_a, res_b, prev_both_price, both_price, prev_both_index, both_index);

	if (res_price_sum == 512) {
		std::cout << "-1";
		return 0;
	}
	std::cout << res_a + 1 << ' ' << res_b + 1;


	
	return 0;
}
//*/
