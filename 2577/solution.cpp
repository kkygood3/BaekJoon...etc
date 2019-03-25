#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b, c, x;
	int count[10] = {0,};
	string s;

	cin >> a >> b >> c;

	x = a * b * c;

	s = to_string(x);

	for (int i = 0; i < s.length(); i++) {
		char c;
		int n;
		c = s[i];
		n = c - '0';
		count[n]++;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << count[i] << endl;
	}

	return 0;
}