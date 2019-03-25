#include <iostream>
#include <vector>
using namespace std;

int t;
vector<int> v;
vector<int> ans;

int main() {

	cin >> t;

	for (int tc = 0; tc < t; ++tc) {

		int a, b, m;

		cin >> a >> b;

		m = a < b ? b : a;
		
		for (int i = 2; i <= m; ++i) {
			
			while (a % i == 0 && b % i == 0) {
				v.push_back(i);
				a /= i;
				b /= i;
			}

			while (a % i == 0) {
				v.push_back(i);
				a /= i;
			}

			while (b % i == 0) {
				v.push_back(i);
				b /= i;
			}
			if (a == 1 && b == 1)break;
		}

		int sz = v.size();
		int mul = 1;
		for (int i = 0; i < sz; ++i) {
			mul *= v[i];
		}

		ans.push_back(mul);
		v.clear();
	}

	int sz = ans.size();
	for (int i = 0; i < sz; ++i) cout << ans[i] << '\n';

	return 0;
}