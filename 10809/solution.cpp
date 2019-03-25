#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	int c[200];
	cin >> s;
	for (int i = int('a'); i <= int('z'); i++) {
		c[i] = -1;
	}
	for (int i = 0; i < s.length(); i++) {
		if (c[int(s[i])] == -1) c[int(s[i])] = i;
	}
	for (int i = int('a'); i<= int('z'); i++) {
		cout << c[i] << ' ';
	}
	
	return 0;
}