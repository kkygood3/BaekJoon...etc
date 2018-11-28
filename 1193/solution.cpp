#include <iostream>
#include <string>
using namespace std;

int main() {

	long int n, X = 1;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;

	int i = 0;
	if (n == 1) { cout << "1/1"; return 0; }

	while (1) {
		int temp = X;
		X += i;
		if (temp <= n && n < X) {
			if (i % 2 != 0) {
				cout << i - (n - temp) << '/' << n - temp + 1; return 0;
			}
			else { cout << n - temp + 1 << '/' << i - (n - temp); return 0; }
		}
		i++;
	}
	return 0;
}