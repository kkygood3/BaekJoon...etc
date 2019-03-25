#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct comp {
	bool operator()(string a, string b) {
		return a > b;
	}
};

set<string, comp> s;
int n, k;
int d;
char arr[30];
vector<int> v;

int main() {
	
	int t;
	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		cin >> n >> k;
		d = n / 4;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		for (int i = 0; i < n; ++i) {
			string temp = "";
			
			if (i + d - 1 >= n) {
				for (int j = 0; j < d; ++j) {
					if (i + j >= n) temp += arr[i + j - n];
					else temp += arr[i + j];
				}
			}
			else {
				for (int j = 0; j < d; ++j) {
					temp += arr[i + j];
				}
			}

			s.insert(temp);
		}

		set<string>::iterator iter;
		int idx = 0;
		string ans;
		for (iter = s.begin(); iter != s.end(); ++iter) {
			if(idx == k - 1) ans = *iter;
			idx++;
		}

		int tmp = 0;
		int answer = 0;
		for (int i = ans.size() - 1; i >= 0 ; --i) {
			if (ans[i] >= '0' && ans[i] <= '9') {
				answer += int(ans[i] - '0') * pow(16, tmp);
			} else {
				answer += int(ans[i] - 'A' + 10) * pow(16, tmp);
			}

			tmp++;
		}
		v.push_back(answer);
		s.clear();
	}

	for (int i = 0; i < v.size(); ++i) cout << '#' << i + 1 << ' ' << v[i] << '\n';
	return 0;
}