#include <iostream>
#include <map>
#include <set>

/*


int main() {
	int size; std::cin >> size;
	
	int* array = new int[size];
	std::map<int, int> counts;
	for (int i = 0; i < size; i++) {
		std::cin >> array[i];
		counts[array[i]]++;
	}
	if (size < 3) {
		std::cout << '0';
		return 0;
	}

	std::set<int> result;
	std::map<int, int> test_counts;
	for (int j = 0; j < size; j++) {
		for (int i = -1; i < counts.size(); i++) {
			test_counts[i] = counts[i];
		}
		test_counts[array[j]]--;
		while (true){
			int i1 = 0;
			int i2 = 0;
			int i3 = 0;
			for (int i = 0; i < counts.size(); i++) {
				if (test_counts[array[i]] < test_counts[array[i1]] && test_counts[array[i]] > 0) {
					i3 = i2;
					i2 = i1;
					i1 = i;
					continue;
				}
				if (test_counts[array[i]] < test_counts[array[i2]] && test_counts[array[i]] > 0) {
					i3 = i2;
					i2 = i;
					continue;
				}
				if (test_counts[array[i]] < test_counts[array[i3]] && test_counts[array[i]] > 0) {
					i3 = i;
					continue;
				}
			}
			std::cout << array[i1] << ' ' << array[i2] << ' ' << array[i3] << '\n';
			test_counts[array[i1]]--;
			test_counts[array[i2]]--;
			test_counts[array[i3]]--;
			int s = 0;
			for (auto n : test_counts) {
				if (n.second) s++;
			}
			if (s < 3) break;
		}
		test_counts[array[j]]++;
		int s = 0;
		for (auto n : test_counts) {
			if (n.second) s++;
		}
		if (s < 3) {
			for (auto n : test_counts) {
				if (n.second)
					result.insert(n.second);
			}
		}
	}


	std::cout << result.size() << '\n';
	for (int n : result) {
		std::cout << n << ' ';
	}


	delete array;
	return 0;
}
//*/