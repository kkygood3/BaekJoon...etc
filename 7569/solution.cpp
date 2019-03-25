#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct Info {
	int row;
	int col;
	int height;
};
int m, n, h;	// col, row, height
int arr[100][100][100];
int d_row[6] = { 0,0,-1,1,0,0 };
int d_col[6] = { -1,1,0,0,0,0 };
int d_height[6] = { 0,0,0,0,-1,1 };
queue<Info> q;

bool check(int row, int col, int height) {
	if (row < 0 || row >= n || col < 0 || col >= m || height < 0 || height >= h) return false;
	if (arr[row][col][height] == -1 || arr[row][col][height] == 1) return false;

	return true;
}

int BFS() {
	
	int day = -1;
	while (!q.empty()) {
		int qs = q.size();
		for (int sz = 0; sz < qs; ++sz) {
			int cur_row = q.front().row;
			int cur_col = q.front().col;
			int cur_height = q.front().height;
			q.pop();

			for (int i = 0; i < 6; ++i) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];
				int next_height = cur_height + d_height[i];

				if (check(next_row, next_col, next_height)) {
					Info info = { next_row, next_col, next_height };
					q.push(info);
					arr[next_row][next_col][next_height] = 1;
				}
			}
		}
		day++;
	}

	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr[i][j][k] == 0)
					return -1;
			}
		}
	}

	return day;
}

int main() {

	cin >> m >> n >> h;

	bool done = true;

	for (int k = 0; k < h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					Info info = { i,j,k };
					q.push(info);
				}
				else if (arr[i][j][k] == 0) {
					done = false;
				}
			}
		}
	}

	if (done) {
		cout << 0 << '\n';
	} else {
		cout << BFS() << '\n';
	}

	return 0;
}