#include <iostream>
using namespace std;

int main() {

	int N;
	int max = 0;
	double avg = 0;
	int score[1000];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}

	for (int i = 0; i < N; i++) {
		if (max < score[i]) max = score[i];
	}
	
	for (int i = 0; i < N; i++) {
		avg += double(score[i]) / double(max) * 100.;
	}
	avg /= N;
	cout << avg;
	
	return 0;
}