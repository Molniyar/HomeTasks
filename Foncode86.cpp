#include <iostream>

/*
int main() {
	int len; std::cin >> len;

	int a_index = -1;
	int b_index = -1;
	int prev_both_index = -1;
	int both_index = -1;

	int a_price = 255;
	int b_price = 255;
	int prev_both_price = 255;
	int both_price = 255;

	bool a_cont = 1;
	bool b_cont = 2;
	bool prev_both_cont = 3;
	bool both_cont = 3;

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
			if (a_price <= price)break;
			a_index = i;
			a_price = price;
			break; 
		}
		case 2: {
			if (b_price <= price)break;
			b_index = i;
			b_price = price;
			break; 
		}
		case 3: {
			if (prev_both_price <= price) {
				if (both_price <= prev_both_price)break;
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
	//std::cout << a_index << ' ' << b_index << ' ' << prev_both_index << ' ' << both_index << '\n';
	//std::cout << a_price << ' ' << b_price << ' ' << prev_both_price << ' ' << both_price << "\n\n";

	if (a_price > prev_both_price) {//sorting
		std::swap(a_price, prev_both_price);
		std::swap(b_price, both_price);
		std::swap(a_index, prev_both_index);
		std::swap(b_index, both_index);
		std::swap(a_cont, prev_both_cont);
		std::swap(b_cont, both_cont);
	}
	if (a_price > b_price) {
		std::swap(a_price, b_price);
		std::swap(a_index, b_index);
		std::swap(a_cont, b_cont);
	}
	if (prev_both_price > both_price) {
		std::swap(prev_both_price, both_price);
		std::swap(prev_both_index, both_index);
		std::swap(prev_both_cont, both_cont);
	}
	//std::cout << a_index << ' ' << b_index << ' ' << prev_both_index << ' ' << both_index << '\n';
	//std::cout << a_price << ' ' << b_price << ' ' << prev_both_price << ' ' << both_price << "\n\n";
	if (b_index == -1) {
		std::cout << "-1";
		return 0;
	}
	if ((a_cont & 2) == 0) std::swap(a_index, b_index);
	if ((a_cont & 3) && (b_cont & 3) && a_index > b_index) std::swap(a_index, b_index);
	std::cout << a_index+1 << ' ' << b_index+1;
	return 0;
}
//*/
