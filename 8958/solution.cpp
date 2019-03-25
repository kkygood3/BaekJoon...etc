#include <iostream>
#include <string>
using namespace std;

int main() {

	int t;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	string s[10000];
	int score[10000] = { 0, };
	for (int i = 0; i < t; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < t; i++) {
		int count = 0;
		for (int j = 0; j < s[i].length(); j++) {
			if (s[i][j] == 'O') {
				count++;
				score[i] += count;
			}
			else {
				count = 0;
			}
		}
	}
	
	for (int i = 0; i < t; i++) {
		cout << score[i] << endl;
	}

	return 0;
}