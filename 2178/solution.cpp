#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <string>
#define MAX 110
using namespace std;

queue<pair<int, int>> q;
bool arr[MAX][MAX];
bool visit[MAX][MAX];
int n, m;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
int cnt = 1;

bool check(int row, int col) {

	if (row < 0 || col < 0 || row >= n || col >= m) return false;
	if (!arr[row][col]) return false;
	if (visit[row][col]) return false;

	return true;

}

void BFS() {

	visit[0][0] = true;
	q.push(make_pair(0,0));

	while (!q.empty()) {
		int qs = q.size();
		
		/*for (int row = 0; row < n; ++row) {

			for (int col = 0; col < m; ++col) {
				cout << visit[row][col] << ' ';
			}
			cout << '\n';
		}

		cout << cnt << '\n';*/

		for (int sz = 0; sz < qs; ++sz) {
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int next_row = row + d_row[i];
				int next_col = col + d_col[i];
				if (next_row == n - 1 && next_col == m - 1) {
					++cnt;
					return;
				}
				if (check(next_row, next_col)) {
					visit[next_row][next_col] = true;
					q.push(make_pair(next_row, next_col));
				}
			}

		}
		++cnt;
	}
}

int main() {

	cin >> n >> m;

	string temp;
	for (int row = 0; row < n; ++row) {
		
		cin >> temp;

		for (int col = 0; col < m; ++col) {
			arr[row][col] = temp[col] - '0';
		}
	}

	BFS();

	//for (int row = 0; row < n; ++row) {

	//	for (int col = 0; col < m; ++col) {
	//		cout << visit[row][col] << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << cnt << '\n';

	return 0;
}