#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 25
using namespace std;

int ans[MAX * MAX];
queue<pair<int, int>> q;
bool visit[MAX][MAX];
int arr[MAX][MAX];
int house[MAX][MAX];
int n;
int d_row[4] = { 1,0,-1,0 };
int d_col[4] = { 0,1,0,-1 };
int cnt;


bool check(int row, int col) {
	
	if (row < 0 || col < 0 || row >= n || col >= n) return true;
	else if(visit[row][col]) return true;
	else return false;
}

void BFS(int row, int col,int num) {
	cnt = 1;
	while (!q.empty()) q.pop();
	q.push(make_pair(row, col));
	visit[row][col] = true;
	house[row][col] = num;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		
		bool sw = false;
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (!check(next_row, next_col)) sw = true;
		}
		if (!sw) continue;
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (!check(next_row, next_col)) {
				q.push(make_pair(next_row, next_col));
				visit[next_row][next_col] = true;
				house[next_row][next_col] = num;
				cnt++;
			}
		}
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		int tmp;
		cin >> s;
		for (int j = n - 1; j >= 0; j--) {
			tmp = s.back() - '0';
			s.pop_back();
			arr[i][j] = tmp;
			if (tmp == 0) visit[i][j] = true;
		}
	}

	memcpy(house, arr, sizeof(arr));

	int houseNum = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0 && !visit[i][j]) {
				BFS(i, j, houseNum);
				ans[houseNum] = cnt;
				houseNum++;
			}
		}
	}
	
	sort(&ans[1], &ans[houseNum]);

	cout << houseNum - 1 << '\n';
	for (int i = 1; i < houseNum; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}