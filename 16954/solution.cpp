#include <iostream>
#include <utility>
#include <queue>
using namespace std;

char arr[8][8];
bool visit[8][8];
queue<pair<int, int>> q;
int d_row[9] = { 0,0,-1,1,-1,1,-1,1,0 };
int d_col[9] = { -1,1,0,0,-1,1,1,-1,0 };

bool check(int row, int col) {
	if (row < 0 || row >= 8 || col < 0 || col >= 8 || arr[row][col] == '#') return false;
	if (row > 0 && arr[row - 1][col] == '#') return false;
	
	return true;
}

void init() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			visit[i][j] = false;
		}
	}
}

void move_arr() {
	for (int i = 6; i >= 0; --i) {
		for (int j = 0; j < 8; ++j) {
			arr[i + 1][j] = arr[i][j];
		}
	}
	for (int j = 0; j < 8; ++j) {
		arr[0][j] = '.';
	}
}

int BFS(int row,int col) {
	q.push(make_pair(row, col));
	
	while (!q.empty()) {
		int sz = q.size();
		for (int qs = 0; qs < sz; ++qs) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();
			for (int i = 0; i < 9; ++i) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];
				if (check(next_row, next_col) && !visit[next_row][next_col]) {
					if (next_row == 0 && next_col == 7) return 1;
					visit[next_row][next_col] = true;
					q.push(make_pair(next_row, next_col));
				}
			}
		}
		init();
		move_arr();
	}
	return 0;
}

int main() {

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> arr[i][j];
		}
	}

	cout << BFS(7, 0) << '\n';

	return 0;
}