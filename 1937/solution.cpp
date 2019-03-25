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

	if (dp[row][col] != -1) return dp[row][col];	// �̹� ���� ������ ����

	dp[row][col] = 1;	// �ƴϸ� �ʱ�ȭ

	for (int i = 0; i < 4; ++i) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		if (next_row >= 0 && next_col >= 0 && next_col < n && next_row < n && arr[row][col] < arr[next_row][next_col]) {
			int temp = 1;	// �⺻ 1
			temp += DFS(next_row, next_col); // dfs�� ���� ��Ҵ� ����ŭ ���� �޾� �߰����� -> �ش� ������ �ִ� �� �� �ִ� ��
			dp[row][col] = max(dp[row][col], temp);	// ���� ���� ���� �ٸ� ������ ���� �� ���� ������
			if (ans < dp[row][col]) ans = dp[row][col];
		}
	}

	return dp[row][col];	// �� ����
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