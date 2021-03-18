#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int const MAX_N = 100001;
bool isPrime_1059[MAX_N];
int primes_1059[MAX_N];
int pindex_1059 = 0;

void findAllPrimes() {
	fill(isPrime_1059, isPrime_1059+MAX_N, true);
	isPrime_1059[0] = false;
	isPrime_1059[1] = false;
	for (int i=2; i<MAX_N; i++) {
		if (isPrime_1059[i]) {
			primes_1059[pindex_1059++] = i;
			for(int j=i+i; j<MAX_N; j+=i) isPrime_1059[j] = false;
		}
	}
}

struct pfactor {
	int p;
	int k;
};

int _1059() {
	pfactor pfactor[10];
	int findex = 0;
	findAllPrimes();

	long long n, temp;
	scanf("%lld", &n);

	if (n == 1) {
		printf("1=1");
		return 0;
	}

	int sqr = sqrt((double)n);
	temp = n;
	for (int i=0; primes_1059[i] <= sqr; i++) {
		int p=primes_1059[i];
		if (temp % p == 0) {
			int cnt = 0;
			while(temp > 0) {
				if (temp % p != 0) break;
				temp /= p;
				cnt++;
			}
			pfactor[findex].p = p;
			pfactor[findex].k = cnt;
			findex++;
		}
	}
	if (temp > 1) {
		pfactor[findex].p = temp;
		pfactor[findex].k = 1;
		findex++;
	}
	printf("%lld=", n);
	for (int i=0; i<findex; i++) {
		if (i!=0) printf("*");
		if (pfactor[i].k == 1) {
			printf("%d", pfactor[i].p);
		} else {
			printf("%d^%d", pfactor[i].p, pfactor[i].k);
		}
	}
	
	return 0;
}