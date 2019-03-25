#include <iostream>
#include <vector>
using namespace std;

int n, k;
int arr[5010];
int tmp[5010];
int cnt;
vector<int> v;
vector<int> wow[5010];

int main() {

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int idx;
		cin >> idx;
		arr[idx]++;
		v.push_back(idx);
		if (arr[idx] > k) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	
	if(n < k) {
		cout << "NO" << '\n';
		return 0;
	}

	int sum = 0;
	int pos = k;
	for (int i = 1; i <= 5000; ++i) {
		sum += arr[i];
		if (sum >= k) {
			pos = i;
			break;
		}
	}

	int su = 1;

	for (int i = 1; i <= pos; ++i) {
		int sz  = arr[i];
		for (int j = 0; j < sz; ++j) {
			wow[i].push_back(su++);
			if (su > k) su = 1;
		}
	}

	int sz = v.size();
	cout << "YES" << '\n';
	for (int i = 0; i < sz; ++i) {
		if (v[i] <= pos) {
			int pri = wow[v[i]].back();
			cout << pri << ' ';
			wow[v[i]].pop_back();
		}
		else {
			cout << ++tmp[v[i]] << ' ';
		}
	}

	return 0;
}