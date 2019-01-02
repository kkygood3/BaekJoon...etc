#include <iostream>
#include <queue>
using namespace std;

struct A {
	int row;
	int col;
	int skill;
};

int k, w, h;
bool arr[205][205];
bool visit[205][205][32];
int d_row[12] = { -1,1,0,0,-1,-1,-2,-2,1,1,2,2 };
int d_col[12] = { 0,0,-1,1,-2,2,1,-1,2,-2,1,-1 };
queue<A> q;
int ans = -1;

bool check(int row, int col, int skill) {
	if (row < 0 || col < 0 || row >= h || col >= w) return false;
	if (visit[row][col][skill]) return false;
	if (arr[row][col] == 1) return false;
	
	return true;
}

void BFS(int row, int col) {

	visit[row][col][0] = true;
	A a;
	a.row = row, a.col = col, a.skill = k;
	q.push(a);

	int cur = 0;
	while (!q.empty()) {
		int qs = q.size();

		/*cout << cur << '\n';
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if(visit[i][j][0] || visit[i][j][1])cout << 1 << ' ';
				else cout << 0 << ' ';
			}
			cout << '\n';
		}*/

		for (int sz = 0; sz < qs; ++sz) {
			row = q.front().row;
			col = q.front().col;
			int skill = q.front().skill;
			q.pop();
			if (row == h - 1 && col == w - 1) {
				ans = cur;
				return;
			}

			if (skill > 0) {
				for (int i = 0; i < 4; ++i) {
					int next_row = row + d_row[i];
					int next_col = col + d_col[i];
					if (check(next_row,next_col, skill)) {
						visit[next_row][next_col][skill] = true;
						A a;
						a.row = next_row, a.col = next_col, a.skill = skill;
						q.push(a);
					}
				}
				for (int i = 4; i < 12; ++i) {
					int next_row = row + d_row[i];
					int next_col = col + d_col[i];
					if (check(next_row, next_col, skill - 1)) {
						visit[next_row][next_col][skill-1] = true;
						A a;
						a.row = next_row, a.col = next_col, a.skill = skill - 1;
						q.push(a);
					}
				}
			}
			else {
				for (int i = 0; i < 4; ++i) {
					int next_row = row + d_row[i];
					int next_col = col + d_col[i];
					if (check(next_row, next_col, skill)) {
						visit[next_row][next_col][skill] = true;
						A a;
						a.row = next_row, a.col = next_col, a.skill = skill;
						q.push(a);
					}
				}
			}
		}
		cur++;
	}

}

int main() {

	cin >> k >> w >> h;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> arr[i][j];
		}
	}

	BFS(0, 0);

	cout << ans << '\n';

	return 0;
}