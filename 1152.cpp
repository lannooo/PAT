#include <cstdio>
#include <cmath>

long long findPrimeInConsecutive(int L, int K, int digits[]) {
	for (int i=0; i<=L-K; i++){
		long long ans = 0;
		for (int j=i; j<i+K; j++) {
			ans = ans * 10 + digits[j];
		}
		// consider whether ans is prime
		int sqr = (int)sqrt((double)ans);
		bool isprime = true;
		for (int k = 2; k <= sqr; k++) {
			if (ans % k == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) return ans;
	}
	return -1;
}

int _1152() {
	int L,K;
	char buf[1001];
	int digits[1001];
	scanf("%d %d", &L, &K);
	scanf("%s", buf);
	for(int i=0; i<L; i++) {
		digits[i] = buf[i] - '0';
	}
	long long res = findPrimeInConsecutive(L, K, digits);
	if (res == -1) printf("404");
	else {
		// print in format as a K-digits number, add 0 at head if not enough
		int count = 0;
		int d[10];
		char out[12];
		while(count < K) {
			d[count++] = res % 10;
			res /= 10;
		}
		count = 0;
		for(int i=K-1; i>=0; i--) {
			out[count++] = d[i] + '0';
		}
		out[count] = 0;
		printf("%s", out);
	}
	//getchar();getchar();
	return 0;
}