#include <iostream>

void print_shift(int n) {
	if (!n) return; 
	std::cout << "x = x " << ((n > 0) ? "<< " : ">> ") << ((n > 0) ? n : -n) << ";\n";
}
/*
int main() {
	int negative = 0x80000000;

	int len; std::cin >> len;
	int max = 0;
	int min = 0;
	int current = 0;

	for (int i = 0; i < len; i++) {
		std::string inp; 
		std::cin >> inp;
		std::cin >> inp;
		std::cin >> inp;
		std::cin >> inp;
		bool invert = inp[0] == '>';
		std::cin >> inp;
		int parsed_input = 0;
		for (int j = 0; j < inp.size()-1; j++) {
			parsed_input *= 10;
			parsed_input += inp[j] - '0';
		}
		if (invert) parsed_input = -parsed_input;

		current += parsed_input;
		if (current > max) max = current;
		if (current < min) min = current;
		//std::cout << i;
	}

	std::cout << max << ";" << min << ";" << current << "\n";

	int s1 = max;
	int s2 = min - max;
	int s3 = current - min;

	if ((s2 & negative) == (s3 & negative)) {
		s2 += s3;
		s3 = 0;
	}
	if ((s1 & negative) == (s2 & negative)) {
		s1 += s2;
		s2 = 0;
	}
	if ((s2 > 0 ? s2 : -s2) <= (s1 > 0 ? s1 : -s1)) {
		s2 += s3;
		s3 = 0;
	}
	
	std::cout << bool(s1) + bool(s2) + bool(s3) << '\n';

	print_shift(s1);
	print_shift(s2);
	print_shift(s3);

	return 0;
}
//*/