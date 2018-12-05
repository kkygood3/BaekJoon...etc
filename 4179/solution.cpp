//DFS + BFS 완전탐색 시간초과

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <utility>
//#include <cstring>
//#define MAX 1010
//using namespace std;
//
//queue<pair<int, int>> q;
//char J_map[MAX][MAX];
//char F_map[MAX][MAX];
//char origin_F_map[MAX][MAX];
//bool visit[MAX][MAX];
//int n, m;
//int J_row, J_col, F_row, F_col;
//int d_row[4] = { -1,1,0,0 };
//int d_col[4] = { 0,0,-1,1 };
//int min_cur = 99999;
//
//bool check_BFS(int row, int col) {
//	
//	if (row < 0 || col < 0 || row >= n || col >= m) return false;
//	if (F_map[row][col] == 'F' || F_map[row][col] == '#') return false;
//
//	return true;
//}
//
//void BFS(int cur) {
//
//	q.push(make_pair(F_row, F_col));
//
//	while (!q.empty() && cur > 0) {	// cur만큼 돈다
//		int sz = q.size();
//		for (int qs = 0; qs < sz; ++qs) {
//			int row = q.front().first;
//			int col = q.front().second;
//			q.pop();
//			for (int i = 0; i < 4; ++i) {
//				int next_row = row + d_row[i];
//				int next_col = col + d_col[i];
//				if (check_BFS(next_row, next_col)) {
//					F_map[next_row][next_col] = 'F';
//					q.push(make_pair(next_row, next_col));
//				}
//			}
//		}
//		cur--;
//	}
//}
//
//bool check(int row, int col, int cur) {
//
//	if (row < 0 || col < 0 || row >= n || col >= m) {
//		if (cur + 1 < min_cur) min_cur = cur + 1; // 다음이 탈출일 경우 현재 경로 + 1
//		return false;
//	}
//	if (J_map[row][col] == '#' || F_map[row][col] == 'F') return false;
//
//	return true;
//}
//
//void DFS(int cur, int row, int col) {
//
//	memcpy(F_map, origin_F_map, sizeof(origin_F_map)); // 초기화
//	while (!q.empty()) q.pop();
//	BFS(cur); // 불번짐
//	
//	if (cur >= min_cur) return; // 이동 경로가 최소경로보다 같거나 커질 경우
//	if (F_map[row][col] == 'F') return; // 이동했는데 불위치인 경우
//
//	for (int i = 0; i < 4; ++i) {
//		int next_row = row + d_row[i];
//		int next_col = col + d_col[i];
//		if (check(next_row, next_col, cur)) {
//			
//			J_map[row][col] = '.';
//			J_map[next_row][next_col] = 'J';
//			DFS(cur + 1, next_row, next_col);
//			J_map[row][col] = 'J';
//			J_map[next_row][next_col] = '.';
//		}
//	}
//
//}
//
//int main() {
//
//	cin.tie(0); ios::sync_with_stdio(0);
//
//	cin >> n >> m;
//
//	for (int row = 0; row < n; ++row) {
//		for (int col = 0; col < m; ++col) {
//			cin >> J_map[row][col];
//			F_map[row][col] = J_map[row][col];
//			origin_F_map[row][col] = F_map[row][col];
//			if (J_map[row][col] == 'J') {
//				J_row = row;
//				J_col = col;
//			}
//			if (F_map[row][col] == 'F') {
//				F_row = row;
//				F_col = col;
//			}
//		}
//	}
//
//	DFS(0, J_row, J_col);
//	
//	if (min_cur == 99999) cout << "IMPOSSIBLE";
//	else cout << min_cur << '\n';
//
//	return 0;
//}