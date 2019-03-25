#include <iostream>
#define MAX 1000000009
using namespace std;

int n;
int arr[MAX];

bool check(){
	for (int i = 0; i < n - 1; ++i) {
		if(arr[i] != arr[i + 1]) return true;
	}
	return false;
}

int main() {

	cin >> n;
	int max_ = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] > max_) max_ = arr[i];
	}
	
	while (check()) {
		bool sw = false;
		for (int i = 0; i < n; ++i) {
			if (arr[i] == arr[i + 1] && arr[i] <= max_) {
				sw = true;
				arr[i]++;
				arr[i + 1]++;
				i += 2;
			}
		}

		if (!sw) {

		}

	}

	cout << "YES" << '\n';

	return 0;
}