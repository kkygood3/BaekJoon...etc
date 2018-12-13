#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 1010
using namespace std;

queue<pair<int, int>> q_fire;
queue<pair<int, int>> q_sang;
vector<string> ans;
char arr[MAX][MAX];
bool fire[MAX][MAX];
int w, h;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };

void init() {
	
	for (int row = 0; row < h; ++row) {
		for (int col = 0; col < w; ++col) {
			arr[row][col] = '.';
			fire[row][col] = false;
		}
	}

	while (!q_sang.empty())q_sang.pop();
	while (!q_fire.empty())q_fire.pop();

}

bool check_fire(int row, int col) {
	
	if (row < 0 || col < 0 || row >= h || col >= w || arr[row][col] == '#' || fire[row][col]) return false;
	return true;
}

bool check_sang(int row, int col) {
	
	if (arr[row][col] == '#' || fire[row][col] || arr[row][col] == '@' || arr[row][col] == '*') return false;
	return true;
}

void BFS() {

	int time = 0;

	while (!q_sang.empty()) {

		int sz = q_fire.size();
		for (int qs = 0; qs < sz; ++qs) {
			int row = q_fire.front().first;
			int col = q_fire.front().second;
			q_fire.pop();
			for (int i = 0; i < 4; ++i) {
				int next_row = row + d_row[i];
				int next_col = col + d_col[i];
				if (check_fire(next_row, next_col)) {
					fire[next_row][next_col] = true;
					arr[row][col] = '*';
					q_fire.push(make_pair(next_row, next_col));
				}
			}
		}

		sz = q_sang.size();
		for (int qs = 0; qs < sz; ++qs) {
			int row = q_sang.front().first;
			int col = q_sang.front().second;
			q_sang.pop();
			for (int i = 0; i < 4; ++i) {
				int next_row = row + d_row[i];
				int next_col = col + d_col[i];
				if (next_row < 0 || next_col < 0 || next_row >= h || next_col >= w) {
					time++;
					string s = "";
					while (time != 0) {
						int temp = time % 10;
						s.push_back(temp + '0');
						time /= 10;
					}
					reverse(s.begin(), s.end());
					ans.push_back(s);
					return;
				}
				if (check_sang(next_row, next_col)) {
					arr[next_row][next_col] = '@';
					q_sang.push(make_pair(next_row, next_col));
				}
			}
		}
		time++;
	}
	ans.push_back("IMPOSSIBLE");
}

int main() {

	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {

		cin >> w >> h;
		for (int row = 0; row < h; ++row) {
			for (int col = 0; col < w; ++col) {
				cin >> arr[row][col];
				if (arr[row][col] == '@') {
					q_sang.push(make_pair(row, col));
				}
				if (arr[row][col] == '*') {
					fire[row][col] == true;
					q_fire.push(make_pair(row, col));
				}
			}
		}

		BFS();
		/*for (int row = 0; row < h; ++row) {
			for (int col = 0; col < w; ++col) {
				cout << arr[row][col];
			}
			cout << '\n';
		}*/
		init();

	}

	int sz = ans.size();
	for (int i = 0; i < sz; ++i) cout << ans[i] << '\n';

	return 0;
}