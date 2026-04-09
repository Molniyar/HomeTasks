#include <iostream>
#include <stack>

//*

struct link_item {
	int value;
	link_item* next = nullptr;
};
struct tree_item {
	link_item* first_link = nullptr;
	bool calculated;
};

tree_item trees[100000]; //= new tree_item[trees_count];
link_item links[200000]; //= new link_item[pairs_count * 2];

int last_tree = -1;
int find_longest_path(int prev, int tree) {
	//std::cout << tree << '\n';
	trees[tree].calculated = true;
	last_tree = tree;
	//std::cout << "|| function started: prev=" << prev << ", tree=" << tree << ", size=" << size << "\n";
	int result = 0;
	link_item* out = trees[tree].first_link;
	while (out != nullptr) {
		//std::cout << "\treading next value\n";
		if (out->value != prev) {
			result = std::max(result, find_longest_path(tree, out->value));
		}
		out = out->next;
	}
	//std::cout << "\tread all values\n";
	return result + 1;
}
int find_longest_path(int tree) {
	if (trees[tree].first_link == nullptr) {
		return 1;
	}
	find_longest_path(tree, tree);
	return find_longest_path(last_tree, last_tree);
}

int main() {
	int size; std::cin >> size;

	int pattern[3] = { 0,0,0 };//current pattern
	int patterns[3][3] = {//every possible pattern
		{1,2,2},
		{2,2,1},
		{2,1,2}
	};

	int* lamps = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin >> lamps[i];
		if (lamps[i])
			pattern[i % 3] = lamps[i];
	}

	int matches[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (patterns[i][j] == pattern[j]) {
				matches[i]++;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (matches[i] >= 2) {
			pattern[0] = patterns[i][0];
			pattern[1] = patterns[i][1];
			pattern[2] = patterns[i][2];
			break;
		}
	}

	int red = 0;
	int blue = 0;
	for (int i = 0; i < size; i++) {
		if (lamps[i] == 0) {
			if (pattern[i % 3] == 1) {
				red++;
			}
			else blue++;
		}
	}

	std::cout << red << '\n' << blue;
}
//*/