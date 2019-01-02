#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

long long n, k;

int main() {

	cin >> n >> k;

	long long left = 1;
	long long right = k;
	int ans;
	while (left <= right) {

		long long cnt = 0;
		long long mid = (left + right) / 2;
		for (int i = 1; i <= n; ++i) cnt += min(mid / i, n);	// i * j 보다 작은수를 찾아야하므로 mid / i => j를 이용 , n보다 클순 없으므로 n이 최대	

		if (cnt < k) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}

	}

	cout << ans << '\n';

	return 0;
}