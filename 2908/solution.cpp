#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ex(int x) {
	string s;
	char temp;
	s = to_string(x);
	temp = s[0];
	s[0] = s[2];
	s[2] = temp;
	return atoi(s.c_str());
}
int main() {

	int a[2], b[2];
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> a[0] >> b[0];
	a[1] = ex(a[0]);
	b[1] = ex(b[0]);

	if (a[1] > b[1]) cout << a[1];
	else cout << b[1];

	return 0;
}