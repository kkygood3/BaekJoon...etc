	#include <iostream>
	using namespace std;
	bool hansu(int num);

	int main() {

		int N, count = 0;
		cin >> N;

		for (register int i = 1; i <= N; i++) {
			if (hansu(i)) count++;
		}
		cout << count;
		return 0;
	}

	bool hansu(int num) {
		int x[4];
		if (num < 100) return true;
		else if(num < 1000){
			x[0] = num % 10;
			x[1] = (num / 10) % 10;
			x[2] = (num / 100) % 10;
			if ((x[2] - x[1]) == (x[1] - x[0])) return true;
			else return false;
		}
		else if(num < 10000){
			x[0] = num % 10;
			x[1] = (num / 10) % 10;
			x[2] = (num / 100) % 10;
			x[3] = (num / 1000) % 10;
			if (((x[3] - x[2]) == (x[2] - x[1])) && ((x[2] - x[1])== (x[1] - x[0]))) return true;
			else return false;
		}
		else return false;
	}