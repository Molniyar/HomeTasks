#include <iostream>

namespace {



void print_array(int arr[], int start, int end) {
	for (int i = start; i < end; i++) {
		std::cout << arr[i] << ' ';
	}
}


void quick_sort(int arr[], int start, int end) {
	if (start >= end) { return; }
	if (end - start == 1) { return; }

	print_array(arr, start, end);

	std::cout << " -> ";
	int x = arr[end - 1];// end-1 = last
	int S = start;//less
	int E = end - 1;//more or equals
	for (; S <= E;) {
		if (arr[S] >= x && arr[E] < x) {
			std::swap(arr[S], arr[E]);
			continue;
		}
		if (arr[S] < x) {
			S++;
		}
		if (arr[E] >= x) {
			E--;
		}
	}
	if (S == start) {
		if (arr[end - 2] < x) {
			std::swap(arr[end - 1], arr[end - 2]);
			quick_sort(arr, start, end);
			return;
		}
		quick_sort(arr, start, end - 1);
	}
	print_array(arr, start, end);
	std::cout << "||| " << start << " | " << S << " | " << S << " | " << end << " |||\n";
	quick_sort(arr, start, S);
	quick_sort(arr, S, end);
}
void swap(int numbers[], size_t first, size_t second)
{
	auto temp{ numbers[first] };
	numbers[first] = numbers[second];
	numbers[second] = temp;
}
void other_sort(int numbers[], size_t start, size_t end)
{
	// начальный индекс должен быть меньше конечного индекса для массива из 2 и более элементов
	if (start >= end)
		return;
	// проверяем все элементы относительно элемента с индексом start
	size_t current = start;
	auto x = numbers[start];
	for (size_t i{ start + 1 }; i <= end; i++)
	{
		// если i-ый элемент меньше начального
		if (numbers[i] < x)
		{
			swap(numbers, ++current, i); // меняем его с левым
		}
	}
	swap(numbers, start, current); // Меняем выбранный (start) и последний обмененный элементы
	if (current > start)
	{
		other_sort(numbers, start, current - 1); // Сортируем элементы слева
	}
	if (end > current + 1)
	{
		other_sort(numbers, current + 1, end); // Сортируем элементы справа
	}
}
void heapify(int arr[], int n, int i) {

	int T = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[T]) { T = l; }
	if (r < n && arr[r] > arr[T]) { T = r; }

	if (T != i) {
		std::swap(arr[i], arr[T]);
		heapify(arr, n, T);
	}
}

void heap_sort(int arr[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		heapify(arr, len, i);
	}

	for (int i = len - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}
}