#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
#define MAX 1000
using namespace std;

int n, m;
bool maze[MAX][MAX];
bool temp[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> q;
int d_row[4] = { -1,0,1,0 };
int d_col[4] = { 0,-1,0,1 };
vector<pair<int, int>> v;
int ans = 9999999;
int Min = 9999999;

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= n || col >= m) return false;
	if (!visit[row][col]) return true;
	else return false;
}

void BFS() {

	while (!q.empty()) q.pop();
	q.push(make_pair(n - 1, 0));
	visit[n - 1][0] = true;

	int cnt = 0;

	while (!q.empty()) {
		int sz = q.size();
		for (int qs = 0; qs < sz; qs++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();

			if (cur_row == 0 && cur_col == m - 1) {
				ans = cnt;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];

				if (check(next_row, next_col)) {
					q.push(make_pair(next_row, next_col));
					visit[next_row][next_col] = true;
				}

			}
		}
		cnt++;
		if (cnt >= Min) return;
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++){
			cin >> maze[row][col];
			if (maze[row][col] == 1) {
				visit[row][col] = true;
				v.push_back(make_pair(row, col));
			}
		}
	}
	if (v.empty()) {
		cout << n + m - 2 << '\n';
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		int row = v[i].first;
		int col = v[i].second;
		memcpy(visit, maze, sizeof(maze));
		visit[row][col] = 0;
		
		BFS();
		Min = Min > ans ? ans : Min;
		if (ans == n + m - 2) {
			cout << ans << '\n';
			return 0;
		}
	}

	cout << ans << '\n';

	return 0;
}