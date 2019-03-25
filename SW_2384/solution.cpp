#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX 10
using namespace std;

int arr[MAX][MAX];
int t, n;
vector<pair<int, int>> stair;
queue<pair<int, int>> q;
vector<int> dis[2];
bool visit[MAX][MAX];
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
bool D[MAX];
int saram;
vector<int> first_stair;
vector<int> second_stair;
queue<int> wait[2];
queue<int> go_down[2];
vector<int> ans;
int min_time;

bool check(int row, int col, int cnt) {

	if (row < 0 || col < 0 || row >= n || col >= n) return false;
	if (visit[row][col]) return false;
	
	return true;

}

void BFS(int row, int col) {

	visit[row][col] = true;
	q.push(make_pair(row, col));
	
	int cnt = 1;
	while (!q.empty()) {
		int sz = q.size();
		for (int qs = 0; qs < sz; qs++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];

				if (check(next_row, next_col, cnt)) {

					visit[next_row][next_col] = true;

					if (next_row == stair[0].first && next_col == stair[0].second) {
						dis[0].push_back(cnt);
					}
					else if (next_row == stair[1].first && next_col == stair[1].second) {
						dis[1].push_back(cnt);
					}

					q.push(make_pair(next_row,next_col));
				}
			}


		}
		cnt++;
	}

}

void init() {

	while (!q.empty())q.pop();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}

}

void time_check() {
	int time = -1;
	int cnt = 0;
	while (1) {
		time++;
		if (time > min_time) return;
		/*cout << time << '\n';
		for (int i = 0; i < first_stair.size(); i++) {
			cout << first_stair[i] << ' ';
		}
		cout << '\n';
		
		if (!go_down[0].empty()) cout << "내려가는중 "<< go_down[0].front() << '\n';
		if (!wait[0].empty()) cout << "기다리는중 " << wait[0].front() << '\n';

		cout << '\n';
		for (int i = 0; i < second_stair.size(); i++) {
			cout << second_stair[i] << ' ';
		}
		cout << '\n';

		if (!go_down[1].empty()) cout << "내려가는중 " << go_down[1].front() << '\n';
		if (!wait[1].empty()) cout << "기다리는중 " << wait[1].front() << '\n';*/

		while (!go_down[0].empty() && go_down[0].front() <= time) {
			go_down[0].pop();
			cnt++;
			
			if (!wait[0].empty() && go_down[0].size() < 3 ) {
				go_down[0].push(time + arr[stair[0].first][stair[0].second] + 1);
				wait[0].pop();
			}

			if (cnt == saram) {
				if (min_time > time) min_time = time;
				return;
			}
		}

		

		while (!go_down[1].empty() && go_down[1].front() <= time ) {
			go_down[1].pop();
			cnt++;
			
			if (!wait[1].empty() && go_down[1].size() < 3 ) {
				go_down[1].push(time + arr[stair[1].first][stair[1].second] + 1);
				wait[1].pop();
			}

			if (cnt == saram) {
				if (min_time > time) min_time = time;
				return;
			}
		}

		for (int i = 0; i < first_stair.size(); i++) {
			first_stair[i] -= 1;

			if (first_stair[i] == 0) {
				if (go_down[0].size() < 3) go_down[0].push(time + arr[stair[0].first][stair[0].second] + 2);
				else wait[0].push(arr[stair[0].first][stair[0].second]);
			}
		}

		for (int i = 0; i < second_stair.size(); i++) {
			second_stair[i] -= 1;

			if (second_stair[i] == 0) {
				if (go_down[1].size() < 3) go_down[1].push(time + arr[stair[1].first][stair[1].second] + 2);
				else wait[1].push(arr[stair[1].first][stair[1].second]);
			}
		}

		

	}

}

void DFS(int index, int cur) {

	if (cur == 0) {
		first_stair.clear();
		second_stair.clear();

		for (int i = 0; i < saram; i++) {
			if (D[i] == 0) first_stair.push_back(dis[0][i]);
			if (D[i] == 1) second_stair.push_back(dis[1][i]);
		}

		time_check();
		while (!go_down[0].empty()) go_down[0].pop();
		while (!go_down[1].empty()) go_down[1].pop();
		while (!wait[0].empty()) wait[0].pop();
		while (!wait[1].empty()) wait[1].pop();

		return;
	}

	if (index == saram) return;

	D[index] = true;
	DFS(index + 1, cur - 1);
	D[index] = false;
	DFS(index + 1, cur);

}

int main() {
	
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n;
		saram = 0;
		min_time = 99999;
		stair.clear();
		dis[0].clear();
		dis[1].clear();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] >= 2) {
					stair.push_back(make_pair(i, j));
				}
				else if (arr[i][j] == 1) saram++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) {
					BFS(i, j);

					init();
				}
			}
		}


		for (int i = 0; i <= saram; i++) {
			DFS(0, i);
		}

		ans.push_back(min_time);

	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << " " << ans[i] << '\n';
	}

	return 0;
}