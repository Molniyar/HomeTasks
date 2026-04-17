#include <iostream>
#include <stack>

/*

struct link_item {
	int value;
	link_item *next = nullptr;
};
struct tree_item {
	link_item *first_link = nullptr;
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
	return result+1;
}
int find_longest_path(int tree) {
	if (trees[tree].first_link == nullptr) {
		return 1;
	}
	find_longest_path(tree, tree);
	return find_longest_path(last_tree, last_tree);
}

int main() {
	int trees_count; std::cin >> trees_count;
	int pairs_count; std::cin >> pairs_count;


	int in_1;
	int in_2;
	for (int i = 0; i < pairs_count; i++) {
		std::cin >> in_1;
		std::cin >> in_2;
		in_1--;
		in_2--;
		links[i << 1].value = in_1;
		links[i << 1].next = trees[in_2].first_link;
		trees[in_2].first_link = &links[i << 1];

		links[(i << 1)+1].value = in_2;
		links[(i << 1)+1].next = trees[in_1].first_link;
		trees[in_1].first_link = &links[(i << 1)+1];
 	}
	/*
	for (int i = 0; i < trees_count; i++) {
		link_item* out = trees[i].first_link;
		std::cout << '[';
		while (out->next!=nullptr) {
			std::cout << out->value << ", ";
			out = out->next;
		}
		std::cout << out->value << "]\n";
	}//


	int result = 0;
	for (int i = 0; i < trees_count; i++) {
		//std::cout << trees[i].calculated;
		if (trees[i].calculated) 
			continue;
		result += find_longest_path(i);
		//std::cout << "|| " << find_longest_path(i) << '\n';
	}
	//std::cout << '\n';
	std::cout << result;

//delete[] trees;
//delete[] links;
}
// */