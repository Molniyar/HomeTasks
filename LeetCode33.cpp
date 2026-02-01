#include <iostream>
#include <vector>
using namespace std;
//medium
int search(vector<int>& nums, int target) {
	bool debug = 1;

	int size = nums.size();
	if (size == 0) return -1;
	if (size == 1) {
		if (nums[0] == target) return 0;
		return -1;
	}
	
	int start = 0;
	int change = (size - 1);
	while (change) {
		if (debug) cout << "]] index = " << start << ", change = " << change << '\n';
		int next_index = start;
		int left = start - change;
		int right = start + change;
		if (left >= 0 && left < size && nums[left] < nums[next_index]) {
			next_index = left;
		}
		if (right >= 0 && right < size && nums[right] < nums[next_index]) {
			next_index = right;
		}
		start = next_index;
		if (change == 1) break;
		change = (change >> 1) + (change & 1);
	}

	if (debug) cout << "start: " << start << '\n';

	int index = size >> 1;
	change = (size >> 1);// used here too
	int carry = 0;
	while (change) {
		int current_index = (index + start) % size;
		if (debug) cout << "|| index = " << index << ", actual_index = " << current_index << ", change = " << change << '\n';
		if (nums[current_index] > target) {
			index -= change;
		}
		else if (nums[current_index] < target) {
			index += change;
		}
		else return current_index;
		if (index >= size) index = size-1;
		if (index < 0) index = 0;
		if (change == 1)break;
		change = (change >> 1)/**/ + (change & 1)/**/;
	}

	if (nums[(index + start) % size] != target) return -1;
	else return (index + start) % size;
}
/*
int main() {

	vector<int> arr0 = { 5,6,7,8,1,2,3 };
	int t0 = 2;
	vector<int> arr1 = { 4,5,6,7,0,1,2 };
	int t1 = 0;
	vector<int> arr2 = { 14,15,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int t2 = 11;
	vector<int> arr3 = { 1,2,3 };
	int t3 = 1;
	vector<int> arr4 = { 1,2 };
	int t4 = 0;
	vector<int> arr5 = { 4,5,6,7,8,9,1,2,3 };
	int t5 = 1;
	vector<int> arr6 = { 1,2,3,4,5,6,7 };
	int t6 = 7;
	vector<int> arr7 = { 8,1,2,3,4,5,6,7 };
	int t7 = 6;
	vector<int> arr8 = { 2, 3, 4, 5, 6, 7, 8, 9, 1 };
	int t8 = 9;
	vector<int> arr9 = { 3, 4, 5, 6, 1, 2 };
	int t9 = 2;


	vector<vector<int>> arrs = { arr0,arr1,arr2,arr3,arr4,arr5,arr6,arr7,arr8,arr9 };
	vector<int> targets = { t0,t1,t2,t3,t4,t5,t6,t7,t8,t9 };

	for (int i = 0; i < arrs.size(); i++) {
		cout << "***** TEST " << i + 1 << " *****\n";
		cout << "Array : ";
		for (int j = 0; j < arrs[i].size(); j++) {
			cout << arrs[i][j] << ' ';
		}cout << '\n';
		cout << "Target: " << targets[i] << '\n';
		cout << "Result: " << search(arrs[i], targets[i]) << '\n';
		cout << "==============================================\n";
	}
}
//*/