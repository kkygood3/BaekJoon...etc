#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 20
using namespace std;

queue<pair<int, int>> q;
bool arr[MAX][MAX];
bool visit[MAX][MAX];
int t, n, m;
int d_row[4] = { -1,0,1,0 };
int d_col[4] = { 0,-1,0,1 };
vector<int> ans;
int max_value;
int max_ans;

void init() {

	while (!q.empty()) q.pop();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}

bool check(int row, int col) {

	if (row < 0 || col < 0 || row >= n || col >= n) return false;
	if (visit[row][col]) return false;

	return true;
}

void BFS(int row, int col) {
	visit[row][col] = true;
	q.push(make_pair(row, col));
	int cur_row = row;
	int cur_col = col;
	int cnt = 1;
	int sum;
	int val;
	if (arr[row][col] == true) {
		 sum = m;
	}
	else sum = 0;

	while (!q.empty()) {
		int qs = q.size();
		
		val = (cnt * cnt) + ((cnt - 1) * (cnt - 1));
		val = sum - val;
		if (val >= 0 && max_ans <= sum / m) {
			max_ans = sum / m;
		}
		//cout << cnt << " : val" << val << " sum : " << sum << "현재 위치 :" << row << ", " << col << "그래서 답은 : " << max_ans<< '\n';
		for (int sz = 0; sz < qs; sz++) {
			cur_row = q.front().first;
			cur_col = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];

				if (check(next_row,next_col)) {
					sum += m * arr[next_row][next_col];
					visit[next_row][next_col] = true;
					q.push(make_pair(next_row, next_col));
				}
			}
		}
		cnt++;
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n >> m;
		max_value = 0;
		max_ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				BFS(i, j);
				init();
			}
		}

		ans.push_back(max_ans);
	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << " " << ans[i] << '\n';
	}
	return 0;
}