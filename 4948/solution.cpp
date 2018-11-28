#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> v, count;
	while (1) {
		cin >> n;
		if (n == 0) break;
		v.push_back(n);
	}

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		int sum = 0;
		for (int i = *iter + 1; i <= 2 * *iter; i++) {

			int max = sqrt(i);
			for (int j = 2; j <= max + 1; j++) {
				if (i == 1) {
					break;
				}
				if (j == max + 1) {
					sum++;
				}
				if (i % j == 0) break;
			}
		}
		count.push_back(sum);
	}

	for (iter = count.begin(); iter != count.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}