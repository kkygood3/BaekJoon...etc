#include <iostream>
#define MAX 200010
using namespace std;

int n;
int arr[MAX];

bool check() {
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] != arr[i + 1]) return false;
	}
	return true;
}

int main() {

	cin >> n;
	if (n == 1) {
		cout << "YES" << '\n';
		return 0;
	}
	int max_ = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (max_ < arr[i]) max_ = arr[i];
	}

	if (check()) {
		cout << "YES" << '\n';
		return 0;
	}

	while (1) {
		bool sw = false;
		for (int i = 0; i < n - 1;) {
			if (arr[i] == arr[i + 1]) {
				sw = true;
				if (i - 1 >= 0 && arr[i] < arr[i - 1]) {
					arr[i] = arr[i - 1];
					arr[i + 1] = arr[i - 1];
				}
				else if (i + 2 < n && arr[i + 1] < arr[i + 2]) {
					arr[i] = arr[i + 2];
					arr[i + 1] = arr[i + 2];
				}
				else {
					arr[i]++;
					arr[i + 1]++;
				}
				if (arr[i] == max_) {
					if (check()) {
						cout << "YES" << '\n';
						return 0;
					}
				}
				i += 2;
			}
			else i++;
		}
		
		if (!sw) {
			cout << "NO" << '\n';
			return 0;
		}

	}
	return 0;
}