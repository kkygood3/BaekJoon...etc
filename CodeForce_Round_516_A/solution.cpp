#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {

	int a, b, c, Max;

	cin >> a >> b >> c;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(),v.end());
	if (v[2] < v[1] + v[0]) {
		cout << 0 << '\n';
	}
	else {
		cout << v[2] - v[1] - v[0] + 1 << '\n';
	}

	return 0;
}