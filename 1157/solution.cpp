#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string s;
	char ch;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> s;
	int c[130] = { 0, };
	for (int i = 0; i < s.length(); i++) {
		if (islower(s[i])) {
			s[i] += 'A' - 'a';
		}
	}
	for (int i = 0; i < s.length(); i++) {
		c[int(s[i])]++;
	}

	int max = 0;

	for (int i = int('A'); i <= int('Z'); i++) {
		if (max < c[i])
		{
			max = c[i];
			ch = char(i);
		}
		else if (max == c[i]) ch = '?';
	}
	cout << ch;
	return 0;
}