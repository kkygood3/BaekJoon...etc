#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> //memset
#include <vector>
#include <set>
using namespace std;
int t;

vector<int> cnt;
vector<string> v, v_unique;
set<string> st;
vector<int> ans;
int main() {

	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cnt.clear();
		v.clear();
		v_unique.clear();
		cin >> n;
		int mul = 1;
		string *s = new string[n];
		for (int j = 0; j < n; j++) {
			char c[50];
			cin.ignore();
			cin.getline(c, 50);
			s[j] = c;
			int idx;
			idx = s[j].find(" ");
			v.push_back(&s[j][idx + 1]);
			st.insert(&s[j][idx + 1]);
		}
		set<string>::iterator iter;
		for (iter = st.begin(); iter != st.end(); iter++) {
			string ss = *iter;
			int sum = 1;
			for (int k = 0; k < v.size(); k++)
			{
				if (ss == v[k]) sum++;
			}
			if(sum >= 2) cnt.push_back(sum);
		}
		
		for (int j = 0; j < cnt.size(); j++) {
			mul *= cnt[j];
		}
		
		ans.push_back(mul - 1);
	}
	
	for (int i = 0; i < ans.size(); i++) {
		if(i != ans.size() - 1)cout << ans[i] << '\n';
		else cout << ans[i];
	}
	return 0;
}
