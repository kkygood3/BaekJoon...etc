#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool arr[50][50];
bool visit[50][50][2]; // 0 왼 1 오른쪽
int n, m, h;
int ans = 99999;

bool check(int row, int col) {

	if (row <= 0 || col <= 0 || row > h || col >= n) return false; // 끝에도 안댐
	if (visit[row][col][1] || visit[row][col][0]) return false; // 오른쪽이 연결 or 왼쪽으로 연결

	return true;
}

bool find(int row, int col) {

	int start = col;

	while (row < h + 1) {
		if (visit[row][col][1]) col++;
		else if (visit[row][col][0]) col--;
		row++;
	}

	if (start != col) return false;
	else return true;

}

bool simul() {

	for (int i = 1; i < n; ++i) {		// 끝은 자동
		if (!find(1, i)) {
			return false;
		}
	}

	return true;
}

void DFS(int cur_row, int cur_col,int cur) {

	if (cur == 4) return;
	if (ans <= cur) return;
	if (simul()) {
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (visit[i][j][0]) cout << 'l';
				else if (visit[i][j][1]) cout << 'r';
				else cout << '.';
			}
			cout << '\n';
		}
		if (ans > cur) ans = cur;
	}

	for (int row = cur_row; row <= h; ++row) {
		for (int col = 1; col < n; ++col) {
			if (row == cur_row && col <= cur_col) continue;
			if (check(row, col)) {
				visit[row][col][1] = true;
				visit[row][col + 1][0] = true;
				DFS(row, col, cur + 1);
				visit[row][col][1] = false;
				visit[row][col + 1][0] = false;
			}

		}
	}


}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m >> h;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		visit[a][b][1] = true;
		visit[a][b + 1][0] = true;
	}

	DFS(1, 0, 0);

	if (ans == 99999) {
		cout << "-1" << '\n';
		return 0;
	}
	cout << ans << '\n';

	return 0;
}