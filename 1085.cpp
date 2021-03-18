#include <cstdio>
#include <algorithm>
using namespace std;

unsigned long long pseq[100000];
int lowi[100000];
int highi[100000];
int _1085() {
	int n;
	unsigned long long p;
	scanf("%d%lld", &n, &p);
	for (int i=0; i<n; i++) {
		scanf("%d", &pseq[i]);
	}
	sort(pseq, pseq+n);
	int max = 1;
	lowi[0] = highi[0] = 0;
	int len;
	for(int i=1; i<n; i++) {
		if (pseq[lowi[i-1]] * p >= pseq[i]) {
			lowi[i] = lowi[i-1];
			highi[i] = i;
		} else {
			highi[i] = i;
			lowi[i] = lowi[i-1]+1;
			while(pseq[highi[i]] > pseq[lowi[i]] * p) lowi[i]++;
		}
		len = (highi[i]-lowi[i]+1);
		if (max < len) max = len;
	}

	printf("%d", max);
	
	return 0;
}