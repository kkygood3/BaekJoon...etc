#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> //memcpy
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {

	int a, b;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> a >> b;

	cout << gcd(a,b) << '\n' << lcm(a, b);

	return 0;
}