#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 50
using namespace std;

queue<pair<int, int>> q;
int t, n, m, r, c, l;
int arr[MAX][MAX];
bool visit[MAX][MAX];
bool clean[MAX][MAX];
int d_row[4] = { -1,0,1,0 };
int d_col[4] = { 0,-1,0,1 }; // 북 서 남 동
int sum;
vector<int> ans;

bool check_right(int row, int col, int i)
{
	if (i == 3)
	{
		if ((arr[row][col] == 1 || arr[row][col] == 3 || 4 || 5) && (arr[row][col + 1] == 1 || 3 || 6 || 7)) return true;
		else return false;
	}
}

bool check(int row, int col, int cur_state, int i) {

	int next_state = arr[row][col];
	if (row < 0 || col < 0 || row >= n || col >= m) return false;
	if (visit[row][col]) return false;
	if (next_state == 0) return false;

	if (cur_state == 1 && i == 0) {
		if (next_state == 1 || next_state == 2 || next_state == 5 || next_state == 6) return true; // 위로 진입
		else return false;
	}
	else if (cur_state == 1 && i == 1) {
		if (next_state == 1 || next_state == 3 || next_state == 4 || next_state == 5) return true; // 왼쪽으로 진입
		else return false;
	}
	else if (cur_state == 1 && i == 2) {
		if (next_state == 1 || next_state == 2 || next_state == 4 || next_state == 7) return true; // 아래로 진입
		else return false;
	}
	else if (cur_state == 1 && i == 3) {
		if (next_state == 1 || next_state == 3 || next_state == 6 || next_state == 7) return true; // 오른쪽으로 진입
		else return false;
	}
	else if (cur_state == 2 && i == 0) {
		if (next_state == 1 || next_state == 2 || next_state == 5 || next_state == 6) return true;
		else return false;
	}
	else if (cur_state == 2 && i == 2) {
		if (next_state == 1 || next_state == 2 || next_state == 4 || next_state == 7) return true;
		else return false;
	}
	else if (cur_state == 3 && i == 1) {
		if (next_state == 1 || next_state == 3 || next_state == 4 || next_state == 5) return true;
		else return false;
	}
	else if (cur_state == 3 && i == 3) {
		if (next_state == 1 || next_state == 3 || next_state == 6 || next_state == 7) return true;
		else return false;
	}
	else if (cur_state == 4 && i == 0) {
		if (next_state == 1 || next_state == 2 || next_state == 5 || next_state == 6) return true;
		else return false;
	}
	else if (cur_state == 4 && i == 3) {
		if (next_state == 1 || next_state == 3 || next_state == 6 || next_state == 7) return true;
		else return false;
	}
	else if (cur_state == 5 && i == 2) {
		if (next_state == 1 || next_state == 2 || next_state == 4 || next_state == 7) return true;
		else return false;
	}
	else if (cur_state == 5 && i == 3) {
		if (next_state == 1 || next_state == 3 || next_state == 6 || next_state == 7) return true;
		else return false;
	}
	else if (cur_state == 6 && i == 1) {
		if (next_state == 1 || next_state == 3 || next_state == 4 || next_state == 5) return true;
		else return false;
	}
	else if (cur_state == 6 && i == 2) {
		if (next_state == 1 || next_state == 2 || next_state == 4 || next_state == 7) return true;
		else return false;
	}
	else if (cur_state == 7 && i == 0) {
		if (next_state == 1 || next_state == 2 || next_state == 5 || next_state == 6) return true;
		else return false;
	}
	else if (cur_state == 7 && i == 1) {
		if (next_state == 1 || next_state == 3 || next_state == 4 || next_state == 5) return true;
		else return false;
	}
	else return false;

	return true;
}

void BFS(int r, int c, int l) {

	int cur_row = r;
	int cur_col = c;
	int cur_state = arr[cur_row][cur_col];
	visit[cur_row][cur_col] = true;
	q.push(make_pair(cur_row, cur_col));
	int cnt = 1;
	sum = 1;
	while (!q.empty()) {
		int qs = q.size();
		if (cnt == l) {
			ans.push_back(sum);
			
			return;
		}
		for (int sz = 0; sz < qs; sz++) {
			cur_row = q.front().first;
			cur_col = q.front().second;
			cur_state = arr[cur_row][cur_col];
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];
				int next_state = arr[next_row][next_col];
				if (check(next_row, next_col, cur_state, i)) {
					visit[next_row][next_col] = true;
					sum++;
					q.push(make_pair(next_row, next_col));
				}
			}
		}
		cnt++;
	}
	ans.push_back(sum);
}

void init(int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			visit[i][j] = false;
		}
	}
	while (!q.empty()) q.pop();
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n >> m >> r >> c >> l;
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				cin >> arr[row][col];
			}
		}

		BFS(r, c, l);

		init(n,m);

	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << " " << ans[i] << '\n';
	}

}