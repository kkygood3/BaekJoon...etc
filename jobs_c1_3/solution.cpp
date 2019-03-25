#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, ans = 0, arr[3];
bool d[9];
string ques[101];

bool check(string s) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int strike = 0, ball = 0;

		if (ques[i][0] == s[0]) strike++;
		else if (ques[i][1] == s[0] || ques[i][2] == s[0]) ball++;

		if (ques[i][1] == s[1]) strike++;
		else if (ques[i][0] == s[1] || ques[i][2] == s[1]) ball++;

		if (ques[i][2] == s[2]) strike++;
		else if (ques[i][0] == s[2] || ques[i][1] == s[2]) ball++;

		if (ques[i][4] == strike + '0' && ques[i][6] == ball + '0') cnt++;
	}
	if (cnt == n) return true;
	else return false;
}

void DFS(int cnt) {

	if (cnt == 3) {
		string temp;
		for (int i = 0; i < 3; i++) {
			temp.push_back(arr[i] + '0');
		}

		if (check(temp)) ans++;

		return;
	}

	for (int i = 0; i < 9; i++) {
		if (!d[i]) {
			d[i] = true;
			arr[cnt] = i + 1;
			DFS(cnt + 1);
			d[i] = false;
		}
	}
}

int main() {

	cin >> n;
	cin.ignore();
	char c[8];
	for (int i = 0; i < n; i++) {
		cin.getline(c, 8);
		ques[i] = c;
	}
	string tmp;
	
	DFS(0);
	cout << ans << '\n';
}