#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int main(void) {

	string s;
	cin >> s;

	int sz = s.size();

	queue<string> q1;
	queue<string> q2;

	for (int i = 0; i < sz;) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			string str = "";
			str += s[i];

			if (s[i + 1] >= 'A' && s[i + 1] <= 'Z') {
				q1.push(str);
				i++;
				continue;
			}
			else if (s[i + 1] >= 'a' && s[i + 1] <= 'z') {
				str += s[i + 1];
				q1.push(str);
				i += 2;
				continue;
			}
			else {
				q1.push(str);
				i++;
				continue;
			}
		}

		else if (s[i] >= '2' && s[i] <= '9') {
			string str = "";
			str += s[i];
			q2.push(str);
			i++;
			continue;
		}
		else if (s[i] == '1') {
			string str = "";
			str += s[i];
			if (s[i + 1] == '0') {
				str += s[i + 1];
				q2.push(str);
				i += 2;
				continue;
			}
			else {
				q2.push(str);
				i++;
				continue;
			}
		}
	}

	if (q1.size() != q2.size()) cout << "error" << '\n';
	else {
		int qs = q1.size();
		string cmp = "1";
	
		for (int i = 0; i < qs; ++i) {
			cout << q1.front();
			q1.pop();
			if (q2.front() == cmp) {
				q2.pop();
			}
			else {
				cout << q2.front();
				q2.pop();
			}
		}
		cout << '\n';
	}

	return 0;
}