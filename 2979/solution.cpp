#include <iostream>
#define MAX 110
using namespace std;

int arr[110];
int a, b, c;
int fee = 0;

int main() {

	cin >> a >> b >> c;
	
	int start, end;
	cin >> start >> end;
	for (int i = start; i < end; ++i) arr[i]++;
	cin >> start >> end;
	for (int i = start; i < end; ++i) arr[i]++;
	cin >> start >> end;
	for (int i = start; i < end; ++i) arr[i]++;

	for (int i = 0; i < 101; ++i) {
		if (arr[i] == 1) fee += a;
		if (arr[i] == 2) fee += b * 2;
		if (arr[i] == 3) fee += c * 3;
	}

	cout << fee << '\n';

	return 0;
}