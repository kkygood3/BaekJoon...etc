#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int n, m;
int arr[301][301];
int next_arr[301][301];
bool visit[301][301];
queue<pair<int, int>> q;
int d_row[4] = { 0,0,-1,1 };
int d_col[4] = { -1,1,0,0 };

bool check(int row,int col) {
	if (row < 0 || row >= n || col < 0 || col >= m) return false;
	return true;
}

void BFS(int row, int col) {
	q.push(make_pair(row, col));
	visit[row][col] = true;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (check(next_row, next_col) && arr[next_row][next_col] != 0 && !visit[next_row][next_col]) {
				q.push(make_pair(next_row, next_col));
				visit[next_row][next_col] = true;
			}
		}
	}
}

int isTwo() {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] != 0 && !visit[i][j]) {
				cnt++;
				BFS(i, j);
				if (cnt > 1) return 2;
			}
		}
	}
	if (cnt == 0) return 0;

	return 1;
}

void melt() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] != 0) {
				next_arr[i][j] = arr[i][j];
				for (int d = 0; d < 4; ++d) {
					int next_row = i + d_row[d];
					int next_col = j + d_col[d];
					if (check(next_row, next_col) && arr[next_row][next_col] == 0) {
						next_arr[i][j] -= 1;
					}
				}
				if (next_arr[i][j] < 0) next_arr[i][j] = 0;
			}
		}
	}
	memcpy(arr, next_arr, sizeof(arr));
}

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visit[i][j] = false;
			next_arr[i][j] = 0;
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	int year = 0;
	while (1) {
		int ans = isTwo();
		if (ans == 0) {
			cout << 0;
			return 0;
		}
		else if (ans == 2) {
			cout << year;
			return 0;
		}
		init();
		melt();
		year++;
	}
	

	return 0;
}