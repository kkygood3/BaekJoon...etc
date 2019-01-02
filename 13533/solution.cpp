#include <iostream>
#include <vector>
#include <utility>
typedef long long ull;
#define MOD 1000000007
using namespace std;

vector<pair<ull,ull>> v;
int n;
ull s;
ull ans = 0;



ull Pactorial(ull n){
	if (n <= 1) return 1;
	return Pactorial(n - 1) * n;
}

ull Combination(ull n, ull r) {
	if (r == 0 || n == 0) return 1;
	return Pactorial(n) / Pactorial(r) / Pactorial(n - r);
}

ull Duplication(ull n, ull r) {
	return Combination(n + r - 1, r);
}

int main() {

	cin >> n >> s;
	cout << Duplication(3, 5) << Duplication(3, 3) << Duplication(3, 1) << Duplication(3, 2) << '\n';

	return 0;
}