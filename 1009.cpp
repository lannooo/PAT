#include <cstdio>

int _1009() {
	float polya[1001]={0};
	float polyb[1001]={0};
	float polyp[2002] = {0};
	int na, nb;
	int exp;
	float coe;
	// read two polynomials A and B
	scanf("%d", &na);
	for(int i=0; i<na; i++) {
		scanf("%d%f", &exp, &coe);
		polya[exp] += coe;
	}
	scanf("%d", &nb);
	for(int i=0; i<nb; i++) {
		scanf("%d%f", &exp, &coe);
		polyb[exp] += coe;
	}

	// calculate the product of A and B
	for (int i=0; i<=1000; i++) {
		if (polya[i] != 0) {
			for (int j=0; j<=1000; j++) {
				if (polyb[j] != 0) {
					polyp[i+j] += (polya[i]*polyb[j]);
				}
			}
		}
	}
	int cnt = 0;
	for(int i=0; i<=2000; i++) {
		if (polyp[i] != 0.0) cnt++;
	}
	printf("%d", cnt);
	for(int i=2000; i>=0; i--) {
		if (polyp[i] != 0.0) printf(" %d %.1f", i, polyp[i]);
	}
	//getchar();getchar();
	return 0;
}