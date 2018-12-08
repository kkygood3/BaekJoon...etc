#include <iostream>
#include <vector>
using namespace std;

int t;
vector<long double> v;

int main() {

	cin.tie(0); ios::sync_with_stdio(0);

	cin >> t;
	int n;
	long double p;
	long double x;

	for (int tc = 0; tc < t; ++tc) {

		cin >> n;
		long double ans = 0; 
		
		for (int i = 0; i < n; ++i) {
			cin >> p >> x;
			ans += p * x;
		}
		v.push_back(ans);
	}

	int sz = v.size();
	cout.precision(6);
	for (int i = 0; i < sz; ++i) {
		cout << "#" << i + 1 << " " << v[i] << '\n';
	}

	return 0;
}