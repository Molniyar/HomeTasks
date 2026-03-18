#include <iostream>
#include <cmath>

//*
int main() {
	int ax; std::cin >> ax;
	int ay; std::cin >> ay;
	int bx; std::cin >> bx;
	int by; std::cin >> by;
	int cx; std::cin >> cx;
	int cy; std::cin >> cy;
	int dx; std::cin >> dx;
	int dy; std::cin >> dy;

	double A1 = ay - by;
	double B1 = bx - ax;
	double C1 = ax * by - bx * ay;

	double A2 = by - cy;
	double B2 = cx - bx;
	double C2 = bx * cy - cx * by;

	double A3 = cy - ay;
	double B3 = ax - cx;
	double C3 = cx * ay - ax * cy;

	double D1 = std::abs(A1 * dx + B1 * dy + C1) / std::sqrt(A1 * A1 + B1 * B1);
	double D2 = std::abs(A2 * dx + B2 * dy + C2) / std::sqrt(A2 * A2 + B2 * B2);
	double D3 = std::abs(A3 * dx + B3 * dy + C3) / std::sqrt(A3 * A3 + B3 * B3);

	std::cout << std::min(std::min(D1, D2), D3);
}
//*/