#include <iostream>
#include <vector>
#include <utility>
#define MAX 101
using namespace std;

int n, m;
pair<int, int> start;
pair<int, int> des;
int start_d;
int des_d;
bool maze[101][101];
bool visit[101][101];
int d_row[4] = { 0, 0, 1, -1 };
int d_col[4] = { 1, -1, 0, 0 };  // µ¿ ¼­ ³² ºÏ
int com_min = 999999;

bool check(int row, int col) {

	if (maze[row][col]) return false;
	if (row <= 0 || col <= 0 || row > n || col > m) return false;
	if (visit[row][col]) return false;
	return true;
}

int com_check(int d1, int d2) {

	if (d1 == d2) return 0;
	if (d1 == 0 && d2 == 1) return 2;
	if (d1 == 1 && d2 == 0) return 2;
	if (d1 == 0 && d2 == 2) return 1;
	if (d1 == 2 && d2 == 0) return 1;
	if (d1 == 0 && d2 == 3) return 1;
	if (d1 == 3 && d2 == 0) return 1;
	if (d1 == 1 && d2 == 2) return 1;
	if (d1 == 2 && d2 == 1) return 1;
	if (d1 == 1 && d2 == 3) return 1;
	if (d1 == 3 && d2 == 1) return 1;
	if (d1 == 2 && d2 == 3) return 2;
	if (d1 == 3 && d2 == 2) return 2;
}

void DFS(int row, int col, int d, int com) {

	if (com_min < com) return;

	/*cout << com << '\n';
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= m; col++) {
			cout << visit[row][col] << ' ';
		}
		cout << '\n';
	}*/
	if (row == des.first && col == des.second) {
		com += com_check(d, des_d - 1);
		if (com < com_min) com_min = com;
		/*cout << "µµÂø " << com << '\n';*/
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		if (check(next_row,next_col)) {
			visit[next_row][next_col] = true;
			com += com_check(d,i);
			if (d != i) com++;
			else if (d == i && row == start.first && col == start.second) com++;
			DFS(next_row, next_col, i, com);
			visit[next_row][next_col] = false;
			com -= com_check(d, i);
			if (d != i) com--;
			else if (d == i && row == start.first && col == start.second) com--;
			
		}
	}

}

int main() {
	
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= m; col++) {
			cin >> maze[row][col];
		}
	}
	cin >> start.first >> start.second >> start_d;
	cin >> des.first >> des.second >> des_d;

	/*for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= m; col++) {
			cout << maze[row][col] << ' ';
		}
		cout << '\n';
	}*/

	visit[start.first][start.second] = true;
	DFS(start.first, start.second, start_d - 1, 0);

	cout << com_min << '\n';

	return 0;
}