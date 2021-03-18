#include <cstdio>
#include <cmath>


int findConsecutive(int n, int expfactor) {
	if (n == 1) return 0;
	if (n % expfactor != 0) return 0;
	return 1 + findConsecutive(n/expfactor, expfactor+1);
}

int _1096_2() {
	int n;
	scanf("%d", &n);
	int sqr = (int)sqrt(1.0 * n);
	int c=0;
	int firstFactor = 1;
	for (int i=2; i<=sqr; i++) {
		if (n % i == 0) {
			int cc = findConsecutive(n, i);
			if (cc > c) {
				c = cc;
				firstFactor = i;
			}
		}
	}
	if (firstFactor == 1) {
		firstFactor = n;
		c = 1;
	}
	printf("%d\n", c);
	for(int i=0; i<c; i++) {
		if (i!=0) printf("*");
		printf("%d", firstFactor+i);
	}

	return 0;
}