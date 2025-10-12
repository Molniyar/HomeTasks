#include <iostream>
#include <vector>
#include <queue>

struct Point {
	int x;
	int y;
};
struct MyPoint {
	int x;
	int y;
	int n;
};

void printMatrix_(int** matrix, int ySize, int xSize) {
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			switch (matrix[i][j]) {
			case -1: {std::cout << "##";break;}
			case 1: {std::cout << "__";break;}
			case 8: { std::cout << "=="; break; }
			case -2: { std::cout << "()"; break; }
			case -128: { std::cout << "ST"; break; }
			case 127: { std::cout << "EN"; break; }
			case -8: { std::cout << "??"; break; }
			default : std::cout << "  ";
			}
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void printMatrix(int** matrix, int ySize, int xSize) {
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void find_path(int** matrix, int ySize, int xSize, int yStart, int xStart, int yEnd, int xEnd) {
	if (xStart == xEnd || yStart == yEnd) { return; }

	int** dMatrix = new int* [xSize];
	for (int i = 0; i < xSize; i++) { 
		dMatrix[i] = new int[ySize];
		for (int j = 0; j < ySize; j++) { dMatrix[i][j] = -1; }
	}
	

	dMatrix[yStart][xStart] = 0;

	std::queue<MyPoint> queue_;
	queue_.push({xStart,yStart,0});
	bool pathFound = false;

	int X_[] = {-1, 1, 0, 0};
	int Y_[] = {0, 0, -1, 1};
	for (;!queue_.empty();) {
		MyPoint current = queue_.front();
		std::cout << current.x << ' ' << current.y << ' ' << current.n << '\n';

		int nz = current.n + 1;
		
		for (int i = 0; i < 4; i++) {
			int nx = X_[i] + current.x;
			int ny = Y_[i] + current.y;
			std::cout << nx << ' ' << ny << '\n';
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (matrix[ny][nx] != -1 && dMatrix[ny][nx] == -1) {
				queue_.push({nx,ny,nz });
				dMatrix[ny][nx] = nz;
				
				//matrix[ny][nx] = -8;
			}
		}
		printMatrix(dMatrix, ySize, xSize);
		queue_.pop();
	}
	printMatrix(dMatrix, ySize, xSize);
	int x = xEnd;
	int y = yEnd;
	for (int i = 0;i < 128;i++) {
		for (int j = 0; j < 4; j++) {
			int nx = X_[j] + x;
			int ny = Y_[j] + y;
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (dMatrix[ny][nx] != -1 && dMatrix[ny][nx] < dMatrix[y][x]) {
				x = nx;
				y = ny;
				matrix[y][x] = -2;
			}
		}
		if (x == xStart && y == yStart) break;
	}
	matrix[yStart][xStart] = -128;//start
	matrix[yEnd][xEnd] = 127;//end
}

void heapify_vec(std::vector<MyPoint> arr, int len, int i) {
	if (i > len) { return; }

	int curr = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (left < len && arr.at(curr).n > arr.at(left).n) {
		curr = left;
	}
	if (right < len && arr.at(curr).n > arr.at(right).n) {
		curr = right;
	}

	if (curr != i) {
		std::swap(arr.at(curr).n, arr.at(i).n);
		heapify_vec(arr, len, curr);
	}
}

void find_path_with_priorities(int** matrix, int ySize, int xSize, int yStart, int xStart, int yEnd, int xEnd) {
	if (xStart == xEnd || yStart == yEnd) { return; }

	int** dMatrix = new int* [xSize];
	for (int i = 0; i < xSize; i++) {
		dMatrix[i] = new int[ySize];
		for (int j = 0; j < ySize; j++) { dMatrix[i][j] = -1; }
	}


	dMatrix[yStart][xStart] = 0;

	std::vector<MyPoint> queue_;
	queue_.push_back({xStart, yStart, 0});
	bool pathFound = false;

	int X_[] = { -1, 1, 0, 0 };
	int Y_[] = { 0, 0, -1, 1 };
	for (; !queue_.empty();) {
		heapify_vec(queue_, queue_.size(), 0);
		MyPoint current = queue_.front();
		std::cout << current.x << ' ' << current.y << ' ' << current.n << '\n';

		//int nz = current.n + matrix[current.y][current.x];

		for (int i = 0; i < 4; i++) {
			int nx = X_[i] + current.x;
			int ny = Y_[i] + current.y;
			std::cout << nx << ' ' << ny << '\n';
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (matrix[ny][nx] != -1 && (dMatrix[ny][nx] == -1 || dMatrix[ny][nx] > current.n + matrix[ny][nx])) {
				queue_.push_back({ nx,ny,current.n + matrix[ny][nx] });
				dMatrix[ny][nx] = current.n + matrix[ny][nx];

				//matrix[ny][nx] = -8;
			}
		}
		printMatrix(dMatrix, ySize, xSize);
		queue_.erase(queue_.begin());
	}
	printMatrix(dMatrix, ySize, xSize);
	int x = xEnd;
	int y = yEnd;
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = X_[j] + x;
			int ny = Y_[j] + y;
			if (nx >= xSize || nx < 0 || ny >= ySize || ny < 0) continue;
			if (dMatrix[ny][nx] != -1 && dMatrix[ny][nx] < dMatrix[y][x]) {
				x = nx;
				y = ny;
				matrix[y][x] = -2;
			}
		}
		if (x == xStart && y == yStart) break;
	}
	matrix[yStart][xStart] = -128;//start
	matrix[yEnd][xEnd] = 127;//end
}







int Calls = 0;
int Swaps = 0;
int Compares = 0;

int Unsorted[] = { 1,0,7,3,9,4,8,5 };
int Sorted[] = { 1,2,3,4,5,6,7,8 };
int BackSorted[] = { 8,7,6,5,4,3,2,1 };
int Same[] = { 5,5,5,5,5,5,5,5 };
int Longer[] = { 1,0,7,9,3,4,8,5,2,6,12,8,5,8,8,30 };

struct sArray
{
	int* arr;
	int length;
	std::string name;
};

using TFunc = void(*)(int*, int);
struct sFunction
{
	TFunc function;
	std::string name;
	sFunction(TFunc afunction, std::string aname) {
		function = afunction;
		name = aname;
	}
};
sArray arrays[] = {
	{ Unsorted,8,"Unsorted"},
	{ Sorted,8,"Sorted  "},
	{ BackSorted,8,"BackSorted"},
	{ Same,8,"Same    "},
	{ Longer,16,"Longer  "}
};

void print_array(int arr[], int start, int end) {
	for (int i = start; i < end; i++) {
		std::cout << arr[i] << ' ';
	}
}

void bubble_sort(int arr[], int len) {
	Calls++;
	for (int i = 0; i < len; i++) {Compares++;
		for (int j = 0; j < len-1-i; j++) {Compares++;
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]); Swaps++;
			} Compares++;
		}
	}
}

void insertion_sort(int arr[], int len) {
	Calls++;
	for (int i = 1; i < len; i++) {Compares++;
	for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {Compares++;
			std::swap(arr[j], arr[j - 1]); Swaps++;
		}
	}
}

void selection_sort(int arr[], int len) {
	Calls++;
	for (int i = 0; i < len - 1; i++) {
		Compares++;
		int min = arr[i];
		int index = i;
		for (int j = i; j < len; j++) {
			Compares++;
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}Compares++;
		}
		std::swap(arr[i], arr[index]); Swaps++;
	}
}


void quick_sort(int arr[], int start, int end) {
	Calls++;
	if (start >= end) { return; }Compares++;

	int current = start;
	int x = arr[start];
	for (int i = start + 1; i <= end; i++) {
		Compares++;
		if (arr[i] < x) {
			std::swap(arr[i], arr[++current]); Swaps++;
		}Compares++;
	}
	std::swap(arr[current], arr[start]); Swaps++;

	quick_sort(arr, start, current-1);
	quick_sort(arr, current+1, end);
}


void heapify(int arr[], int len, int i) {
	Calls++;
	if (i > len) { return; }Compares++;

	int curr = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if (left < len && arr[curr] < arr[left]) {
		curr = left;
	}Compares+=2;
	if (right < len && arr[curr] < arr[right]) {
		curr = right;
	}Compares+=2;

	if (curr != i) {
		std::swap(arr[curr], arr[i]); Swaps++;
		heapify(arr, len, curr);
	}Compares++;
}
void heap_sort(int arr[], int len) {
	Calls++;
	for (int i = len / 2; i >= 0; i--) {
		Compares++;
		heapify(arr, len, i);
	}
	for (int i = len - 1; i >= 0; i--) {
		Compares++;
		std::swap(arr[i], arr[0]); Swaps++;
		heapify(arr, i, 0);
	}
}

void merge(int* arr1, int* arr2, int len1, int len2, int* result) {
	Calls++;
	if (len1 + len2 < 2) { return; }Compares++;
	int I = 0;
	int i1 = 0, i2 = 0;
	for (; i1 < len1 && i2 < len2; I++) {Compares+=2;
		if (arr1[i1] > arr2[i2]) {
			//std::cout << '\n' << "arr2[" << i2 << "] - " << I << " - " << arr2[i2];
			result[I] = arr2[i2++];
		}
		else { 
			//std::cout << '\n' << "arr1[" << i1 << "] - " << I << " - " << arr1[i1];
			result[I] = arr1[i1++];
		}Compares++;
	}
	while (i1 < len1) {Compares++;
		//std::cout << '\n' << "arr1[" << i1 << "] - " << I << " - " << arr1[i1];
		result[I++] = arr1[i1++];
	}
	while (i2 < len2) {Compares++;
		//std::cout << '\n' << "arr2[" << i2 << "] - " << I << " - " << arr2[i2];
		result[I++] = arr2[i2++];
	}
	//std::cout << "\n";
	//print_array(result,0, len1+len2);
	//std::cout << "\n=========================================";
}
void merge_sort(int arr[], int len) {
	int* temp = new int[len];
	int* arr2 = temp;
	int* to = arr;

	for (int i = 0; i < len; i++) { arr2[i] = arr[i]; }

	for (int n = 1, X = len >> 1; n < len; n <<= 1, X >>= 1) {Compares++;
	for (int i = 0; i < X + 1; i++) {Compares++;
			int start = i * n * 2;
			if (start + n >= len) {
				continue;
			}Compares++;
			int len2 = n;
			if (start + n + n >= len) {
				len2 -= (start + n + n - len);
			}Compares++;
			merge(arr + start, arr + start + n, n, len2, arr2 + start); Calls++;
		}
		std::swap(arr, arr2); Swaps++;
		
	}
	if (to != arr) 
		for (int i = 0; i < len; i++)
			to[i] = arr[i];

	delete temp;
}

void clear() {
	Compares = 0;
	Swaps = 0;
	Calls = 0;
}

void copy_array(int* from, int* to, int length) {
	for (int i = 0; i < length; i++) {
		to[i] = from[i];
	}
}

void table_start() {
	std::cout << "+---------------+----------------+---------------+---------------+---------------+\n";
	std::cout << "|               |Compares        |Swaps          |Calls          |Rate           |\n";
	std::cout << "+---------------+----------------+---------------+---------------+---------------+\n";
}

void special_quick_sort_function(int* arr, int len) {
	quick_sort(arr,0,len-1);
}

void special_sort_for_sort_info(int* arr, int* some_arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				std::swap(some_arr[j], some_arr[j + 1]);
			}
		}
	}
}

void TestSort(sArray arr, sFunction functs[],int len) {
	int* rates = new int[len];
	int* compares_ = new int[len];
	int* swaps_ = new int[len];
	int* calls_ = new int[len];
	for (int i = 0; i < len; i++) {
		clear();
		functs[i].function(arr.arr,arr.length);
		compares_[i] = Compares;
		swaps_[i] = Swaps;
		calls_[i] = Calls;
		rates[i] = Compares + Swaps;
	}

	int* indexes = new int[len]; for (int i = 0; i < len; i++) { indexes[i] = i; }
	special_sort_for_sort_info(rates, indexes, len);
	
	table_start();
	for (int i = 0; i < len; i++) {
		clear();
		std::cout << '|' << functs[indexes[i]].name;
		std::cout << "\t| " << compares_[indexes[i]] << "\t\t | " << swaps_[indexes[i]] << "\t\t | " << calls_[indexes[i]] << "\t\t | " << rates[i] << "\t\t | \n";
		std::cout << "+---------------+----------------+---------------+---------------+---------------+\n";
	}
	delete rates;
	delete compares_;
	delete swaps_;
	delete calls_;
}


typedef void (*func) (int*, int);

sFunction functions[] = {
	{ bubble_sort,                 "Bubble sort"    },
	{ insertion_sort,              "Insertion sort" },
	{ selection_sort,              "Selection sort" },
	{ special_quick_sort_function, "Quick sort"     },
	{ heap_sort,                   "Heap sort"      },
	{ merge_sort,                  "Merge sort"     }
};

void sorts_tests(sArray arrays_[], sFunction functions_[], int a_l, int f_l) {
	for (int i = 0; i < a_l; i++) {
		std::cout << "\n" << arrays_[i].name << ":\n";
		TestSort(arrays_[i], functions_, f_l);
	}
}

int main() {
	//sorts_tests(arrays,functions,5,6);
	int __ = 1;
	int WW = -1;
	int II = 8;
	int x1[] = { WW,WW,WW,WW,WW,WW,WW,WW };
	int x2[] = { WW,__,__,__,__,__,__,WW };
	int x3[] = { WW,__,WW,__,WW,WW,__,__ };
	int x4[] = { WW,__,WW,__,WW,__,__,WW };
	int x5[] = { WW,__,WW,__,__,WW,__,WW };
	int x6[] = { WW,II,WW,WW,WW,WW,__,WW };
	int x7[] = { __,__,__,__,__,__,__,WW };
	int x8[] = { __,__,__,WW,WW,WW,WW,WW };
	int* M[] = {x1,x2,x3,x4,x5,x6,x7,x8};
	find_path_with_priorities(M, 8, 8, 1, 1, 6, 3);

	printMatrix_(M, 8, 8);
	//for (int i = 12; i < 16; i++) {for (int j = 0; j < 16; j++) {std::cout << (char)(i*16+j) << " - " << (i * 16 + j) << "";}
}
