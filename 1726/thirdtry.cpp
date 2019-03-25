#include <queue>
#include <iostream>
#define MAX 110
using namespace std;

struct Robot {
	int row;
	int col;
	int dir;
};

queue<Robot> q;
int m, n;
bool arr[MAX][MAX];
bool visit[MAX][MAX][4];
int d_row[4] = { -1,0,1,0 };
int d_col[4] = { 0,1,0,-1 }; // 위 오른쪽 아래 왼쪽 동서남북 >> 1320
Robot start, goal;
int ans = 0;

bool check_triple(int row, int col, int dir) {
	if (row >= m || col >= n || row < 0 || col < 0) return false;
	if (arr[row][col]) return false;
	if (visit[row][col][dir]) return false;
	//cout << "트리플체크" << '\n';
	int back_row = row - d_row[dir];
	int back_col = col - d_col[dir];
	if (arr[back_row][back_col]) return false;
	int back_back_row = row - (2 * d_row[dir]);
	int back_back_col = col - (2 * d_col[dir]);
	if (arr[back_back_row][back_back_col]) return false;

	return true;
}

bool check_double(int row, int col, int dir) {

	if (row >= m || col >= n || row < 0 || col < 0) return false;
	if (arr[row][col]) return false;
	if (visit[row][col][dir]) return false;
	//cout << "더블체크" << '\n';
	int back_row = row - d_row[dir];
	int back_col = col - d_col[dir];
	if (arr[back_row][back_col]) return false;

	return true;
}

bool check(int row, int col, int dir) {

	if (row >= m || col >= n || row < 0 || col < 0) return false;
	if (arr[row][col]) return false;
	if (visit[row][col][dir]) return false;

	return true;
}

void BFS() {

	visit[start.row][start.col][start.dir] = true;
	q.push(start);

	while (!q.empty()) {
		int qs = q.size();
		//cout << ans << '\n';
		//for (int i = 0; i < m; ++i) {
		//	for (int j = 0; j < n; ++j) {
		//		//if (visit[i][j][0] == 1 || visit[i][j][1] == 1 || visit[i][j][2] == 1 || visit[i][j][3] == 1)cout << "1" << ' ';
		//		//else cout << '0' << ' ';
		//		cout << visit[i][j][2] << ' ';
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
		for (int sz = 0; sz < qs; ++sz) {
			
			int cur_row = q.front().row;
			int cur_col = q.front().col;
			int cur_dir = q.front().dir;
			q.pop();
			//cout << cur_row << ' ' << cur_col << ' ' << cur_dir << '\n';
			if (cur_row == goal.row && cur_col == goal.col && cur_dir == goal.dir) {
				//cout << "정답" << '\n';
				return;
			}

			Robot next;
			next.row = cur_row + (3 * d_row[cur_dir]);	// 앞으로 3칸
			next.col = cur_col + (3 * d_col[cur_dir]);
			next.dir = cur_dir;
			if (check_triple(next.row, next.col, next.dir)) {
				//cout << "3칸" << '\n';
				visit[next.row][next.col][next.dir] = true;
				q.push(next);
			}

			next.row = cur_row + (2 * d_row[cur_dir]);	// 앞으로 2칸
			next.col = cur_col + (2 * d_col[cur_dir]);
			next.dir = cur_dir;
			if (check_double(next.row, next.col, next.dir)) {
				//cout << "2칸" << '\n';
				visit[next.row][next.col][next.dir] = true;
				q.push(next);
			}

			next.row = cur_row + d_row[cur_dir];	// 앞으로 1칸
			next.col = cur_col + d_col[cur_dir];
			next.dir = cur_dir;
			if (check(next.row, next.col, next.dir)) {
				visit[next.row][next.col][next.dir] = true;
				q.push(next);
			}

			next.row = cur_row;							// 시계방향
			next.col = cur_col;
			next.dir = cur_dir + 1;
			if (next.dir == 4) next.dir = 0;
			if (check(next.row, next.col, next.dir)) {
				visit[next.row][next.col][next.dir] = true;
				q.push(next);
			}

			next.row = cur_row;							// 반시계방향
			next.col = cur_col;
			next.dir = cur_dir - 1;
			if (next.dir == -1) next.dir = 3;
			if (check(next.row, next.col, next.dir)) {
				visit[next.row][next.col][next.dir] = true;
				q.push(next);
			}

		}
		ans++;
	}
	
}

int main() {

	cin >> m >> n;

	for (int row = 0; row < m; ++row) {
		for (int col = 0; col < n; ++col) {
			cin >> arr[row][col];
		}
	}

	int row, col, dir;
	cin >> row >> col >> dir;
	start.row = row - 1;
	start.col = col - 1;
	if (dir == 1) start.dir = 1;
	if (dir == 2) start.dir = 3;
	if (dir == 3) start.dir = 2;
	if (dir == 4) start.dir = 0;
	cin >> row >> col >> dir;
	goal.row = row - 1;
	goal.col = col - 1;
	if (dir == 1) goal.dir = 1;
	if (dir == 2) goal.dir = 3;
	if (dir == 3) goal.dir = 2;
	if (dir == 4) goal.dir = 0;

	BFS();

	cout << ans << '\n';

	return 0;
}