#include <iostream>
using namespace std;

int main() {

	int t;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}