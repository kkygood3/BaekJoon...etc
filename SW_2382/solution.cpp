#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 100
using namespace std;

pair<int,int> visit[MAX][MAX];		  // first : 미생물 수 , second : 제일 컸던 미생물 수
queue<pair<int, int>> q;	  // row, col
pair<int,int> arr[100][100];  // first : 미생물 수 , second : 방향
pair<int, int> temp[100][100];  // first : 미생물 수 , second : 방향
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 }; // 북 남 서 동
int t, n, m, k;
vector<int> ans;

void check(int row, int col, int num, int i) {

	if (row == 0 || col == 0 || row == n - 1 || col == n - 1) {
		temp[row][col].first = num / 2;
		if (i == 0) temp[row][col].second = 1;
		if (i == 1) temp[row][col].second = 0;
		if (i == 2) temp[row][col].second = 3;
		if (i == 3) temp[row][col].second = 2;
		q.push(make_pair(row, col));
	}

	else if (!visit[row][col].first) {
		visit[row][col].first = num;
		visit[row][col].second = num;
		temp[row][col].first = num;
		temp[row][col].second = i;
		q.push(make_pair(row, col));
	}
	else if (visit[row][col].first) {
		if (visit[row][col].second < num) {
			visit[row][col].first += num;
			visit[row][col].second = num;
			temp[row][col].first = visit[row][col].first;
			temp[row][col].second = i;
		}
		else {
			visit[row][col].first += num;
			temp[row][col].first = visit[row][col].first;
		}
	}


}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = temp[i][j];
			temp[i][j].first = 0;
			temp[i][j].second = 0;
			visit[i][j].first = 0;
			visit[i][j].second = 0;
		}
	}
}

void BFS() {

	int cnt = 1;
	int sum = 0;
	while (!q.empty()) {
		int sz = q.size();
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << arr[i][j].first << '\t';
		//	}
		//	cout << '\n';
		//}
		bool sw = false;
		for (int qs = 0; qs < sz; qs++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			int cur_num = arr[cur_row][cur_col].first;
			int cur_i = arr[cur_row][cur_col].second;
			q.pop();

			int next_row = cur_row + d_row[cur_i];
			int next_col = cur_col + d_col[cur_i];

			check(next_row, next_col, cur_num, cur_i);

		}
		init();
		if (cnt == m) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					sum += arr[i][j].first;
				}
			}
			ans.push_back(sum);
			return;
		}
		cnt++;
	}
}

int main() {
	
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n >> m >> k;

		for (int i = 0; i < k; i++) {
			int row, col;
			cin >> row >> col;
			cin >> arr[row][col].first >> arr[row][col].second;
			arr[row][col].second -= 1;
			q.push(make_pair(row, col));
		}

		BFS();
		while (!q.empty()) q.pop();
	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << ' ' << ans[i] << '\n';
	}

	return 0;
}