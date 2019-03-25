#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;
int arr[200];
int n, k;
vector<string> v;

void init() {
	for (int i = 'a'; i <= 'z'; ++i) arr[i] = 0;
}

int main() {

	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		cin >> n >> k;
		for (int i = 'a'; i < 'a' + k; ++i) {
			arr[i] = (n / k);
		}
		n %= k;
		int alpha = 'a';
		while (n != 0) {
			arr[alpha++]++;
			n--;
		}
		string s;
		for (int i = 'a'; i < 'a' + k; ++i) {
			for (int cnt = 0; cnt < arr[i]; ++cnt) {
				s.push_back(char(i));
			}
		}

		v.push_back(s);

		init();
	}

	int sz = v.size();

	for (int i = 0; i < sz; ++i) cout << v[i] << '\n';

	return 0;
}