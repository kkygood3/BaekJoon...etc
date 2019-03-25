#include <iostream>
#include <cstring>
using namespace std;

int main() {

	int count = 0;
	char arr[1000000];
	bool test = true;
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin.getline(arr, 1000000, '\n');

	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == ' ') {
			test = true;
		}
		else {
			if(test) count++;
			test = false;
		}
	}
	cout << count;
	return 0;
}