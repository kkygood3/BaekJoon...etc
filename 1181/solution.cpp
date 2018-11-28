#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const string &s1, const string &s2) {

	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	return s1.size() < s2.size();
}

int main() {

	int n;
	cin.tie(NULL);	
	ios::sync_with_stdio(false);
	cin >> n;

	vector<string> v;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}

	vector<string>::iterator iter;
	vector<string>::iterator end_iter;

	sort(v.begin(), v.end(), comp);
	
	end_iter = unique(v.begin(), v.end());

	for (iter = v.begin(); iter != end_iter; iter++) {
		cout << *iter << '\n';
	}

	return 0;
}