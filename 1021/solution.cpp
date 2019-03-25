#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
#include <deque>
#include <cmath>
#include <queue>
using namespace std;

deque<int> dq;
deque<int> q;

int main() {

	int n, m, cnt = 0;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		q.push_back(temp);
	}
	int idx;
	while (!q.empty()) {
		for (int i = 0; i < dq.size(); i++) {
			if (q.front() == dq.at(i)) idx = i;
			//cout << dq.at(i) << ' ';
		}
		//cout << '\n';
		if (q.front() == dq.front()) {
			q.pop_front();
			dq.pop_front();
		}
		else if ((dq.size() - idx) > abs(idx - 1)) {
			cnt++;
			int temp;
			temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}
		else {
			cnt++;
			int temp;
			temp = dq.back();
			dq.pop_back();
			dq.push_front(temp);
		}
	}
	cout << cnt;

	return 0;
}