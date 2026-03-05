#include <iostream>

int main() {
	double ax; std::cin >> ax;
	double ay; std::cin >> ay;
	double bx; std::cin >> bx;
	double by; std::cin >> by;
	double cx; std::cin >> cx;
	double cy; std::cin >> cy;
	double result = ((ax - bx) * (ay + by) + (bx - cx) * (by + cy) + (cx - ax) * (cy + ay)) / 2;

	std::cin >> ax;
	std::cin >> ay;
	std::cin >> bx;
	std::cin >> by;
	std::cin >> cx;
	std::cin >> cy;
	double result2 = ((ax - bx) * (ay + by) + (bx - cx) * (by + cy) + (cx - ax) * (cy + ay)) / 2;
	
	std::cout << (result < 0 ? -result : result);
	std::cout << '\n';
	std::cout << (result2 < 0 ? -result2 : result2);
}