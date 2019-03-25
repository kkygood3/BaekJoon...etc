#include <iostream>
#include <queue>
#include <utility>
#define MAX 100
using namespace std;

queue<pair<int, int>> q;
queue<int> q_k;
int TOMATO[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int n, m, h;
int d_row[6] = { -1,0,1,0,0,0 };
int d_col[6] = { 0,-1,0,1,0,0 };
int d_high[6] = { 0,0,0,0,-1,1 };
int cnt = -1;

bool check(int row, int col, int high) {

	if (high < 0 || row < 0 || col < 0 || high >= h || row >= n || col >= m) return false;
	if (visit[high][row][col]) return false;
	if (TOMATO[high][row][col] != 0) return false;
	
	return true;
}

void BFS() {

	while (!q.empty()) {
		int qs = q.size();
		for (int sz = 0; sz < qs; sz++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			int cur_high = q_k.front();
			q.pop();
			q_k.pop();
			for (int i = 0; i < 6; i++) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];
				int next_high = cur_high + d_high[i];
				if (check(next_row, next_col, next_high)) {
					visit[next_high][next_row][next_col] = true;
					TOMATO[next_high][next_row][next_col] = 1;
					q.push(make_pair(next_row, next_col));
					q_k.push(next_high);
				}
			}
		}
		cnt++;
	}

}

int main() {

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> TOMATO[i][j][k];
				if (TOMATO[i][j][k] == 1) {
					visit[i][j][k] = true;
					q.push(make_pair(j, k));
					q_k.push(i);
				}
			}
		}
	}

	BFS();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (!TOMATO[i][j][k]) {
					cout << -1 << '\n';
					return 0;
				}
				//cout << TOMATO[i][j][k] << ' ';
			}
			//cout << '\n';
		}
	}

	cout << cnt << '\n';

	return 0;
}