#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
string str[52];
int n, k;
bool alpha[200];
int ans = 0;

void DFS(int cur, int alp) {
	if (k - cur < 0) return;
	if (cur == k) {
		int max_ = 0;
		for (int i = 0; i < n; ++i) {
			int v_sz = str[i].size();
			bool sw = true;
			for (int j = 0; j < v_sz; ++j) {
				if (!alpha[str[i][j]]) sw = false;
			}
			if (sw) {
				max_++;
			}
			ans = max(ans, max_);
		}
		return;
	}
	for (int i = alp; i <= 'z'; ++i) {
		if (!alpha[i]) {
			if (k - cur > 'z' - i + 1) continue;
			alpha[i] = true;
			DFS(cur + 1, i + 1);
			alpha[i] = false;
		}
	}
}
int main() {
	cin >> n >> k;
	k -= 5;
	alpha['a'] = true;
	alpha['n'] = true;
	alpha['t'] = true;
	alpha['i'] = true;
	alpha['c'] = true;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		str[i].erase(str[i].begin(), str[i].begin() + 4);
		str[i].pop_back();
		str[i].pop_back();
		str[i].pop_back();
		str[i].pop_back();
	}
	DFS(0, 'a');
	cout << ans << '\n';
	return 0;
}