#include <iostream>
#include <string>
using namespace std;

void swap(int *p, int *q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void quicksort(int left, int right, int *arr) {

	int pivot = left;
	int i = pivot + 1;
	int j = pivot;
	if (left < right) {
		for (; i <= right; i++) {
			if (arr[pivot] < arr[i]) {
				j++;
				swap(arr[j], arr[i]);
			}
		}
		swap(arr[j], arr[pivot]);
		pivot = j;
		
		quicksort(left, pivot - 1, arr);
		quicksort(pivot + 1, right, arr);
	}

}

int main() {

	string s;
	int n[10];
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		n[i] = s.at(i) - '0';
	}
	quicksort(0, s.size() - 1, n);
	for (int i = 0; i < s.size(); i++) {
		cout << n[i];
	}

	return 0;
}