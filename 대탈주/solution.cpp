#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int car[51];
int tmp[51];
int arr[1010];
int sw;
vector<int> ans;

void DFS(int cur, int i) {

	if (tmp[arr[i]] >= 1) tmp[arr[i]]--;
	else return;

	if (cur == 1) {
		sw = true;
		return;
	}

	DFS(cur - 1, i + 1);
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	
	for (int tc = 0; tc < t; ++tc) {
		cin >> n >> m;

		int max_car = 0;
		for (int i = 1; i <= m; ++i) {
			cin >> car[i];
			max_car += car[i];
		}
		
		for (int i = 1; i <= n; ++i) cin >> arr[i];

		sw = false;			// 가능한지 판단
		for (int i = 1; i <= n - max_car + 1; ++i) {
			memcpy(tmp, car, sizeof(car));

			DFS(max_car, i);

			if (sw) {
				ans.push_back(i);
				break;
			}
		}
		if (!sw) ans.push_back(0);

	}

	for (int tc = 0; tc < t; ++tc) cout << "#" << tc + 1 << " " << ans[tc] << '\n';

	return 0;
}