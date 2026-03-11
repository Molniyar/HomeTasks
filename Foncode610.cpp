#include <iostream>
#include <vector>
#include <algorithm>

struct indexed_int {
	std::int64_t value;
	int index;
};

static bool compare_value(indexed_int a, indexed_int b) {
	return a.value > b.value;
}
static bool compare_index(indexed_int a, indexed_int b) {
	return a.index < b.index;
}

int main() {
	long size; std::cin >> size;
	std::int64_t money; std::cin >> money;

	indexed_int* array = new indexed_int[size + 1];
	for (int i = 0; i < size; i++) {
		std::cin >> array[i].value;
		array[i].index = i;
		//std::cout << array[i].value << ' ';
	}
	array[size].value = 0;

	std::sort(array,array+size,compare_value);
	
	for (int i = 0; i < size && money; i++) {
		if (array[i].value > array[i + 1].value) {
			std::int64_t dif = (array[i].value - array[i + 1].value); //std::cout << "dif = " << dif << '\n';
			if (dif * (i + 1) > money) {
				dif = money / (i + 1); //std::cout << "redefinition of dif = " << dif << '\n';
				for (int j = i; j >= 0; j--) {
					array[j].value -= dif;
				}
				money = money % (i + 1);
				break;
			}
			for (int j = i; j >= 0; j--) {
				array[j].value -= dif;
				money -= dif;
			}
		}
	}


	std::int64_t max = array[0].value;

	std::sort(array, array + size, compare_index);

	for (int i = 0; i < size; i++) {
		if (money && array[i].value == max) {
			array[i].value--;
			money--;
		}
		std::cout << array[i].value << ' ';
	}

	delete array;
	return 0;
}