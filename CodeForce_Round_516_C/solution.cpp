#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> v;
int n;

bool check(string s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}

int main() {

	int cur;
	string s , temp;
	int cnt = 0;

	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		cur = 0;
		while (cur + i <= n) {
			temp = s.substr(cur, i);
			if (check(temp)) cnt++;
			cur++;
		}
	}
	cout << cnt << '\n';
	return 0;
}