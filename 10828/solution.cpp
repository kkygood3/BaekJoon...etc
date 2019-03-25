#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
	
	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	cin.ignore();
	string *str = new string[n];
	stack<int> s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		char c[20];
		cin.getline(c, 20);
		str[i] = c;

		if (str[i] == "pop") {
			if (s.empty()) v.push_back(-1);
			else {
				v.push_back(s.top());
				s.pop();
			}
		}
		else if (str[i] == "size") {
			v.push_back(s.size());
		}
		else if (str[i] == "empty") {
			if (s.empty()) v.push_back(1);
			else v.push_back(0);
		}
		else if (str[i] == "top") {
			if (s.empty()) v.push_back(-1);
			else v.push_back(s.top());
		}
		else {
			int su = atoi(&c[5]);
			s.push(su);
		}
	}
	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}