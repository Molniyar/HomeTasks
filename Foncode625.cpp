#include <iostream>
#include <stack>

//*
// matrix
// - - - - - - 
// | 0 0 0 0 I 
// | 0 0 0 0 I 
// ~ ~ ~ ~ ~ ~ 
// array
// - - - - - - I I ~ ~ ~ ~ ~ ~ | | 
// writing:→→→→→↓↓↓←←←←←↑↑↑

int main() {
	int height; std::cin >> height;
	int width; std::cin >> width;

	int length = (height - 1 + width - 1) * 2;
	int* gifts = new int[length];
	int* shifted = new int[length];
	{
		int x = 1;
		int y = 1;
		int i = 0;
		for (;x < width; x++, i++) {
			gifts[i] = x * y;
		}
		//x++;
		for (;y < height; y++, i++) {
			gifts[i] = x * y;
		}
		//y++;
		for (;x > 1; x--, i++) {
			gifts[i] = x * y;
		}
		//x--;
		for (;y > 1; y--, i++) {
			gifts[i] = x * y;
		}
		//y--;
	}

	int turns; std::cin >> turns;

	std::int32_t shift = 0;
	int d;
	int k;
	for (int i = 0; i < turns; i++) {
		std::cin >> d;
		std::cin >> k;
		k %= length;
		shift += (d == 2 ? k : length -k);
		shift %= length;
	}
	//std::cout << shift << '\n';

	{
		int i = 0;
		for (int j = shift; j < length; j++, i++) {
			shifted[i] = gifts[j];
		}
		for (int j = 0; j < shift; j++, i++) {
			shifted[i] = gifts[j];
		}
		delete[] gifts;
		gifts = shifted;
	}
	
	{
		char *middle = new char[(width-2)*2+1];
		for (int i = 0; i < (width - 2)*2; i+=2) {
			middle[i] = '0';
			middle[i+1] = ' ';
		}
		middle[(width - 2) * 2] = 0;


		int i = 0;
		for (int j = 0; j < width; j++,i++) {
			std::cout << gifts[i] << ' ';
		}
		std::cout << '\n';
		for (int j = 0; j < height-2; j++, i++) {
			std::cout << gifts[i + width+1] << ' ' << middle << gifts[i] << '\n';
		}
		i += width-1;
		for (int j = width; j > 0; j--, i--) {
			std::cout << gifts[i] << ' ';
		}
		delete[] middle;
	}
	delete[] shifted;
}
//*/