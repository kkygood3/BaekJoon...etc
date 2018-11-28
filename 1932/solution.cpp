#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];

int main() {

	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			arr[i][j] += max({arr[i-1][j], arr[i-1][j - 1] });
		}
	}
	int ans = 0;
	for (int j = 0; j < n; j++) {
		if (ans < arr[n - 1][j]) ans = arr[n - 1][j];
	}
	cout << ans;
	return 0;
}