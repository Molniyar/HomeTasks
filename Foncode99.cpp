#include <iostream>

using namespace std;

int len_1;
int arr_1[1000];
int len_2;
int arr_2[1000];

int prev_arr[1000];
int arr[1000];


int main() {
	cin >> len_1;
	for (int i = 0; i < len_1; i++) {
		cin >> arr_1[i];
	}
	cin >> len_2;
	for (int i = 0; i < len_2; i++) {
		cin >> arr_2[i];
	}
	if (len_1 == 0 || len_2 == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < len_2; i++) {
		prev_arr[i] = 0;
		arr[i] = 0;
	}


	for (int i = 0; i < len_1; i++) {
		for (int j = 0; j < len_2; j++) {
			if (arr_2[j] == arr_1[i]) {
				arr[j] = (j > 0 ? prev_arr[j - 1] : 0) + 1;
			}
			else {
				arr[j] = max(prev_arr[j], (j > 0 ? arr[j - 1] : 0));
			}
		}
		for (int j = 0; j < len_2; j++) {
			prev_arr[j] = arr[j];
		}
	}

	cout << arr[len_2 - 1];

	return 0;
}