#include <iostream>
#include <map>

/*
int main() {
	int size; std::cin >> size;

	std::map<std::string, int> prices;

	std::string name;
	int price;
	for (int i = 0; i < size; i++) {
		std::cin >> name;
		std::cin >> price;
		if (prices.find(name) == prices.end()) {
			prices[name]=price;
			continue;
		}
		if (prices.at(name) > price) {
			prices.at(name) = price;
		}
	}

	std::cout << prices.size() << '\n';
	for (auto item: prices) {
		std::cout << item.first << ' ' << item.second << '\n';
	}
}
//*/