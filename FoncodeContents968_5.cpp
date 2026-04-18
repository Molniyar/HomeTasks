#include <iostream>
#include <cmath>

//*
bool debug = true;

bool get_in_and_out(double &res1, double &res2, double x, double y, double z, double xv, double yv, double zv, double r) {
	double a = xv * xv + yv * yv + zv * zv;
	double b = 2 * x * xv + 2 * y * yv + 2 * z * zv;
	double c = x * x + y * y + z * z - r * r;
	double D = b * b - 4 * a * c;
	std::cout << "D=" << D << '\n';
	if (D < 0) {
		return false;
	}
	D = std::sqrt(D);
	res1 = (-b + D) / (2 * a);
	res2 = (-b - D) / (2 * a);
	if (res1 < 0) res1 = 0;
	if (res2 < 0) res2 = 0;
	std::cout << "results: " << res1 << ' ' << res2 << '\n';
	return true;
}
double get_distance(double x, double y, double z, double xv, double yv, double zv, double time) {
	x += xv * time;
	y += yv * time;
	z += zv * time;
	return std::sqrt(x*x + y*y + z*z);
}
int main() {
	int size; std::cin >> size;
	double damage_zone; std::cin >> damage_zone;
	double kill_zone; std::cin >> kill_zone;
	double time; std::cin >> time;

	int ships_passed = 0;
	double nothing = 0;

	double x;
	double y;
	double z;
	double xv;
	double yv;
	double zv;
 	for (int i = 0; i < size; i++) {
		std::cin >> x;
		std::cin >> y;
		std::cin >> z;
		std::cin >> xv;
		std::cin >> yv;
		std::cin >> zv;
		double res1;
		double res2;
		if (get_in_and_out(res1, res2, x, y, z, xv, yv, zv, damage_zone)) {
			if (get_distance(x, y, z, xv, yv, zv, (res1 + res2) / 2) <= kill_zone)
				continue;
			if (std::max(res2, res1)-std::min(res2,res1) <= time)
				ships_passed++;
		}
		else ships_passed++;
	}
	std::cout << ships_passed;
	return 0;
}
//*/