#include <iostream>
#include <vector>
using namespace std;

int t, n;
int ans;
vector<int> v;

void DFS(int sum) {

	if (sum == n) {
		ans++;
		return;
	}
	if (sum > n) return;

	for (int i = 1; i <= 3; ++i) {
		DFS(sum + i);
	}
}

int main() {

	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		ans = 0;

		cin >> n;

		DFS(0);

		v.push_back(ans);
	}
	
	for (int i = 0; i < v.size(); ++i) cout << v[i] << '\n';

	return 0;
}