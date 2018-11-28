#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string arr[102][102];
void swap(string **a, string **b) {
	string tmp;
	tmp = **a;
	**a = **b;
	**b = tmp;
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, w;
	cin >> n >> w;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	if (n == 1);
	else if (n == 2) {
		for (int i = 0; i < w; i++) {
			for (int i = 1; i < 2; i++) {
				swap(arr[1][i], arr[1][i + 1]);
			}
			for (int i = 1; i < 2; i++) {
				swap(arr[i][n], arr[i + 1][n]);
			}
			for (int i = 2; i > 1; i--) {
				swap(arr[n][i], arr[n][i - 1]);
			}
		}
	}
	else if (n % 2 != 0) {
		for (int i = 0; i < w; i++) {
			for (int i = 1; i < n; i++) {
				swap(arr[1][i], arr[1][i + 1]);	
			}
			for (int i = 1; i < n; i++) {
				swap(arr[i][n], arr[i + 1][n]);
			}
			for (int i = n; i > 1; i--) {
				swap(arr[n][i], arr[n][i - 1]);
			}
			for (int i = n; i > 2; i--) {
				swap(arr[i][1], arr[i - 1][1]);
			}
		}
	}
	else {
		for (int i = 0; i < w; i++) {
			for (int i = 1; i < n; i++) {
				swap(arr[1][i], arr[1][i + 1]);
			}
			for (int i = 1; i < n; i++) {
				swap(arr[i][n], arr[i + 1][n]);
			}
			for (int i = n; i > 1; i--) {
				swap(arr[n][i], arr[n][i - 1]);
			}
			for (int i = n; i > 2; i--) {
				swap(arr[i][1], arr[i - 1][1]);
			}
		}
		if (n == 4) {
			for (int i = 0; i < w; i++) {
				swap(arr[2][2], arr[2][3]);
				swap(arr[2][3], arr[3][3]);
				swap(arr[3][3], arr[3][2]);
			}
		}
		else {
			for (int i = 0; i < w; i++) {
				for (int i = 2; i < n - 1; i++) {
					swap(arr[2][i], arr[2][i + 1]);
				}
				for (int i = 2; i < n - 1; i++) {
					swap(arr[i][n - 1], arr[i + 1][n - 1]);
				}
				for (int i = n - 1; i > 3; i--) {
					swap(arr[n - 1][i], arr[n - 1][i - 1]);
				}
				for (int i = n - 1; i > 3; i--) {
					swap(arr[i][n - 1], arr[i - 1][n - 1]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}