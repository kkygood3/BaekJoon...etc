#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> //memcpy
using namespace std;

int n, m;
int arr[100][100];

int main() {

	cin.tie(0);  ios::sync_with_stdio(0);
	cin >> n >> m;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cin >> arr[row][m - 1 - col];
		}
	}

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cout << arr[row][col] << ' ';
		}
		cout << '\n';
	}

	return 0;
}