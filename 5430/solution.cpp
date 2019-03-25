#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stdlib.h>
#include <algorithm>
using namespace std;

vector<string> v[100];

int main() {

	int t, n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		
		queue<char> q;
		deque<int> dq;
		bool pass = false;
		bool front = true;
		char *c;
		string p;
		cin >> p;
		int p_size = p.size();
		for (int j = 0; j < p_size; j++) {
			q.push(p[j]);
		}
		cin >> n;
		c = new char[4*n + 3];
		cin >> c;
		string s = c;
		c[s.size()-1] = '\0';
		char *ptr = strtok(&c[1], ",");

		while (ptr != NULL) {
			dq.push_back(atoi(ptr));
			ptr = strtok(NULL, ",");
		}
		for (int j = 0; j < p_size; j++) {
			char temp;
			temp = q.front();
			q.pop();
			if (temp == 'R') {
				front = !front;
			}
			else {
				if (dq.empty())
				{
					v[i].push_back("error");
					pass = true;
					break;
				}
				else {
					if(front) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		int dq_size = dq.size();
		if (!pass) {
			v[i].push_back("[");
			if (front) {
				for (int j = 0; j < dq_size; j++) {
					string s_temp = to_string(dq.at(j));
					v[i].push_back(s_temp);
					v[i].push_back(",");
					if (j == dq_size - 1) v[i].pop_back();
				}
			}
			else {
				for (int j = dq_size - 1; j >= 0; j--) {
					string s_temp = to_string(dq.at(j));
					v[i].push_back(s_temp);
					v[i].push_back(",");
					if (j == 0) v[i].pop_back();
				}
			}
			v[i].push_back("]");
		}
	}


	for (int i = 0; i < t; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j];
		}
		if(!(i == t-1))cout << '\n';
	}

	return 0;
}