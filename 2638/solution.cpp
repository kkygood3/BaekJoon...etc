#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int arr[101][101];
queue<pair<int, int>> q;
queue<pair<int, int>> erase;
bool visit[101][101];
int cheese;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
bool sw;

void BFS(int row , int col) {

	visit[row][col] = true;
	q.push(make_pair(row, col));

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m) {
				cheese++;
				return;
			}
			else if (arr[next_row][next_col] == 0 && !visit[next_row][next_col]) {
				visit[next_row][next_col] = true;
				q.push(make_pair(next_row, next_col));
			}
		}
	}

}

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visit[i][j] = false;
		}
	}
	while (!q.empty()) q.pop();
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}
	
	int cur = 0;
	while (1) {
		bool keep = false;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j] == 1) {
					keep = true;

					cheese = 0;

					for (int k = 0; k < 4; ++k) {
						int next_row = i + d_row[k];
						int next_col = j + d_col[k];
						if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m && arr[next_row][next_col] == 0) {
							BFS(next_row, next_col);

							init();
						}
					}

					if (cheese >= 2) {
						erase.push(make_pair(i, j));
					}
				}
			}
		}

		//cout << cur << '\n';
		while (!erase.empty()) {
			arr[erase.front().first][erase.front().second] = 0;
			//cout << erase.front().first << ',' << erase.front().second << '\n';
			erase.pop();
		}

		if (!keep) break;
		cur++;
	}

	cout << cur << '\n';

	return 0;
}