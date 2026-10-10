/*



#include <iostream>

using namespace std;

struct Tile {
	int first;
	int second;
	void swap() {
		std::swap(first, second);
	}
	bool is_same() {
		return first == second;
	}
	void read() {
		char ch;
		cin >> ch;
		first = ch - '0';
		cin >> ch;
		cin >> ch;
		second = ch - '0';
	}
	void sort() {
		if (first > second)
			swap();
	}
	void turn_left() {
		if (first < second)
			swap();
	}
	void turn_right() {
		if (first > second)
			swap();
	}
};

int len;


void stabilise_results(int& result_1, int& result_2) {
	if (result_1 < result_2)
		result_1 = result_2;
	result_2 = result_1;
}
void iterate_tile_rotation(bool& inverse, Tile& curr) {
	if (!curr.is_same()) {
		if (inverse)
			curr.swap();
		inverse = !inverse;
	}
}
void iterate_half_result_calculation(Tile& curr, bool& inv, int& result) {
	//iterate_tile_rotation(inv, curr);
	curr.turn_right();

	result += curr.first * curr.second;
}
void iterate_result_calculation(Tile& curr, Tile& prev, bool& inv, int& result) {
	iterate_tile_rotation(inv, curr);

	result += prev.second * curr.first;
	result += curr.first * curr.second;
	//cout << "> {" << curr.first << ' ' << curr.second << "} , {" << curr.first << ' ' << curr.second << "} \n";
}
int solution() {
	if (len == 0)
		return 0;

	bool inv_1 = false;
	bool inv_2 = true;
	int result_1 = 0;
	int result_2 = 0;
	Tile prev_1; prev_1.read(); prev_1.sort();
	Tile prev_2 = prev_1;
	iterate_half_result_calculation(prev_1, inv_1, result_1);
	iterate_half_result_calculation(prev_2, inv_2, result_2);
	for (int i = 1; i < len; i++) {
		if (prev_1.is_same()) {// there is no difference between prev_1 and prev_2 because both will be equal to 2:2 (or both wont)
			stabilise_results(result_1, result_2);
			inv_1 = false;
			inv_2 = true;
		}
		Tile curr_1; curr_1.read(); curr_1.sort();
		Tile curr_2 = curr_1;
		iterate_result_calculation(curr_1, prev_1, inv_1, result_1);
		iterate_result_calculation(curr_2, prev_2, inv_2, result_2);
		prev_1 = curr_1;
		prev_2 = curr_2;
	}

	stabilise_results(result_1, result_2);
	return result_1;
}



int main() {
	cin >> len;
	cout << solution();
	
}

//*/