#include <iostream>
#define MAX 15

using namespace std;

int arr[MAX][MAX];
int t, n;
int d_row[4] = { 0,1,0,-1 };
int d_col[4] = { 1,0,-1,0 }; // 오른쪽, 아래, 왼쪽, 위

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= n || col >= n) return false;
	if (arr[row][col] != 0) return false;
	return true;
}

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = 0;
		}
	}
}

int main() {

	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n;

		int cnt = 1;
		int dir = 0;
		int row = 0;
		int col = 0;
		
		arr[0][0] = cnt;

		while (1) {
			row = row + d_row[dir];
			col = col + d_col[dir];
			if (check(row, col)) {
				arr[row][col] = ++cnt;
			}
			else {
				row = row - d_row[dir];
				col = col - d_col[dir];

				dir++;
				if (dir == 4) dir = 0;

				row = row + d_row[dir];
				col = col + d_col[dir];
				if (check(row, col)) {
					arr[row][col] = ++cnt;
				}
			}
			if (cnt == n * n) break;

		}
		cout << "#" << tc + 1 << '\n';
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		init();

	}

	return 0;
}