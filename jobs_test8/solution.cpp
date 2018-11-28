#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {

	int n;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	vector<int>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << ' ';
	}

	return 0;
}