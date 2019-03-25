#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int d[52][52];
int min_d[14][101];
int house[101][2];
int chiken[14][2];
vector<int> v;

int main() {

	int n, m;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int cnt_h = 0;
	int cnt_c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
			if (d[i][j] == 1) {
				cnt_h++;
				house[cnt_h][0] = i;
				house[cnt_h][1] = j;
			}
			if (d[i][j] == 2) {
				cnt_c++;
				chiken[cnt_c][0] = i;
				chiken[cnt_c][1] = j;
			}
		}
	}
	for (int i = 1; i <= cnt_c; i++) {
		for (int j = 1; j <= cnt_h; j++) {
			for (int k = 0; k < 2; k++) {
				min_d[i][j] += abs(chiken[i][k] - house[j][k]);
			}
		}
	}
	for (int i = 1; i <= cnt_c; i++) {
		for (int j = 1; j <= cnt_h; j++) {
			cout << i << "번째 치킨집에서" << j << "번째 집 거리 : " << min_d[i][j] << '\n';
		}
	}

	return 0;
}