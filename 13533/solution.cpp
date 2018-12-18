#include <iostream>
#include <vector>
#include <utility>
typedef unsigned long long ull;
#define MOD 1000000007
using namespace std;

vector<pair<ull,ull>> v;
int n;
ull s;
ull ans = 0;

void DFS(int cur, int sum) {

	if (sum == s && cur == n) {
		ans++;
		return;
	}
	if (cur == n) return;

	int sz = v[cur].first;

	for (int i = 0; i <= sz; ++i) {
		if(s - sum - i <= v[cur].second) DFS(cur + 1, sum + i);
		else continue;
	}

}

int main() {

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		ull u;
		cin >> u;
		v.push_back(make_pair(u, 0));
	}

	for (int i = 0; i < n; ++i) {
		ull sum = 0;
		for (int j = i + 1; j < n; ++j) {
			sum += v[j].first;
		}
		v[i].second = sum;
	}

	DFS(0, 0);
	ans %= MOD;

	cout << ans << '\n';

	return 0;
}