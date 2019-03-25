#include <iostream>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 & b == 0) return 0;
		cout << a + b << '\n';
	}
	return 0;
}