#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[110];
int ans = 0;

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(&arr[0], &arr[n]);

	for (int i = 0; i < n - 1; i += 2) {
		ans += arr[i + 1] - arr[i];
	}
	cout << ans << '\n';

	return 0;
}