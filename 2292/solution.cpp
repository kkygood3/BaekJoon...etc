#include <iostream>
#include <string>
using namespace std;

int main() {

	int i = 1;
	long int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	long int num = 1;

	while(num < n){
		num += 6 * i;
		i++;
	}

	cout << i;
	return 0;
}