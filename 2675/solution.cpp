#include <iostream>
#include <string>
using namespace std;

int main() {

	int t, r[1000];
	string s[1000];
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r[i];
		cin >> s[i];
	}
	for (int i = 0; i < t; i++) {
		string temp = "";
		for (int j = 0; j < s[i].length(); j++) {
			for (int k = 0; k < r[i]; k++) {
				cout << s[i][j];
			}
		}
		cout << endl;
	}
}