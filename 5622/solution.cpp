#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string s;
	int temp = 0, count = 3, answer = 0;
	int c[130] = { 0, };
	cin >> s;
	for (int i = 'A'; i <= 'O'; i++) {
		if (temp == 3) { temp = 0; count++; }
		c[i] = count;
		temp++;
	}
	c['P'] = 8; c['Q'] = 8; c['R'] = 8; c['S'] = 8;
	c['T'] = 9; c['U'] = 9; c['V'] = 9;
	c['W'] = 10; c['X'] = 10; c['Y'] = 10; c['Z'] = 10;	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//cin >> s;

	for (int i = 0; i < s.length(); i++) {
		answer += c[s[i]];
	}
	cout << answer;
	return 0;
}