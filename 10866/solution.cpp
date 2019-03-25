#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
#include <deque>
using namespace std;

deque<int> dq;
vector<int> v;
vector<int>::iterator iter;

int main() {

	int t;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;

	cin.ignore();
	for (int i = 0; i < t; i++) {

		char c[20];
		cin.getline(c, 20);
		string s = c;
		int x, temp;

		if (s.find("push_front") != string::npos) {
			x = atoi(&c[11]);
			dq.push_front(x);
		}
		else if (s.find("push_back") != string::npos) {
			x = atoi(&c[10]);
			dq.push_back(x);
		}
		else if (s == "pop_front") {
			if (dq.empty()) v.push_back(-1);
			else {
				temp = dq.front();
				dq.pop_front();
				v.push_back(temp);
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) v.push_back(-1);
			else {
				temp = dq.back();
				dq.pop_back();
				v.push_back(temp);
			}
		}
		else if (s == "size") {
			v.push_back(dq.size());
		}
		else if (s == "empty") {
			v.push_back(dq.empty());
		}
		else if (s == "front") {
			if (dq.empty()) v.push_back(-1);
			else v.push_back(dq.front());
		}
		else if (s == "back") {
			if (dq.empty()) v.push_back(-1);
			else v.push_back(dq.back());
		}
	}



	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}