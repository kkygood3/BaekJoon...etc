#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> v;
queue<int> q;
stack<char> s;
stack<int> ans;
int main() {

	int sum = 0;
	int mul = 1;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			mul *= 2;
			s.push('(');
			if (i + 1 < str.size() && str[i + 1] == ')') sum += mul;
		}
		if (str[i] == ')') {
			if (s.empty()) {
				sum = 0;
				break;
			}
			else {
				mul /= 2;
				if(s.top() == '(') s.pop();
			}
		}
		if (str[i] == '[') {
			mul *= 3;
			s.push('[');
			if (i + 1 < str.size() && str[i + 1] == ']') sum += mul;
		}
		if (str[i] == ']') {
			if (s.empty()) {
				sum = 0;
				break;
			}
			else {
				mul /= 3;
				if (s.top() == '[') s.pop();
			}
		}
	}
	
	if (!s.empty()) sum = 0;
	
	cout << sum;

	return 0;
}