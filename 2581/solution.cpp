#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n, m, min = 10001, sum = 0;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> v;

	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		
		for (int j = 2; j <= i; j++) {
			if (j == i) {
				v.push_back(i);
				if (min > i) min = i;
			}
			if (i % j == 0) break;
		}
	}
	vector<int>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++) {
		sum += *iter;
	}

	if (sum == 0) cout << -1;
	else cout << sum << '\n' << min;

	return 0;
}