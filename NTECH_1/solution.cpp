#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int p, int m, int d) {
	int answer = 0;


	for (int k = 0; k <= 100; ++k) {

		double goal = p;
		for (int j = 1; j <= m; ++j) {
			goal += goal * double(double(k) / 100);
		}
		if (goal >= d) {
			answer = k;
			return answer;
		}
	}

	return answer;
}