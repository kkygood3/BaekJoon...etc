#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<string, bool> check;
vector<string> v;

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		check.insert(make_pair(s, true));
	}

	int count = 0;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (check[s]) {
			count++;
			v.push_back(s);
		}
	}

	cout << count << '\n';
	
	sort(v.begin(), v.end());
	int sz = v.size();
	
	for (int i = 0; i < sz; ++i) {
		cout << v[i] << '\n';
	}

	return 0;
}