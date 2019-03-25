// 다른 방법 : 1시간 , 해당 방법 : 25분
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define MAX 1010
using namespace std;

queue<pair<int, int>> q_J;
queue<pair<int, int>> q_F;
char arr[MAX][MAX];
int n, m, J_row, J_col, F_row, F_col; // 초기값
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
int range = 1; // 거리
int ans = 0; // 답

bool check_F(int row, int col) {

	if (row < 0 || col < 0 || row >= n || col >= m) return false;
	if (arr[row][col] == '#' || arr[row][col] == 'F') return false;
	return true;
}

bool check_J(int row, int col) {

	if(arr[row][col] == '.') return true;
	return false;
}

bool check_finish(int row, int col) {
	
	if (row < 0 || col < 0 || row >= n || col >= m) {
		ans = range;
		return true;
	}
	return false;
}

void BFS() {

	while (!q_J.empty()) {
		int qs_F = q_F.size();
		/*for (int row = 0; row < n; ++row) {
			for (int col = 0; col < m; ++col) {
				cout << arr[row][col];
			}
			cout << '\n';
		}*/
		for (int sz = 0; sz < qs_F; ++sz) {
			int row = q_F.front().first;
			int col = q_F.front().second;
			q_F.pop();
			for (int i = 0; i < 4; ++i) {
				int next_row = row + d_row[i];
				int next_col = col + d_col[i];
				if (check_F(next_row, next_col)) {
					arr[next_row][next_col] = 'F';
					q_F.push(make_pair(next_row, next_col));
				}
			}
		}

		int qs_J = q_J.size();
		for (int sz = 0; sz < qs_J; ++sz) {
			int row = q_J.front().first;
			int col = q_J.front().second;
			q_J.pop();
			for (int i = 0; i < 4; ++i) {
				int next_row = row + d_row[i];
				int next_col = col + d_col[i];
				if (check_finish(next_row, next_col)) return;
				if (check_J(next_row, next_col)) {
					arr[next_row][next_col] = 'J';
					q_J.push(make_pair(next_row, next_col));
				}
			}
		}
		range++;
	}
}

int main() {

	cin >> n >> m;

	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < m; ++col) {
			cin >> arr[row][col];
			if (arr[row][col] == 'J') {
				J_row = row;
				J_col = col;
				q_J.push(make_pair(J_row, J_col));
			}
			if (arr[row][col] == 'F') {
				F_row = row;
				F_col = col;
				q_F.push(make_pair(F_row, F_col));
			}
		}
	}

	BFS();

	if (ans == 0) cout << "IMPOSSIBLE" << '\n';
	else cout << ans << '\n';

	return 0;
}