#include <string>
#include <vector>
#include <queue>

using namespace std;

bool solution(vector<int> arrA, vector<int> arrB) {
	queue<int> q;

	int first = arrA[0];
	int sz_a = arrA.size();
	int sz = arrB.size();

	if (sz_a != sz) return false;

	for (int i = 0; i < sz; ++i) {
		if (arrB[i] == first) q.push(i);
	}

	while(!q.empty()){
		int idx = q.front();
		q.pop();
		bool check = false;
		for (int i = 0; i < sz; ++i) {

			if (arrA[i] != arrB[idx]) {
				check = true;
				break;
			}

			++idx;
			if (idx == sz) idx = 0;
		}
		if (!check) return true;
	}

	return false;
}