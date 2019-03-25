#include <iostream>
#include <vector>
using namespace std;

vector<double> ans;

int main() {

	int t;
	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		double d, a, b, f;
		cin >> d >> a >> b >> f;
		if (d == 0) {
			ans.push_back(0);
			continue;
		}
		double time = d / (a + b);
		double answer = time * f;

		ans.push_back(answer);
	}

	int sz = ans.size();
	cout << fixed;
	cout.precision(11);
	for (int i = 0; i < sz; ++i) {
		cout << "#" << i + 1 << ' ' << ans[i] << '\n';
	}

	return 0;
}