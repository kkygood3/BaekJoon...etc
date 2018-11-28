#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {

	int a, b, c;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> a >> c >> b;

	for (int i = a; i <= c; i++) {
		cout << i << ' ';
	}

	for (int i = c - 1; i >= b; i--) {
		cout << i << ' ';
	}

	return 0;
}