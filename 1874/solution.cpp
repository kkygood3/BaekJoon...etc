#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

vector<char> v;
stack<int> s;
queue<int> q;

int main() {

	int t, n, i = 1;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;


	for (int i = 0; i < t; i++) {
		cin >> n;
		q.push(n);
	}
	
	while (!q.empty()) {
		if (i == t + 2) break;
		if (s.empty()) {
			v.push_back('+');
			s.push(i++);
		}
		else if (s.top() == q.front()) {
			v.push_back('-');
			s.pop();
			q.pop();
		}
		else {
			v.push_back('+');
			s.push(i++);
		} 

	}

	vector<char>::iterator iter;

	if (!q.empty()) cout << "NO";
	else {
		for (iter = v.begin(); iter != v.end(); iter++) {
			cout << *iter << '\n';
		}
	}

	return 0;
}