#include <iostream>
#include <queue>
using namespace std;

struct A {
	int row;
	int col;
	int dir;
};

char arr[52][52];
bool visit[52][52][2];		// 2는 방향 세로, 가로
int n;
int s_row, d_row, s_col, d_col, s_dir, d_dir;
int i_row[4] = { -1,1,0,0 };
int i_col[4] = { 0,0,-1,1 };		// 위 아래 왼쪽 오른쪽
int ans = 0;
queue<A> q;


bool check(int row, int col, int dir, int i) {
	if (row < 0 || col < 0 || row >= n || col >= n) return false;
	if (visit[row][col][dir]) return false;

	if (dir == 0) {		//세로
		if (i == 0) {
			if (arr[row - 1][col] == '1' || row - 1 < 0) return false;
		}
		else if (i == 1) {
			if (arr[row + 1][col] == '1' || row + 1 >= n) return false;
		}
		else if (i == 2) {
			if (arr[row][col] == '1' || row < 0) return false;
			if (arr[row + 1][col] == '1' || row + 1 >= n) return false;
			if (arr[row - 1][col] == '1' || row - 1 < 0) return false;
		}
		else if (i == 3) {
			if (arr[row][col] == '1' || row >= n) return false;
			if (arr[row + 1][col] == '1' || row + 1 >= n) return false;
			if (arr[row - 1][col] == '1' || row - 1 < 0) return false;
		}
	}
	else if (dir == 1) {	//가로
		if (i == 0) {
			if (arr[row][col] == '1' || col < 0) return false;
			if (arr[row][col + 1] == '1' || col + 1 >= n) return false;
			if (arr[row][col - 1] == '1' || col - 1 < 0) return false;
		}
		else if (i == 1) {
			if (arr[row][col] == '1' || col >= n) return false;
			if (arr[row][col + 1] == '1' || col + 1 >= n) return false;
			if (arr[row][col - 1] == '1' || col - 1 < 0) return false;
		}
		else if (i == 2) {
			if (arr[row][col - 1] == '1' || col - 1 < 0) return false;
		}
		else if (i == 3) {
			if (arr[row][col + 1] == '1' || col + 1 >= n) return false;
		}
	}

	return true;
}

void BFS(int r, int c, int d) {

	visit[r][c][d] = true;
	A a;
	a.row = r;
	a.col = c;
	a.dir = d;
	q.push(a);
	
	
	int cur = 0;
	while (!q.empty()) {
		int qs = q.size();
		/*cout << cur << '\n';
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visit[i][j][0] && visit[i][j][1]) cout << 'o';
				else if (visit[i][j][0]) cout << 0;
				else if (visit[i][j][1]) cout << 1;
				else cout << 'x';
			}
			cout << '\n';
		}*/
		for (int sz = 0; sz < qs; sz++) {
			int row = q.front().row;
			int col = q.front().col;
			int dir = q.front().dir;
			q.pop();
			
			if (row == d_row && col == d_col && dir == d_dir) {
				ans = cur;
				return;
			}

			for (int i = 0; i < 5; ++i) {
				if (i < 4) {
					int next_row = row + i_row[i];
					int next_col = col + i_col[i];
					if (check(next_row, next_col, dir, i)) {
						visit[next_row][next_col][dir] = true;
						A a;
						a.row = next_row;
						a.col = next_col;
						a.dir = dir;
						q.push(a);
					}
				}
				else if (i == 4) {
					if (dir == 0 && !visit[row][col][1]) {
						if (arr[row - 1][col - 1] == '1' || arr[row][col - 1] == '1' || arr[row + 1][col - 1] == '1' ||
							arr[row - 1][col + 1] == '1' || arr[row][col + 1] == '1' || arr[row + 1][col + 1] == '1' ||
							arr[row][col] == '1' || arr[row - 1][col] == '1' || arr[row + 1][col] == '1' ||
							row - 1 < 0 || col - 1 < 0 || row + 1 >= n || col + 1 >= n) break;
						else {
							visit[row][col][1] = true;
							A a;
							a.row = row;
							a.col = col;
							a.dir = 1;
							q.push(a);
						}
					}
					else if (dir == 1 && !visit[row][col][0]) {
						if (arr[row - 1][col - 1] == '1' || arr[row][col - 1] == '1' || arr[row + 1][col - 1] == '1' ||
							arr[row - 1][col + 1] == '1' || arr[row][col + 1] == '1' || arr[row + 1][col + 1] == '1' ||
							arr[row][col] == '1' || arr[row - 1][col] == '1' || arr[row + 1][col] == '1' ||
							row - 1 < 0 || col - 1 < 0 || row + 1 >= n || col + 1 >= n) break;
						else {
							visit[row][col][0] = true;
							A a;
							a.row = row;
							a.col = col;
							a.dir = 0;
							q.push(a);
						}
					}
				}
			}
		}
		cur++;
	}
}

int main() {

	cin >> n;

	int cnt_B = 0;
	int cnt_E = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') cnt_B++;
			if (arr[i][j] == 'E') cnt_E++;
			if (arr[i][j] == 'B' && cnt_B == 2) {
				if (i - 1 >= 0 && arr[i - 1][j] == 'B') {
					s_row = i;
					s_col = j;
					s_dir = 0;	// 세로
				}
				else if (j - 1 >= 0 && arr[i][j - 1] == 'B') {
					s_row = i;
					s_col = j;
					s_dir = 1;	// 가로
				}
			}
			if (arr[i][j] == 'E' && cnt_E == 2) {
				if (i - 1 >= 0 && arr[i - 1][j] == 'E') {
					d_row = i;
					d_col = j;
					d_dir = 0;	// 세로
				}
				else if (j - 1 >= 0 && arr[i][j - 1] == 'E') {
					d_row = i;
					d_col = j;
					d_dir = 1;	// 가로
				}
			}
		}
	}

	BFS(s_row, s_col, s_dir);
	
	cout << ans << '\n';

	return 0;
}