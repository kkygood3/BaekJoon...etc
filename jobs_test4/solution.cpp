#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {

	int a, b, c;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> a >> b >> c;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	sort(v.begin(), v.end());

	cout << v[1];
	

	return 0;
}