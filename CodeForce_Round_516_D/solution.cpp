#include <iostream>
#include <string>
#include <queue>
#include <utility>
#define MAX 2001
using namespace std;

int n, m, r, c, x, y;
char maze[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> EXP[MAX][MAX];
string s;
queue<pair<int, int>> q;
int d_row[4] = { -1,0,1,0 };
int d_col[4] = { 0,-1,0,1 }; // idx 1 : Left id 3 : Right

bool check(int row, int col) {
	
	if (row <= 0 || col <= 0 || row > n || col > m) return false;
	if (visit[row][col]) return false;
	if (maze[row][col] == '*') return false;
	return true;
}

void DFS(int row, int col, int x_c, int y_c) {

	if (x_c < 0 || y_c < 0) return;
	else {
		maze[row][col] = '+';
		if(EXP[row][col].first == 0 && EXP[row][col].second == 0) EXP[row][col] = make_pair(x - x_c, y - y_c);
		else if(x - x_c <= EXP[row][col].first && y - y_c <= EXP[row][col].second) EXP[row][col] = make_pair(x - x_c, y - y_c);
		else if (x - x_c >= EXP[row][col].first && y - y_c >= EXP[row][col].second) return;
	}
	
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];

		if (check(next_row, next_col)) {
			visit[next_row][next_col] = true;
			if (i == 1) DFS(next_row, next_col, x_c - 1, y_c);
			else if (i == 3) DFS(next_row, next_col, x_c, y_c - 1);
			else DFS(next_row, next_col, x_c, y_c);
			visit[next_row][next_col] = false;
		}
	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m >> r >> c >> x >> y;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			maze[i][j + 1] = s[j];
		}
	}


	visit[r][c] = true;
	DFS(r, c, x, y);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(maze[i][j] == '+') cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}