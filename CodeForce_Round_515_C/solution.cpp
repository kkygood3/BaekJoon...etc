#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	char c;
	int q, n;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> c >> n;
		if (c == 'L') dq.push_front(n);
		else if (c == 'R') dq.push_back(n);
		else {
			int cnt = 0;
			for (int i = 0; i < dq.size(); i++) {
				if (dq.at(i) == n) break;
				else cnt++;
			}
			if (cnt > (dq.size() - 1) / 2) cnt = (dq.size() - 1) - cnt;
			cout << cnt << '\n';
		}
	}
	return 0;
}