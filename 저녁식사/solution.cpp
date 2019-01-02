#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
using namespace std;

struct A {
	int x;
	int y;
	int index;
};

map<int, pair<int, int>> m;	// key : x ��ǥ , value : y ��ǥ, index
map<int, pair<int, int>> m_second;		// key : y ��ǥ , value : x ��ǥ, index
vector<A> v;
int n;				// ���� ����
vector<vector<int>> ans;

bool compare(A a, A b) {
	
	return a.x < b.x;
}

int main() {

	int t;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; ++tc) {

		cin >> n;

		for (int i = 0; i < n; ++i) {			// x�� ���� �� y�� ū ��� �� �Ÿ�.
			int x, y;
			cin >> x >> y;
			if (m.find(x) == m.end()) m.insert(make_pair(x, make_pair(y, i + 1)));	// ������ �ϴ� �߰�
			else {
				if (m[x].first > y) {
					m[x].first = y;		// ���� y�� ���� y���� Ŭ ��� �ٲ���
					m[x].second = i + 1;
				}
			}
		}

		map<int, pair<int, int>>::iterator iter;

		for (iter = m.begin(); iter != m.end(); ++iter) {
			int x, y, index;
			x = iter->first , y = iter->second.first , index = iter->second.second;

			if (m_second.find(y) == m_second.end()) m_second.insert(make_pair(y, make_pair(x, index)));	// ������ �ϴ� �߰�
			else {
				if (m_second[y].first > x) {
					m_second[y].first = x;		// ���� x�� ���� x���� Ŭ ��� �ٲ���
					m_second[y].second = index;
				}
			}
		}

		for (iter = m_second.begin(); iter != m_second.end(); ++iter) {
			A a;
			a.x = iter->second.first;
			a.y = iter->first;
			a.index = iter->second.second;
			v.push_back(a);
		}

		sort(v.begin(), v.end(), compare);

		int max = v[0].y;
		int sz = v.size();
		for (int i = 0; i < sz - 1; ++i) {
			if (v[i + 1].index == 0) continue;
			if (max < v[i + 1].y) v[i + 1].x = 0, v[i + 1].y = 0, v[i + 1].index = 0;
			else max = v[i + 1].y;
		}

		vector<int> tmp;
		for (int i = 0; i < sz; ++i) if (v[i].index != 0) tmp.push_back(v[i].index);
		ans.push_back(tmp);

		v.clear();		//init
		m.clear();
		m_second.clear();
	}

	for (int tc = 0; tc < t; ++tc) {
		cout << '#' << tc + 1 << ' ';
		int sz = ans[tc].size();
		for(int i =0; i < sz; ++i) cout << ans[tc][i] << ' ';
		cout << '\n';
	}

	return 0;
}