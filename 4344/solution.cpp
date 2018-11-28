#include <iostream>
using namespace std;

int main() {

	int C, N;
	int score[1000];
	double avg = 0;
	double answer[1000];
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> score[j];
			avg += score[j];
		}
		avg = 0;
		for (int j = 0; j < N; j++) {
			avg += score[j];
		}
		avg /= double(N);
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (score[j] > avg) count++;
		}
		answer[i] = double(count) / double(N) * 100.;
	}
	for (int i = 0; i < C; i++) {
		cout << fixed;
		cout.precision(3);
		cout << answer[i] << "%" << "\n";
	}
	
	return 0;
}