#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[105][105];
bool visit[105][105];
int n;
int max_len;
int ans;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

bool check(int row, int col, int stage) {
	if (row < 0 || col < 0 || row >= n || col >= n) return false;
	if (!visit[row][col] && arr[row][col] > stage) return true;
	return false;
}

void BFS(int row, int col, int stage) {
	visit[row][col] = true;
	q.push(make_pair(row, col));

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (check(next_row,next_col, stage)) {
				visit[next_row][next_col] = true;
				q.push(make_pair(next_row, next_col));
			}
		}

	}

}

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visit[i][j] = false;
		}
	}
}

int main() {

	cin >> n;
	max_len = 0;
	ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (max_len < arr[i][j]) max_len = arr[i][j];
		}
	}

	int stage = 0;
	while (stage < max_len) {
		int t_ans = 0;
		for (int row = 0; row < n; ++row) {
			for (int col = 0; col < n; ++col) {
				if (!visit[row][col] && arr[row][col] > stage) {
					BFS(row, col, stage);
					t_ans++;
				}
			}
		}

		init();
		if (ans < t_ans) ans = t_ans;

		stage++;
	}

	cout << ans << '\n';

	return 0;
}