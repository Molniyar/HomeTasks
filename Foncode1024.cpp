#include <iostream>
#include <set>

/*
int main() {
	int size; std::cin >> size;
	int arr_a[300];
	int arr_b[300];

	for (int i = 0; i < size; i++) {
		std::cin >> arr_a[i];
	}
	for (int i = 0; i < size; i++) {
		std::cin >> arr_b[i];
	}

	std::set<std::pair<int,int>> set;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			set.insert({std::min(arr_a[i],arr_b[j]), std::max(arr_a[i],arr_b[j])});
		}
	}

	std::cout << set.size();

	return 0;
}
//*/