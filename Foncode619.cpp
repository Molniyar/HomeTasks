/*
#include <iostream>
#include <queue>
using namespace std;

using Axis = short;

struct Point {
	Axis x;
	Axis y;

	Point operator+(const Point& b)const { return { x + b.x, y + b.y }; }

	Point operator-(const Point& b)const { return { x - b.x, y - b.y }; }
};



class Image {
	using TCell = char;
public:
	Axis height = 0;
	Axis width = 0;
	TCell** image = nullptr;
	void init(Axis h, Axis w) {
		image = new TCell * [height];
		for (Axis i = 0; i < height; i++) {
			image[i] = new TCell[width];
			for (Axis j = 0; j < width; j++) {
				image[i][j] = 0;
			}
		}
	}
	void free() {
		for (Axis i = 0; i < height; i++) {
			delete[] image[i];
		}
		delete[] image;
		height = 0;
		width = 0;
	}
	Image(const Image&) = delete;
	Image() {}
	void read() {
		std::cin >> height;
		std::cin >> width;
		image = new TCell*[height];
		for (Axis i = 0; i < height; i++) {
			image[i] = new TCell[width];
			for (Axis j = 0; j < width; j++) {
				std::cin >> image[i][j];
			}
		}
	}
	~Image() {
		free();
	}
	bool in_bounds(const Point& pt)const {
		return (
			pt.x >= 0 && pt.x < width &&
			pt.y >= 0 && pt.y < height
			);
	}
	
	void init_rotated90(const Image& img) {// redefinition if rotated in 90 
		free();

		height = img.height;
		width = img.width;
		std::swap(width, height);

		image = new TCell * [height];
		for (Axis i = 0; i < height; i++) {
			image[i] = new TCell[width];
			for (Axis j = 0; j < width; j++) {
				image[i][j] = img.image[img.height - j - 1][i];
			}
		}
	}
	Point get_coords_of(char ch)const {
		for (Axis i = 0; i < height; i++) {
			for (Axis j = 0; j < width; j++) {
				if (image[i][j] == ch) {
					return { j,i };
				}
			}
		}
		return { -1,-1 };
	}
	int count(char ch) {
		int result = 0;
		for (Axis i = 0; i < height; i++) {
			for (Axis j = 0; j < width; j++) {
				if (image[i][j] == ch) {
					result++;
				}
			}
		}
		return result;
	}
	int area(Point at) {// 
		int result = 0;

		queue<Point> coords;

		auto add = [&](Point point) {
			if (in_bounds(point) && image[point.y][point.x] == '#') {
				image[point.y][point.x] = '0';
				coords.push(point);
			}
		};

		add(at);
		while (coords.size()) {
			Point curr = coords.front();
			coords.pop();

			
			result++;

			add({ curr.x + 1, curr.y });
			add({ curr.x - 1, curr.y });
			add({ curr.x, curr.y + 1 });
			add({ curr.x, curr.y - 1 });
		}

		fill(at, '#', '0');

		return result;
	}
	void fill(Point at, char ch, char replace) {//
		queue<Point> coords;
		coords.push(at);

		auto add = [&](const Point& point) { if (in_bounds(point) && image[point.y][point.x] == replace) coords.push(point);};

		while (coords.size()) {
			Point curr = coords.front();

			image[curr.y][curr.x] = ch;

			add({ curr.x + 1, curr.y });
			add({ curr.x - 1, curr.y });
			add({ curr.x, curr.y + 1 });
			add({ curr.x, curr.y - 1 });
			//coords.push({ curr.x - 1, curr.y });
			//coords.push({ curr.x, curr.y + 1 });
			//coords.push({ curr.x, curr.y - 1 });

			coords.pop();
		}
	}
	void print()const {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::cout << image[i][j];
			}
			std::cout << '\n';
		}
	}
	bool matches(const Image& img, Point at, int pixels) {//
		//cout << "new\n";
		//print();
		//img.print();
		Point current = img.get_coords_of('#');

		int pixels_matched = 0;


		queue<Point> coords;

		auto add = [&](Point point) { 
			Point p = point - current + at;
			if (in_bounds(p) && image[p.y][p.x] == '#') { 
				coords.push(point);
				image[p.y][p.x] = '0';
			}
		};

		add(current);
		while (coords.size()) {
			Point curr = coords.front();coords.pop();
			Point curr_container = curr - current + at;

			//print();

			// after this condition image[curr_container.y][curr_container.x] is always '#'
			if (!img.in_bounds(curr)) {//maybe interrupt completely if this condition is true
				pixels_matched = -1;
				break;
			}
			//cout << '\t' << curr.x << ' ' << curr.y << ' ' << img.image[curr.y][curr.x] << '\t' << curr_container.x << ' ' << curr_container.y << ' ' << image[curr_container.y][curr_container.x] << '\n';
			if ((img.image[curr.y][curr.x] != '#')) {
				//std::cout << "skipped" << '\n';
				//return false;
				pixels_matched = -1;
				break;
			}
			//if (img.image[curr.y][curr.x] == '#') {}
			pixels_matched++;

			add({ curr.x + 1, curr.y });
			add({ curr.x - 1, curr.y });
			add({ curr.x, curr.y + 1 });
			add({ curr.x, curr.y - 1 });

			//coords.pop();
		}

		fill(at, '#', '0');

		//std::cout << pixels_matched << ' ' << pixels << '\n';

		return pixels_matched == pixels;
	}

};

int* pixels;
Image* letters;
Image text;

int main() {
	int size; std::cin >> size;

	pixels = new int[size];
	letters = new Image[size];
	for (int i = 0; i < size; i++) {
		letters[i].read();
		pixels[i] = letters[i].count('#');
	}

	int* found = new int[size];
	for (int k = 0; k < size; k++) {
		found[k] = 0;
	}
	
	text.read();

	for (Axis i = 0; i < text.height; i++) {
		for (Axis j = 0; j < text.width; j++) {
			if (text.image[i][j] != '#') {
				continue;
			}
			int pixel_count = text.area({j,i});
			//std::cout << "!!!!!!!   " << pixel_count << '\n';
			bool match;
			for (Axis k = 0; k < size; k++) {
				if (pixels[k] != pixel_count)
					continue;
				//cout << "calling at " << k << '\n';
				match = text.matches(letters[k], Point{ j,i }, pixels[k]);
				if (match) {
					found[k]++;
					break;
				}
				Image m90;
				m90.init_rotated90(letters[k]);
				match = text.matches(m90, Point{ j,i }, pixels[k]);
				if (match) {
					found[k]++;
					break;
				}
				Image m180;
				m180.init_rotated90(m90);
				match = text.matches(m180, Point{ j,i }, pixels[k]);
				if (match) {
					found[k]++;
					break;
				}
				m90.init_rotated90(m180);
				match = text.matches(m90, Point{ j,i }, pixels[k]);
				if (match) {
					found[k]++;
					break;
				}
			}
			text.fill(Point{ j,i }, '.', '#');

		}
	}

	for (Axis k = 0; k < size; k++) {
		std::cout << found[k] << '\n';
	}
	delete[] found;

	delete[] letters;
	delete[] pixels;

	return 0;
}

//*/