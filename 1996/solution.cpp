#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> v;

stack<char> s;
stack<int> ans;
int main() {

	int t , want;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		int cnt = 0;
		queue<pair<int, int>> q;
		priority_queue <int> pq;

		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			q.push({ j, temp });
			pq.push(temp);
		}

		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (val == pq.top()) {
				cnt++;
				pq.pop();
				if (idx == m) {
					v.push_back(cnt);
					break;
				}
			}
			else {
				q.push({ idx, val });
			}

		}
	}
	for (int i = 0; i < t; i++) {
		cout << v[i] << '\n';
	}
	return 0;
}