#include <iostream>
using namespace std;

int arr[150][150];
long int ans[150][150];
int n;
int d_row[2] = { 1,0 };
int d_col[2] = { 0,1 };

int main() {

	cin >> n;
	ans[0][0] = 1;
	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			cin >> arr[row][col];
			if (arr[row][col] != 0) {
				for (int i = 0; i < 2; ++i) {
					int next_row = row + (arr[row][col] * d_row[i]);
					int next_col = col + (arr[row][col] * d_col[i]);
					if (next_row < 0 || next_col < 0 || next_col >= n || next_row >= n) continue;
					ans[next_row][next_col] += ans[row][col];
				}
			}
		}
	}
	/*for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			cout << ans[row][col] << ' ';
			
		}
		cout << '\n';
	}*/
	
	cout << ans[n - 1][n - 1] << '\n';

	return 0;
}