#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

vector<int> v;
vector<int>::iterator iter;
int sel_days = 0;
int days;
int gain = 0;
int maximum = 0;

void sel(int start, vector<int> v) {
	if (start == days) return;
	int max = 0;
	int temp = 0;
	for (int i = start; i < days; i++) {
		if (max < v[i]) {
			max = v[i];
			temp = i;
		}
	}
	if (temp != start) {
		sel_days++;
		sel(temp + 1, v);
	}
	else {
		sel(temp + 1, v);
	}
}

int main() {

	int max = 0;
	cin >> days;
	

	for (int i = 0; i < days; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sel(0, v);

	for (int i = days - 1; i >= 0; i--) {
		if (v[i] > max) {
			max = v[i];
		}
		else {
			gain += (max - v[i]);
		}
	}

	cout << gain - sel_days;

	return 0;
}