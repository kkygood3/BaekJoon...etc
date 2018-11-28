#include <iostream>
using namespace std;

void swap(int *p, int *q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void quicksort(int left, int right, int *data) {
	int pivot = left;
	int j = pivot;
	int i = pivot + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (data[i] < data[pivot]) {
				j++;
				swap(data[i], data[j]);
			}
		}
		swap(data[j], data[pivot]);
		pivot = j;

		quicksort(left, pivot - 1, data);
		quicksort(pivot + 1, right, data);

	}

}

int main() {

	int t, arr[1000];
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}
	quicksort(0, t-1, arr);
	for (int i = 0; i < t; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}


// 그냥 정렬
//int main() {
//
//	int	n, su[1001];
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> su[i];
//	}
//
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - 1; j++) {
//			if (su[j] > su[j + 1]) {
//				int temp;
//				temp = su[j + 1];
//				su[j + 1] = su[j];
//				su[j] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cout << su[i] << endl;
//	}
//
//	return 0;
//}
