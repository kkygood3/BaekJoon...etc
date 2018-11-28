#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(int i, int j, int arr[][12]) {
	int count = 0;
	if (arr[i][j] != 0) {
		arr[i][j] = 0;
		count++;
	}
	if (arr[i][j - 1] != 0) {
		arr[i][j - 1] = 0;
		count += check(i, j - 1, arr);
		count++;
	}
	if (arr[i - 1][j] != 0) {
		arr[i - 1][j] = 0;
		count += check(i - 1, j, arr);
		count++;
	}
	if (arr[i][j + 1] != 0) {
		arr[i][j + 1] = 0;
		count += check(i, j + 1, arr);
		count++;
	}
	if (arr[i + 1][j] != 0) {
		arr[i + 1][j] = 0;
		count += check(i + 1, j, arr);
		count++;
	}
	return count;
}

int main() {

	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	int arr[12][12] = {0,};
	
	vector<int> v;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != 0) v.push_back(check(i,j,arr));
		}
	}
	cout << v.size();
	sort(v.begin(), v.end());
	vector<int>::iterator iter;

	if (!v.empty()) {
		cout << '\n';
		for (iter = v.begin(); iter != v.end(); iter++) {
			cout << *iter << ' ';
		}
	}
	return 0;
}