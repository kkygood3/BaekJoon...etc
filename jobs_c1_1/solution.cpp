#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){

	int d, cnt = 0;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> d;
	int tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	while (!v.empty()) {
		tmp = v.back();
		v.pop_back();
		if (tmp == d) cnt++;
	}

	cout << cnt;

	return 0;
}