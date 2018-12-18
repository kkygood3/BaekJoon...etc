#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> ans;

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		ans.push_back(0);
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			ans[i] += v[j];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += ans[i];
	}

	cout << sum << '\n';

	return 0;
}