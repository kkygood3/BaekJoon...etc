#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAX 4010
using namespace std;

typedef struct Atom {

	int row;
	int col;
	int way;
	int pow;

}ATOM;

int t, n, x, y, u, k;
int d_row[4] = { 1,-1,0,0 };
int d_col[4] = { 0,0,-1,1 }; // ╩С го аб ©Л
ATOM arr[1000];
int visit[MAX][MAX];
queue<int> q;
int energy = 0;
vector <int> ans;
int cnt = 0;

bool check(int row, int col) {

	if (row < 0 || col < 0 || row > 4001 || col > 4001) return false;

	return true;
}

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visit[i][j] = false;
		}
	}
}
int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n;
		energy = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> u >> k;
			ATOM a;
			x += 1000;
			x *= 2;
			y += 1000;
			y *= 2;
			arr[i].row = y;
			arr[i].col = x;
			arr[i].way = u;
			arr[i].pow = k;
			visit[y][x]++;
		}
		int cc = 0;
		while (cc <= 4001) {
			cc++;
			//cout << cc << " , "<< energy << " , " << no_one << '\n';
			for (int i = 0; i < n; i++) {
				if (arr[i].pow == 0) continue;

				visit[arr[i].row][arr[i].col]--;
				if (!check(arr[i].row + d_row[arr[i].way], arr[i].col + d_col[arr[i].way])) {
					arr[i].pow = 0;
				}
				else {
					arr[i].row = arr[i].row + d_row[arr[i].way];
					arr[i].col = arr[i].col + d_col[arr[i].way];

					visit[arr[i].row][arr[i].col]++;
				}
				
			}

			for (int i = 0; i < n; i++) {
				if (visit[arr[i].row][arr[i].col] >= 2) {
					energy += arr[i].pow;
					arr[i].pow = 0;
				}
			}

			for (int i = 0; i < n; i++) {
				if (visit[arr[i].row][arr[i].col] >= 2) {
					visit[arr[i].row][arr[i].col] = 0;
				}
			}
		}

		ans.push_back(energy);
	}
	

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << ' ' << ans[i] << '\n';
	}
	return 0;
}