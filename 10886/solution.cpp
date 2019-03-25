#include <iostream>
using namespace std;


int main() {

	int n;
	cin >> n;

	int cnt_o = 0;
	int cnt_x = 0;
	
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp) cnt_o++;
		else cnt_x++;
	}

	if (cnt_o > cnt_x) cout << "Junhee is cute!" << '\n';
	else cout << "Junhee is not cute!" << '\n';

	return 0;
}
