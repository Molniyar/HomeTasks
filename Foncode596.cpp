#include <iostream>

/*

int count;
char* array;
int carrots_to_loose;

void count_carrots(int left, int right, int& carrots_end_left, int& carrots_end_right) {
	carrots_end_left = left;
	carrots_end_right = right;
	while (array[carrots_end_left] == 'C' && carrots_end_left <= right) carrots_end_left++;
	while (array[carrots_end_right] == 'C' && carrots_end_right >= left) carrots_end_right++;
	//while (array[count - 1 - carrots_end_right] == 'C') carrots_end_right++;
}

bool turn(int& left, int& right, int& carrots_end_left, int& carrots_end_right, int& player_carrots) {
	count_carrots(left, right, carrots_end_left, carrots_end_right);

	if (array[left] == 'P') {
		left++;
	}
	else if (array[right] == 'P') {
		right--;
	}
	else {
		if (carrots_end_left - left > right - carrots_end_right) {
			left++;
		}
		else right--;
		player_carrots++;
	}
	if (player_carrots >= carrots_to_loose) {
		return true;
	}

	return false;
}

int main() {
	std::cin >> count;
	std::cin >> carrots_to_loose;

	array = new char[count];

	for (int i = 0; i < count; i++) {
		std::cin >> array[i];
	}

	int carrots_end_left = 0;
	int carrots_end_right = count-1;
	

	int a = 0;
	int b = 0;
	for (int left = 0, right = count - 1; left < right; ) {
		if (turn(left, right, carrots_end_left, carrots_end_right, a)) {
			std::cout << "NE";
			return 0;
		}
		if (turn(left, right, carrots_end_left, carrots_end_right, b)) {
			std::cout << "DA";
			return 0;
		}
	}
	return 0;
	
	delete[] array;
}
//*/