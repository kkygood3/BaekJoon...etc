// 또시간 초과
//#include <iostream>
//#define MAX 110
//using namespace std;
//
//struct Robot {
//	int row;
//	int col;
//	int dir;
//};
//
//int m, n;
//bool arr[MAX][MAX];
//bool visit[MAX][MAX];
//int d_row[4] = { 0,0,1,-1 };
//int d_col[4] = { 1,-1,0,0 }; // 동 서 남 북  0,1 명령 2번, 2,3 명령 2번
//Robot start, goal;
//int ans = 9999;
//
//bool check(int row, int col) {
//
//	if (row >= n || col >= n || row < 0 || col < 0) return false;
//	if (arr[row][col]) return false;
//	if (visit[row][col]) return false;
//
//	return true;
//}
//
//void DFS(int row, int col, int dir, int dis ,int cur) {
//	
//	
//
//	if (cur >= ans) return;
//
//	if (row == goal.row && col == goal.col) {
//		for (int i = 0; i < m; ++i) {
//			for (int j = 0; j < n; ++j) {
//				cout << visit[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//		int temp;
//		if (dir == goal.dir) temp = cur;
//		else if ((dir == 0 && goal.dir == 1) || (dir == 1 && goal.dir == 0) || (dir == 2 && goal.dir == 3) || (dir == 3 && goal.dir == 2)) temp = cur + 2;
//		else temp = cur + 1;
//		if (temp < ans) ans = temp;
//		return;
//	}
//
//	for (int i = 0; i < 4; ++i) {
//		int next_row = row + d_row[i];
//		int next_col = col + d_col[i];
//		if (check(next_row, next_col)) {
//			visit[next_row][next_col] = true;
//			if (i == dir) {
//				if (dis == 3) DFS(next_row, next_col, i, 0, cur + 1);
//				else DFS(next_row, next_col, i, dis + 1, cur);
//			}
//			else if ((dir == 0 && i == 1) || (dir == 1 && i == 0) || (dir == 2 && i == 3) || (dir == 3 && i == 2)) {
//				DFS(next_row, next_col, i, 1, cur + 3);
//			}
//			else DFS(next_row, next_col, i, 1, cur + 2);
//			visit[next_row][next_col] = false;
//		}
//	}
//
//}
//
//int main() {
//
//	cin >> m >> n;
//
//	for (int row = 0; row < m; ++row) {
//		for (int col = 0; col < n; ++col) {
//			cin >> arr[row][col];
//		}
//	}
//
//	int row, col, dir;
//	cin >> row >> col >> dir;
//	start.row = row - 1;
//	start.col = col - 1;
//	start.dir = dir - 1;
//	cin >> row >> col >> dir;
//	goal.row = row - 1;
//	goal.col = col - 1;
//	goal.dir = dir - 1;
//
//	visit[start.row][start.col] = true;
//	DFS(start.row, start.col, start.dir, 0, 0);
//
//	cout << ans << '\n';
//
//	return 0;
//}