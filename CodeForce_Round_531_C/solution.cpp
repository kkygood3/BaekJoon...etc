#include <iostream>
using namespace std;
#define pb push_back
#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 100005
#define pi pair<int,int>
#define int long long
#define F first
#define S second
#define sz size()

int n;
signed main() {
	cin >> n;
	int x = (n*(n + 1)) / 2;
	cout << x << '\n';
	if (x % 2) cout << 1;
	else cout << 0;
}