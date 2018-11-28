#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int n, count = 0;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	string s[100];

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		bool sw = false;
		char c[130] = { 0, };
		char temp = s[i][0];
		for (int j = 0; j < s[i].length(); j++) {
			if (temp != s[i][j] && c[s[i][j]] != 0) sw = true;
			c[s[i][j]]++;
			temp = s[i][j];
		}
		if (!sw)count++;
	}
	cout << count;
	
	return 0;
}