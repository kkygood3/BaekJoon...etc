#include <iostream>
#define MAX 10
using namespace std;

int n, m;
int arr[MAX][MAX];
int d_row[8] = { -1,1,0,0,-1,-1,1,1 };
int d_col[8] = { 0,0,-1,1,-1,1,-1,1 }; // 위 아래 왼쪽 오른쪽 왼쪽위 오른쪽위 왼쪽아래 오른쪽아래

int same_color_check(int row, int col, int color) {
	if (row <= 0 || col <= 0 || row > n || col > n || arr[row][col] == 0) return 0; // 그만
	if (arr[row][col] == color) return 1; // 그만하고 지나온길 색깔 바꾸기
	return 2; // 계속
}

void simulation(int row, int col, int color) {

	for (int dir = 0; dir < 8; ++dir) {
		int next_row = row + d_row[dir];
		int next_col = col + d_col[dir];
		int cnt = 0;
		if (arr[next_row][next_col] != color && arr[next_row][next_col] != 0) {
			while (1) {
				if (same_color_check(next_row, next_col, color) == 1 && cnt >= 1) {
					for (int i = 0; i < cnt; ++i) {
						next_row -= d_row[dir];
						next_col -= d_col[dir];
						arr[next_row][next_col] = color;
					}
					break;
				}
				else if (same_color_check(next_row, next_col, color) == 1 && cnt == 0) break;
				else if (same_color_check(next_row, next_col, color) == 0) break;
				else {
					cnt++;
					next_row += d_row[dir];
					next_col += d_col[dir];
				}
			}
		}
	}
	/*for (int row = 1; row <= n; ++row) {
		for (int col = 1; col <= n; ++col) {
			cout << arr[row][col] << ' ';
		}
		cout << '\n';
	}*/
}

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			arr[i][j] = 0;
		}
	}
}

int main() {

	n = 6;
	cin >> m;
	arr[n / 2][n / 2] = 2; // 백돌
	arr[n / 2 + 1][n / 2] = 1;
	arr[n / 2][n / 2 + 1] = 1;
	arr[n / 2 + 1][n / 2 + 1] = 2;

	int color = 0;
	for (int i = 0; i < m; ++i) {
		int row, col;
		color++;
		if (color == 3) color = 1;
		cin >> row >> col;
		arr[row][col] = color;
		simulation(row, col, color);
	}
	int black = 0;
	int white = 0;
	for (int row = 1; row <= n; ++row) {
		for (int col = 1; col <= n; ++col) {
			if (arr[row][col] == 1) {
				black++;
				cout << 'B';
			}
			if (arr[row][col] == 2) {
				white++;
				cout << 'W';
			}
			if (arr[row][col] == 0) cout << '.';
		}
		cout << '\n';
	}
	(black > white) ? cout << "Black" << '\n' : cout << "White" << '\n';

	return 0;
}