#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define MAX 110
using namespace std;

vector<int> v;
bool arr[MAX][MAX];
int n, m, k;
queue<pair<int, int>> q;
bool visit[MAX][MAX];
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
int cnt;

bool check(int row, int col) {
	
	if (visit[row][col]) return false;
	if (row < 0 || col < 0 || row >= n || col >= m) return false;
	if (arr[row][col]) return false;

	return true;

}

void BFS() {

	while (!q.empty()) {

		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_row = row + d_row[i];
			int next_col = col + d_col[i];
			if (check(next_row,next_col)) {
				visit[next_row][next_col] = true;
				q.push(make_pair(next_row, next_col));
				cnt++;
			}
		}

	}
	v.push_back(cnt);
}

int main() {

	cin >> m >> n >> k;

	for (int i = 0; i < k; ++i) {
		int x_s, x_e, y_s, y_e;
		cin >> x_s >> y_s >> x_e >> y_e;

		for (int row = x_s; row < x_e; ++row) {
			for (int col = y_s; col < y_e; ++col) {
				arr[row][col] = true;
			}
		}
	}

	for (int col = m - 1; col >= 0; --col) {
		for (int row = 0; row < n; ++row) {
			if (!arr[row][col] && !visit[row][col]) {
				q.push(make_pair(row, col));
				cnt = 1;
				visit[row][col] = true;
				BFS();
			}
		}
	}
	int sz = v.size();
	cout << sz << '\n';
	sort(v.begin(),v.end());

	for (int i = 0; i < sz; ++i) {
		cout << v[i] << ' ';
	}
	cout << '\n';

	return 0;
}