#include <iostream>
#include <vector>
#include <queue>

template<class T>
class OrderedQueue {
	std::vector<T> vec;
public:
	void add(T point) {
		vec.push_back(point);
		for (int i = vec.size()-1;;) {
			int parent = i >> 1;
			if (vec.at(parent).n > vec.at(i).n) {
				//std::cout << vec.at(i).n << "-><-" << vec.at(parent).n << '\n';
				std::swap(vec.at(parent), vec.at(i));
			}
			else break;
			i = parent;
		}
	}
	bool is_empty() {
		return vec.empty();
	}
	void heapify() {
		heapify(0);
	}
	void heapify(int i) {
		int len = vec.size();
		if (i > len) { return; }

		int curr = i;
		int left = i * 2 + 1;
		int right = i * 2 + 2;

		if (left < len && vec.at(curr).n > vec.at(left).n) {
			curr = left;
		}
		if (right < len && vec.at(curr).n > vec.at(right).n) {
			curr = right;
		}

		if (curr != i) {
			std::swap(vec.at(curr), vec.at(i));
			heapify(curr);
		}
	}
	T pop() {
		T result = vec.front();
		vec.at(0) = vec.back();
		vec.pop_back();
		heapify(0);
		return result;
	}
};