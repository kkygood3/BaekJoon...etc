#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	int arr[10] = { 0, };

	cin >> s;

	replace(s.begin(), s.end(), '9', '6');
	for (int i = 0; i < s.size(); i++) {
		int n;
		n = s[i] - '0';
		arr[n]++;
	}
	arr[6] = ceil((double)arr[6] / 2);
	int temp = 0;
	for (int i = 0; i < size(arr); i++) {
		if (temp < arr[i]) temp = arr[i];
	}

	cout << temp;

	return 0;
}