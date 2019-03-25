#include <iostream>
#include <algorithm>
using namespace std;

int arr[510][510];
int dp[510][510];
int n;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
int ans = 1;

int DFS(int row, int col) {

	if (dp[row][col] != -1) return dp[row][col];	// 이미 값이 있으면 리턴

	dp[row][col] = 1;	// 아니면 초기화

	for (int i = 0; i < 4; ++i) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		if (next_row >= 0 && next_col >= 0 && next_col < n && next_row < n && arr[row][col] < arr[next_row][next_col]) {
			int temp = 1;	// 기본 1
			temp += DFS(next_row, next_col); // dfs를 들어가서 살았던 수만큼 리턴 받아 추가해줌 -> 해당 지역의 최대 살 수 있는 값
			dp[row][col] = max(dp[row][col], temp);	// 들어갔다 나온 값과 다른 곳으로 갔다 온 값을 비교해줌
			if (ans < dp[row][col]) ans = dp[row][col];
		}
	}

	return dp[row][col];	// 값 리턴
}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dp[i][j] == -1) DFS(i, j);
		}
	}

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}*/

	cout << ans << '\n';

	return 0;
}