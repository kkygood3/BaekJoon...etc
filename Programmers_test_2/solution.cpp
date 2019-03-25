#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int l, vector<int> v) {
	int answer = 0;

	sort(v.begin(), v.end());
	int sz = v.size();

	for (int i = 1; i < sz; ++i) {
		int dis = v[i] - v[i - 1];
		if (dis > answer) answer = dis + 1;
	}

	answer /= 2;

	if(answer < v[0]) answer = v[0] - 0;
	if (l - v[sz - 1] > answer) answer = l - v[sz - 1];

	return answer;
}