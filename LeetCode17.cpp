#include <iostream>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits) {
	int size = digits.size();

	vector<int> indexes(size);
	for (int i = 0; i < size; i++) indexes[i] = digits[i] - '0' - 2;

	vector<string> codes = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<int> nums(size, 0);

	int res_size = 1;
	for (int i = 0; i < size; i++) res_size *= codes[indexes[i]].size();

	vector<string> result(res_size);


	for (int i = 0; i < res_size; i++) {
		string write (size, '_');
		for (int j = 0; j < size; j++) {
			write[j] = codes[indexes[j]][nums[j]];
		}
		result[i] = write;
		nums[0] += 1;
		for (int j = 0; j < size; j++) {
			if (nums[j] >= codes[indexes[j]].size()) {
				nums[j] = 0;
				if (j == size - 1) { return result; }
				else nums[j + 1]++;
			}
		}
	}
	return result;
}
/*
int main() {
	vector<string> res = letterCombinations("9");
	for (int i = 0; i < res.size(); i++) {
		cout << "\"";
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << "\" ";
	}
	return 0;
}
//*/