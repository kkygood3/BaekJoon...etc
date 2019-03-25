#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char arr[25][25];
bool visit[25][25];
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
vector<int> v;

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= n || col >= n) return false;
	if (visit[row][col]) return false;
	if (arr[row][col] == '0') return false;
	return true;
}

void BFS(int r, int c) {

	visit[r][c] = true;
	q.push(make_pair(r, c));

	int cnt = 1;
	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (check(next_row, next_col)) {
				visit[next_row][next_col] = true;
				q.push(make_pair(next_row, next_col));
				cnt++;
			}
		}
	}
	v.push_back(cnt);
}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == '1' && !visit[i][j]) BFS(i, j);
		}
	}
	int sz = v.size();
	cout << sz << '\n';

	sort(v.begin(), v.end());

	for (int i = 0; i < sz; ++i) cout << v[i] << '\n';

	return 0;
}