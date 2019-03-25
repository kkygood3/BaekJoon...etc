#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int t, n;
	bool prime[10000] = { false, };
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> v[2];
	cin >> t;
	vector<int>::iterator iter;

	for (int i = 1; i <= 10000; i++) {

		int max = sqrt(i);
		for (int j = 2; j <= max + 1; j++) {
			if (i == 1) {
				break;
			}
			if (j == max + 1) {
				prime[i] = true;
			}
			if (i % j == 0) break;
		}
	}
	prime[1] = false;
	prime[2] = true;
	prime[3] = true;

	for(int i = 0 ; i < t ; i++){
		cin >> n;
		int s = n / 2;
		for (int j = s; j >= 2; j--) {
			if (prime[j] && prime[n - j]) {
				v[0].push_back(j);
				v[1].push_back(n - j);
				break;
			}
		}
	}

	for (int i = 0; i < v[0].size(); i++) {
		cout << v[0][i] << ' ' << v[1][i] << '\n';
	}

	return 0;
}