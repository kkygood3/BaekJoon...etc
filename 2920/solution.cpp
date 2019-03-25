#include <iostream>
#include <string>
using namespace std;

int main() {

	int n[8];
	string s = "";
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	for (int i = 0; i < 8; i++) {
		cin >> n[i];
	}
	
	for (int i = 0; i < 8; i++) {
		s.append(to_string(n[i]));
	}
	if (s == "12345678") cout << "ascending";
	else if (s == "87654321") cout << "descending";
	else cout << "mixed";

	return 0;
}