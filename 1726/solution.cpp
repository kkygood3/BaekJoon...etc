// 시간초과
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
//bool check(int row, int col, int dir, int dis) {
//
//	if (row >= n || col >= n || row < 0 || col < 0) return false;
//	if (arr[row][col]) return false;
//	if (visit[row][col]) return false;
//	if (dis == 2) {
//		int back_row = row - d_row[dir];
//		int back_col = col - d_col[dir];
//		if (arr[back_row][back_col] || visit[back_row][back_col]) return false;
//	}
//	if (dis == 3) {
//		for (int i = 1; i <= 2; ++i) {
//			int back_row = row - (i * d_row[dir]);
//			int back_col = col - (i * d_col[dir]);
//			if (arr[back_row][back_col] || visit[back_row][back_col]) return false;
//		}
//	}
//
//	return true;
//}
//
//void DFS(int row, int col, int dir, int cur) {
//
//	if (cur >= ans) return;
//
//	if (row == goal.row && col == goal.col) {
//
//		int temp;
//		if (dir == goal.dir) temp = cur;
//		else temp = cur + 1;
//		if (temp < ans) ans = temp;
//		return;
//	}
//
//	
//
//	for (int i = 0; i < 4; ++i) {		// 방향
//		for (int dis = 0; dis <= 3; ++dis) {		// 거리
//			int next_row = row + (dis * d_row[i]);
//			int next_col = col + (dis * d_col[i]);
//			int next_dir = i;
//			if (next_row == row && next_col == col && next_dir == i) continue;
//			if (check(next_row, next_col, next_dir, dis)) {
//				visit[next_row][next_col] = true;
//				if (dir == next_dir) {	// 방향 그대로
//					if (dis == 0) {
//						DFS(next_row, next_col, dir, cur);	// 거리 0
//					}
//					else {
//						DFS(next_row, next_col, dir, cur + 1);	// 거리 이동
//					}
//				}
//				else if ((dir == 0 && next_dir == 1) || (dir == 1 && next_dir == 0) || (dir == 2 && next_dir == 3) || (dir == 3 && next_dir == 2)) {
//					if (dis == 0) {
//						DFS(next_row, next_col, dir, cur + 2);	// 거리 0
//					}
//					else {
//						DFS(next_row, next_col, dir, cur + 3);	// 거리 이동
//					}
//				}
//				else {	// 방향 바꿈
//					if (dis == 0) {
//						DFS(next_row, next_col, dir, cur + 1);
//					}
//					else {
//						DFS(next_row, next_col, dir, cur + 2);
//					}
//				}
//				visit[next_row][next_col] = false;
//			}
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
//	DFS(start.row, start.col, start.dir, 0);
//
//	cout << ans << '\n';
//
//	return 0;
//}