#include <iostream>
#include <cmath>
using namespace std;

void swap(int *p, int *q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void quicksort(int left, int right, int *arr) {
	int pivot = left;
	int j = pivot;
	int i = pivot + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (arr[i] < arr[pivot]) {
				j++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[j], arr[pivot]);
		pivot = j;

		quicksort(left, pivot - 1, arr);
		quicksort(pivot + 1, right, arr);
	}


}

int main() {

	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	int *arr = new int[n];
	int count[10000] = { 0, };
	int max = 0, idx;
	int range_max = -4001, range_min = 4001;
	double mean = 0;
	bool sw = false;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mean += (double)arr[i];
		if (range_max < arr[i]) range_max = arr[i];
		if (range_min > arr[i]) range_min = arr[i];
		if(arr[i]>=0) count[arr[i]]++;
		else count[4000 - arr[i]]++;
	}
	mean /= double(n);
	quicksort(0, n - 1, arr);
	cout << round(mean) << '\n';
	cout << arr[n / 2] << '\n';
	for (int i = -4000; i <= 4000; i++) {
		if (i < 0) {
			if (max < count[4000 -i]) {
				max = count[4000 -i];
				idx = i;
				sw = false;
			}
			else if (max == count[4000 - i] && sw == false) {
				idx = i;
				sw = true;
			}
		}
		else {
			if (max < count[i]) {
				max = count[i];
				idx = i;
				sw = false;
			}
			else if (max == count[i] && sw == false) {
				idx = i;
				sw = true;
			}
		}
	}
	if (sw) {
		cout << idx << '\n';
	}
	else {
		for (int i = 0; i <= 8000; i++) {
			if (count[i] == max) {
				if (i <= 4000) {
					cout << i << '\n';
					break;
				}
				else {
					cout << -(i - 4000) << '\n';
					break;
				}
			}
		}
	}
	cout << (range_max - range_min) << '\n';
	

	return 0;
}