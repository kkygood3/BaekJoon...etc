#include <iostream>
#include <queue>
#include <utility>
#define MAX 1000
using namespace std;

int maze[MAX][MAX];
int n, m;
int d_row[4] = { 1,0,-1,0 };
int d_col[4] = { 0,1,0,-1 };
bool D[MAX][MAX];
int value_min = 9999;
queue<pair<int,int>> q;
bool visit[MAX][MAX];

bool check(int row, int col) {
	if (row < 0 || row >= n || col < 0 || col >= m) return true;
	if (D[row][col]) return true;
	else return false;
}

bool check_BFS(int row, int col) {
	if (row < 0 || row >= n || col < 0 || col >= m) return true;
	if (visit[row][col]) return true;
	else return false;
}

void BFS() {

	q.push(make_pair(n - 1, 0));
	visit[n - 1][0] = true;
	int ans = 0;

	while (!q.empty()) {
		int qs = q.size();
		for (int z = 0; z < qs; z++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();
			/*cout << ans << '\n';
			for (int row = 0; row < n; row++) {
				for (int col = 0; col < m; col++) {
					cout << visit[row][col];
				}
				cout << '\n';
			}*/
			if (cur_row == 0 && cur_col == m - 1) {
				cout << ans << '\n';
				return;
			}
			for (int i = 0; i < 4; i++) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];
				if (!check_BFS(next_row,next_col)) {
						visit[next_row][next_col] = true;
						q.push(make_pair(next_row, next_col));
				}
			}
		}
		ans++;
	}
}

void DFS(int row, int col, int dis) {

	if (dis > value_min) return;

	if (row == 0 && col == m - 1) {
		value_min = value_min < dis ? value_min : dis;
		return;
	}


	for (int i = 0; i < 4; i++) {
		if (!check(row + d_row[i], col + d_col[i])) {
			D[row + d_row[i]][col + d_col[i]] = true;
			DFS(row + d_row[i], col + d_col[i], dis + 1);
			D[row + d_row[i]][col + d_col[i]] = false;
		}
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cin >> maze[row][col];
			if (maze[row][col] == 1) {
				visit[row][col] = true;
				D[row][col] = true;
			}
		}
	}
	
	BFS();
	return 0;
}