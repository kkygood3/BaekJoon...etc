// DFS 시간 초과
//#include <iostream>
//using namespace std;
//
//int arr[110][110];
//bool visit[110][110];
//int n;
//int ans = 0;
//int d_row[2] = { 1,0 };
//int d_col[2] = { 0,1 };
//
//bool check(int row, int col) {
//
//	if (row < 0 || col < 0 || row >= n || col >= n) return false;
//	if (visit[row][col]) return false;
//	return true;
//}
//
//void DFS(int row, int col) {
//
//	if (row == n - 1 && col == n - 1) {
//		ans++;
//		return;
//	}
//
//	for (int i = 0; i < 2; ++i) {
//		int next_row = row + (arr[row][col] * d_row[i]);
//		int next_col = col + (arr[row][col] * d_col[i]);
//		if (check(next_row, next_col)) {
//			visit[next_row][next_col] = true;
//			DFS(next_row, next_col);
//			visit[next_row][next_col] = false;
//		}
//	}
//
//}
//
//int main() {
//
//	cin >> n;
//
//	for (int row = 0; row < n; ++row) {
//		for (int col = 0; col < n; ++col) {
//			cin >> arr[row][col];
//		}
//	}
//
//	visit[0][0] = true;
//	DFS(0, 0);
//
//	cout << ans << '\n';
//
//	return 0;
//}