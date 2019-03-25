#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int l, w;
char arr[50][50];
bool visit[50][50];
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
int ans = 0;

bool check(int row, int col) {

	if (row < 0 || col < 0 || row >= l || col >= w) return false;
	if (visit[row][col]) return false;
	if (arr[row][col] == 'W') return false;

	return true;
}

void BFS(int row, int col) {
	
	q.push(make_pair(row, col));
	visit[row][col] = true;

	int cur = 0;
	while (!q.empty()) {
		int qs = q.size();
		if (ans < cur) ans = cur;

		for (int sz = 0; sz < qs; ++sz) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];

				if (check(next_row, next_col)) {
					visit[next_row][next_col] = true;
					q.push(make_pair(next_row, next_col));
				}
			}

		}
		cur++;
	}

}

void init() {

	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < w; ++j) {
			visit[i][j] = false;
		}
	}

}

int main() {

	cin >> l >> w;

	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < l; ++i){
		for (int j = 0; j < w; ++j) {
			if (arr[i][j] == 'L')BFS(i, j);
			init();
		}
	}

	cout << ans << '\n';

	return 0;
}