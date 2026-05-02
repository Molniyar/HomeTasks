#include <iostream>
#include <cmath>

struct TPoint
{
	int x = 0;
	int y = 0;

	TPoint operator+(const TPoint& b) { return { x + b.x, y + b.y }; }
	void operator+=(const TPoint& b) { x += b.x; y += b.y; }

	TPoint operator-(const TPoint& b) { return { x - b.x, y - b.y }; }
	void operator-=(const TPoint& b) { x -= b.x; y -= b.y; }

	TPoint operator*(int b) { return { x * b, y * b }; }
	void operator*=(int b) { x *= b; y *= b; }

	bool operator==(const TPoint& p) const {
		return (x == p.x && y == p.y);
	}
};

struct Node {
	Node* prev = nullptr;
	TPoint data;
	Node* next = nullptr;

	bool operator==(const Node& b) const { return (b.data == data && prev == b.prev && prev == b.prev); }
	void print() {
		std::cout << " {" << data.x << ';' << data.y << "} ";
	}
};

double get_length(TPoint from, TPoint to) {
	int x = std::max(from.x, to.x) - std::min(from.x, to.x);
	int y = std::max(from.y, to.y) - std::min(from.y, to.y);
	return std::sqrt(x * x + y * y);
}

int get_line(const TPoint& from, const TPoint& to, const TPoint& curr) {// maybe swap to and from
	int A = -from.y + to.y;
	int B = from.x - to.x;
	int C = -to.y*B -to.x*A;
	int X = curr.x;
	int Y = curr.y;

	return A * X + B * Y + C;
}

Node nodes[1000];
int main() {
	int size; std::cin >> size;

	std::cin >> nodes[0].data.x;
	std::cin >> nodes[0].data.y;
	std::cin >> nodes[1].data.x;
	std::cin >> nodes[1].data.y;
	std::cin >> nodes[2].data.x;
	std::cin >> nodes[2].data.y;
	nodes[0].next = &nodes[1];
	nodes[1].next = &nodes[2];
	nodes[2].next = &nodes[0];
	nodes[0].prev = &nodes[2];
	nodes[1].prev = &nodes[0];
	nodes[2].prev = &nodes[1];

	Node start = nodes[0];

	for (int i = 3; i < size; i++) {
		std::cin >> nodes[i].data.x;
		std::cin >> nodes[i].data.y;

		Node* prev = nullptr;
		Node* next = nullptr;
		int prevs = 0;
		for (int j = 0; j < i; j++) {
			Node* Prev = nodes[j].prev;
			Node* Next = nodes[j].next;
			int l1 = get_line(nodes[i].data, nodes[j].data, Prev->data);
			int l2 = get_line(nodes[i].data, nodes[j].data, Next->data);
			if ((l1 > 0 && l2 < 0) || (l1 < 0 && l2 > 0)) {
				continue;
			}
			if (l1 > 0 || l2 > 0) {
				prev = &nodes[j];
				prevs = 1;
				continue;
			}
			if (l1 < 0 || l2 < 0) {
				next = &nodes[j];
				prevs = -1;
				continue;
			}
			if (l1 == 0 && l2 == 0) {
				if (prevs == 1) {
					next = &nodes[j];
					prevs = -1;
				}
				else {
					prev = &nodes[j];
					prevs = 1;
				}
			}
		}
		if (prev == nullptr || next == nullptr) {
			std::cout << "<not added>\n";
			continue;
		}
		std::cout << "C| ";
		prev->prev->print();
		prev->print();
		prev->next->print();
		std::cout << " | ";
		nodes[i].print();
		std::cout << " | ";
		next->prev->print();
		next->print();
		next->next->print();
		std::cout << "\n";

		if (get_length(nodes[i].data, prev->prev->data) < get_length(nodes[i].data, prev->next->data)) {
			nodes[i].next = prev;
			nodes[i].next->prev = &nodes[i];
		}
		else {
			nodes[i].prev = prev;
			nodes[i].prev->next = &nodes[i];
		}
		
		if (get_length(nodes[i].data, next->prev->data) < get_length(nodes[i].data, next->next->data)) {
			nodes[i].next = next;
			nodes[i].next->prev = &nodes[i];
		}
		else {
			nodes[i].prev = next;
			nodes[i].prev->next = &nodes[i];
		}

		start = nodes[i];
	}

	std::cout << "[]\n";

	double result = 0;
	Node previous = start;
	Node current = *previous.next;
	while (!(current == start)) {
		std::cout << "R| " << result << ' ' << previous.data.x << ' ' << previous.data.y << '\n';
		result += get_length(previous.data, current.data);
		previous = current;
		current = *current.next;
	}
	std::cout << "R/ " << result << ' ' << previous.data.x << ' ' << previous.data.y << '\n';
	result += get_length(previous.data, current.data);
	std::cout << result;
	return 0;
}