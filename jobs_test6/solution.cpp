#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char arr[1001][1001];

int main() {

	int n;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	int mid = n / 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			arr[i][j] = ' ';
		}
	}

	for (int i = 0; i < n; i++) {
		arr[i][n - 1 - i] = '*';
		arr[i][n - 1 + i] = '*';
		if (i == mid) {
			for (int j = n - 1 - i; j <= n - 1 + i; j++) {
				arr[i][j] = '*';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (j == n + i) break;
			cout << arr[i][j];
		}
		if(i != n-1)cout << '\n';
	}

	return 0;
}