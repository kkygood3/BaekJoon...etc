#include <iostream>
#define MAX 12
using namespace std;

int arr[MAX];
int ans[MAX];

int main() {

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		int index = 0;
		for (int j = 1; j <= n; ++j) {
			if (index == arr[i] && ans[j] == 0) {
				ans[j] = i;
				break;
			}
			if (ans[j] == 0) index++;
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}

	return 0;
}