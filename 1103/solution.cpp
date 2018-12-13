#include <iostream>
#define MAX 52
using namespace std;

int n, m;
char arr[MAX][MAX];
bool visit[MAX][MAX];
int dp[MAX][MAX][4];
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
int ans = 0;

void DFS(int row, int col, int cur) {
	/*cout << cur << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';*/
	if (ans == -1) return;

	visit[row][col] = true;

	for (int i = 0; i < 4; ++i) {
		int next_row = row + ((arr[row][col] - '0') * d_row[i]);
		int next_col = col + ((arr[row][col] - '0') * d_col[i]);
		
		if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m || arr[next_row][next_col] == 'H') {
			if (ans < cur + 1) ans = cur + 1;
			continue;
		}
		else {

			if (visit[next_row][next_col]) {
				ans = -1;
				return;
			}
			if (dp[next_row][next_col][i] <= cur) {
				dp[next_row][next_col][i] = cur + 1;
				DFS(next_row, next_col, cur + 1);
			}
		}
		if (ans == -1) return;
	}
	visit[row][col] = false;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	visit[0][0] = true;
	DFS(0, 0, 0);

	cout << ans << '\n';

	return 0;
}