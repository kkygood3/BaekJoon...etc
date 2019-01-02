#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int n;
deque<char> dq;
vector<string> ans;

int main() {
	
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		cin >> n;

		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;

			if (i == 0) dq.push_back(c);
			else {
				if (dq.front() <= c) dq.push_front(c);
				else dq.push_back(c);
			}
		}
		string s = "";
		for (int i = 0; i < n; ++i) {
			s.push_back(dq.front());
			dq.pop_front();
		}

		ans.push_back(s);
		
	}

	for (int tc = 0; tc < t; ++tc) cout << '#' << tc + 1 << ' ' << ans[tc] << '\n';

	return 0;
}