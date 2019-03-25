#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<int> v;
queue<int> q;
string s;
int n;

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;

	char c[20];
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cin.getline(c,20);
		s = c;
		if (s == "pop") {
			if (q.empty())
				v.push_back(-1);
			else {
				v.push_back(q.front());
				q.pop();
			}
		}
		else if (s == "size")
			v.push_back(q.size());
		else if (s == "empty") {
			if (q.empty()) v.push_back(1);
			else v.push_back(0);
		}
		else if (s == "front") {
			if (q.empty()) v.push_back(-1);
			else {
				v.push_back(q.front());
			}
		}
		else if (s == "back") {
			if (q.empty()) v.push_back(-1);
			else {
				v.push_back(q.back());
			}
		}
		else {
			int push_num;
			push_num = atoi(&c[5]);
			q.push(push_num);
		}
	}
	vector<int>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}
	
	return 0;
}