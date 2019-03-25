#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 20010
using namespace std;

struct A {
	int able;	// ���� ���ݷ�
	int mis_a;  // ù��° �̻��� ���ݷ�
	int mis_b;  // ��ġ�� �̻��� ���ݷ�
};
int n, m, b;
int mis[MAX];
int sum;
vector<int> ans;

bool compare(A a, A b) {
	return a.able < b.able;
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	
	int t;
	cin >> t;

	for (int tc = 0; tc < t; ++tc) {

		cin >> n >> m >> b;
		sum = 0;
		vector<A> v;
		for (int i = 0; i < m; ++i) {
			int power, cnt;
			A a;
			cin >> power >> cnt;
			mis[power] = cnt;
			a.able = power;
			a.mis_a = power;
			a.mis_b = 0;
			v.push_back(a);

		}

		for (int i = 0; i < m; ++i) {
			for (int j = i; j < m; ++j) {
				A a;
				a.able = v[i].able + v[j].able;
				a.mis_a = v[i].able;
				a.mis_b = v[j].able;
				v.push_back(a);
			}
		}


		sort(v.begin(), v.end(), compare);

		int sz = v.size();

		for (int i = 0; i < sz; ++i) {

			if (n == 0) break;
			if (v[i].able >= b && mis[v[i].mis_a] >= 1 && v[i].mis_b == 0) {		// �Ѱ��� �̻��Ϸ� ������ ��

				if (n == 0) break;
				n--;
				sum += v[i].able;
				mis[v[i].mis_a]--;
				while (v[i].able >= b && mis[v[i].mis_a] >= 1 && v[i].mis_b == 0) {

					if (n == 0) break;
					n--;
					sum += v[i].able;
					mis[v[i].mis_a]--;
				}
			}
			else if (v[i].able >= b && mis[v[i].mis_a] >= 1 && mis[v[i].mis_b] >= 1 && v[i].mis_a != v[i].mis_b) {		// �ΰ��� �̻����ε� �ٸ� �̻���
				
				if (n == 0) break;
				n--;
				sum += v[i].able;
				mis[v[i].mis_a]--;
				mis[v[i].mis_b]--;
				while (v[i].able >= b && mis[v[i].mis_a] >= 1 && mis[v[i].mis_b] >= 1 && v[i].mis_a != v[i].mis_b) {

					if (n == 0) break;
					n--;
					sum += v[i].able;
					mis[v[i].mis_a]--;
					mis[v[i].mis_b]--;
				}
			}
			else if (v[i].able >= b && mis[v[i].mis_a] >= 2 && v[i].mis_a == v[i].mis_b) {		// �ΰ��� �̻����ε� ���� �̻���

				if (n == 0) break;
				n--;
				sum += v[i].able;
				mis[v[i].mis_a]-= 2;
				while (v[i].able >= b && mis[v[i].mis_a] >= 2 && v[i].mis_a == v[i].mis_b) {
					
					if (n == 0) break;
					n--;
					sum += v[i].able;
					mis[v[i].mis_a]-= 2;
				}
			}
		}

		if (n <= 0) ans.push_back(sum);
		else ans.push_back(-1);

	}	

	int sz = ans.size();
	for (int i = 0; i < sz; ++i) {
		cout << "#" << i + 1 << ' ' << ans[i] << '\n';
	}

	return 0;
}
