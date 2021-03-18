#include <stdio.h>

const int MAXN = 1001;

int _1002() {
	float polynomials[MAXN]={0};
	int n;
	int exp;
	float coe;
	scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%f", &exp, &coe);
		polynomials[exp] += coe;
    }
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
        scanf("%d%f", &exp, &coe);
		polynomials[exp] += coe;
    }
	int cnt = 0;
	int outexp[100];
	float outcoe[100];
	for(int i=MAXN-1; i>=0; i--) {
		// there may be very small float such as 0.0001 
		// (should it be considered as zero?)
		if (polynomials[i] != 0.0) {
			outexp[cnt] = i;
			outcoe[cnt] = polynomials[i];
			cnt++;
		}
	}
	printf("%d", cnt);
	for(int i=0; i<cnt; i++) {
		printf(" %d %.1f", outexp[i], outcoe[i]);
	}

	return 0;
}