#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int n, m;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> v;

	cin >> n >> m;

	for (int i = n; i <= m; i++) {

		int max = sqrt(i);
		for (int j = 2; j <= max + 1; j++) {
			if (i == 1) { 
				break;
			}
			if (j == max + 1) {
				v.push_back(i);
			}
			if (i % j == 0) break;
		}
	}
	vector<int>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}