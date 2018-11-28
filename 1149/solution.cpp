#include <iostream>
#include <algorithm>
using namespace std;
#define R 0
#define G 1
#define B 2
int house[1001][3];

int main() {
	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> house[i][R] >> house[i][G] >> house[i][B];
	}

	for (int i = 1; i < n; i++) {
		house[i][R] += min({ house[i - 1][G], house[i - 1][B] });
		house[i][G] += min({ house[i - 1][R], house[i - 1][B] });
		house[i][B] += min({ house[i - 1][R], house[i - 1][G] });
	}

	cout << min({ house[n - 1][R], house[n - 1][G], house[n - 1][B] });
	return 0;
}