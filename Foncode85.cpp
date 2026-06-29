#include <iostream>

/*

#include <stack>
#include <deque>

bool is_opening_scope(char ch) {
	return ch == '(' || ch == '[' || ch == '{';
}
char flip_scope(char ch) {
	switch (ch) {
	case '(': return ')';
	case '[': return ']';
	case '{': return '}';
	case ')': return '(';
	case ']': return '[';
	case '}': return '{';
	}
}

int check(const std::string& input, int index) {
	std::stack<char> scope;
	for (int i = index; i < input.size(); i++) {
		if (is_opening_scope(input[i])) {
			scope.push(input[i]);
			continue;
		}
		else {
			if (scope.size() == 0) return 0;
			if (scope.top() != flip_scope(input[i])) return 0;
			scope.pop();
			break;
		}
	}
	for (int i = 0; i < index; i++) {
		switch (input[i]) {
		case '(': {
			scope.push('(');
			break;
		}
		case '[': {
			scope.push('[');
			break;
		}
		case '{': {
			scope.push('{');
			break;
		}
		case ')': {
			if (scope.size() == 0) return 0;
			if (scope.top() != '(') return 0;
			scope.pop();
			break;
		}
		case ']': {
			if (scope.size() == 0) return 0;
			if (scope.top() != '[') return 0;
			scope.pop();
			break;
		}
		case '}': {
			if (scope.size() == 0) return 0;
			if (scope.top() != '{') return 0;
			scope.pop();
			break;
		}
		}
	}
	return scope.size() == 0;
}

bool solution_1(const std::string& input) {
	for (int i = 0; i < input.size(); i++) {
		if (check(input, i)) {
			return true;
		}
	}
	return false;
}
bool solution(const std::string& input) {
	std::deque<char> scope;
	int start = input.size()-1;
	int end = 0;

	while (end < start-1) {//TODO
		if (is_opening_scope(input[end])) {
			if (scope.size() == 0) {
				scope.push_front(input[start]);
				continue;
			}
			if (scope.back() != flip_scope(input[end])) return 0;
			scope.pop_back();
			break;
		}
		else {
			if (scope.size() == 0) {
				scope.push_back(input[end]);
				continue;
			}
			if (scope.front() != flip_scope(input[start])) return 0;
			scope.pop_front();
			break;
		}
	}
	return false;
}

int main() {
	std::string input; std::cin >> input;
	std::cout << (solution(input) ? "YES" : "NO");

	return 0;
}
//*/