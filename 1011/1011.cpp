#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

	int t, result[10000] = {0,};
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;

	
	for (int i = 0; i < t; i++) {

		long int x, y;
		cin >> x >> y;

		int d = y - x;
		
		int n = ceil(sqrt(d));
		int maxdist = pow(n, 2);
		int maxnum = 2 * n - 1;

		if (d <= maxdist - n) {
			maxnum -= 1;
		}

		result[i] = maxnum;

	}

	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	return 0;
}