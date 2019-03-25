#include <iostream>
using namespace std;

bool arr[3] = { 1,0,0 };

void swap(int x, int y) {
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

int main() {
	
	int n;
	cin >> n;

	int x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		swap(x - 1, y - 1);
	}

	for (int i = 0; i < 3; ++i) {
		//cout << arr[i] << '\n';
		if (arr[i]) cout << i + 1 << '\n';
	}

	return 0;
}