#include <iostream>
#include <vector>
using namespace std;

int minimumCost(vector<int>& nums) {
	int first = 51;
	int second = 51;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] < first) {
			second = first;
			first = nums[i];
			continue;
		}
		if (nums[i] < second) {
			second = nums[i];
		}
	}
	return nums[0] + first + second;
}

int main() {
	vector<int> arr0 = { 5,6,7,8,1,2,3 };
	vector<int> arr1 = { 4,5,6,7,0,1,2 };
	vector<int> arr2 = { 14,15,1,2,3,4,5,6,7,8,9,10,11,12,13 };


	vector<vector<int>> arrs = { arr0,arr1,arr2 };

	for (int i = 0; i < arrs.size(); i++) {
		cout << "***** TEST " << i + 1 << " *****\n";
		cout << "Array : ";
		for (int j = 0; j < arrs[i].size(); j++) {
			cout << arrs[i][j] << ' ';
		}cout << '\n';
		cout << "Result: " << minimumCost(arrs[i]) << '\n';
		cout << "==============================================\n";
	}
	return 0;
}