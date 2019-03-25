#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<string> v;
queue<int> q;

int main() {

	int t;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	string str;
	for (int i = 0; i < t; i++) {
		cin >> str;

		stack<int> s;

		for (int j = 0; j <= str.size(); j++) {
			if (j == str.size()) {
				if (s.empty()) {
					v.push_back("YES");
					break;
				}
				else {
					v.push_back("NO");
					break;
				}
			}
			
			if(str[j] == '(')s.push(1);
			else {
				if (s.empty()) { 
					v.push_back("NO");
					break;
				}
				else s.pop();
			}
		}
	}

	vector<string>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}