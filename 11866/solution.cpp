#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

queue<int> q;
vector<int> v;
int main() {

	int n, m;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int cnt = 1;
	int temp;
	while (!q.empty()) {
		if (cnt == m+1) cnt = 1;
		if (cnt == m) {
			temp = q.front();
			q.pop();
			v.push_back(temp);
		}
		else {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		cnt++;
	}
	vector<int>::iterator iter;
	cout << '<';
	for (iter = v.begin(); iter != v.end(); iter++) {
		if (iter == v.end() - 1) cout << *iter;
		else cout << *iter << ", ";
	}
	cout << '>';
	return 0;
}