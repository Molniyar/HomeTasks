#include <iostream>
//#include <cmath>
#include <algorithm>

/*

int main() {
	int d[3]; 
	std::cin >> d[0];
	std::cin >> d[1];
	std::cin >> d[2];

	int x; std::cin >> x;
	int y; std::cin >> y;

	int max_dist = d[0] + d[1] + d[2]; max_dist *= max_dist;

	std::sort(d, d + 3);
	int min_dist = std::max(d[2] - d[1] - d[0],0); min_dist *= min_dist;

	int curr_dist = x * x + y * y;
	
	if (curr_dist >= min_dist && curr_dist <= max_dist) {
		std::cout << "YES";
	}
	else std::cout << "NO";

	return 0;
}
//*/