#include <iostream>
using namespace std;

int main() {

	int hour;
	int min;
	cin >> hour >> min;

	int time;
	cin >> time;

	min += time;

	while (min >= 60) {
		min -= 60;
		hour += 1;
	}

	while (hour >= 24) {
		hour -= 24;	
	}

	cout << hour << ' ' << min << '\n';

	return 0;
}