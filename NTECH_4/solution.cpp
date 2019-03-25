long long solution(long long k)
{
	int answer = 0;
	
	long long next = 1;
	for (long long i = 1; i <= k;) {	

		i += next++;
		if (i > k) answer = k - (i - --next) + 1;
	}

	return answer;
}