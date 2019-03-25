#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v;

bool compare(string a, string b) {

	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	else {
		int a_sum = 0;
		int b_sum = 0;
		int sz = a.size();
		for (int i = 0; i < sz; ++i) {
			int tmp = a[i] - '0';
			if (tmp >= 0 && tmp <= 9) a_sum += tmp;
			tmp = b[i] - '0';
			if (tmp >= 0 && tmp <= 9) b_sum += tmp;
		}
		if (a_sum == 0 && b_sum == 0) return a < b;
		if (a_sum == b_sum) return a < b;
		return a_sum < b_sum;
	}

}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);

	int sz = v.size();
	for (int i = 0; i < sz; ++i) {
		cout << v[i] << '\n';
	}

	return 0;
}