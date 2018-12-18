#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

long long max_ = 0;
long long sum = 0;
string s = "";

int main() {

	int k;

	cin >> k;

	for (int i = 0; i < k; ++i) s.push_back('1');
	for (int i = 0; i < k - 1; ++i) s.push_back('0');

	cout << s << '\n';

	return 0;
}