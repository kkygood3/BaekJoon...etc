#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int arr[1000000];
int n;

int main(void) {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		int tmp = i + 1;
		while (tmp < n) {
			if (arr[tmp] >= arr[i]) {
				if (ans < tmp - i) ans = tmp - i;
				break;
			}

			tmp++;
		}
	}

	cout << ans << '\n';

	return 0;
}