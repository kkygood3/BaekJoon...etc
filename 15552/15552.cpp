#include <iostream>
using namespace std;


int main() {
	int n1,n2, t;
	int sum = 0;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	int *p = new int[t];

	for (register int i = 0; i < t; i++) {
		cin >> n1 >> n2;
		p[i] = n1 + n2;
	}
	for (register int i = 0; i < t; i++)
	{
		cout << p[i] << '\n';
	}
	return 0;
}