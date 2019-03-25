#include <iostream>
#include <deque>
#include <vector>
using namespace std;

deque<int> dq;
vector<int> v;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		dq.push_back(i);
	}

	while (1) {
		v.push_back(dq.front());
		dq.pop_front(); //버리기
		if (dq.empty()) break;
		int temp = dq.front();
		dq.pop_front(); // 앞에서 빼고
		dq.push_back(temp); // 뒤로 넣기
	}
	int sz = v.size();
	for (int i = 0; i < sz; ++i) {
		cout << v[i] << ' ';
	}

	return 0;
}