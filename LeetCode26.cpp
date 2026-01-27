#include <iostream>
#include <vector>
using namespace std;
//easy
int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0) return 0;

	int res_len = 0;
	int prev = nums[0] - 1;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == prev) continue;

		nums[res_len] = nums[i];
		prev = nums[i];
		res_len++;
	}

	return res_len;
}
/*
int main() {
	std::vector<int> test0 = {1,1,1,2,2,3,3};

	int result = removeDuplicates(test0);
	cout << result << '\n';
	for (int i = 0; i < result; i++) {
		cout << test0[i] << ' ';
	}

	return 0;
}
//*/