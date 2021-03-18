#include <cstdio>

double numbers[100000];
int _1104() {
	long long n;
	scanf("%lld", &n);
	for (int i=0; i<n; i++) {
		scanf("%lf", &numbers[i]);
	}
	long long sum = 0;
	for (int i=0; i<n; i++) {
		long long times = (n-i)*(i+1);
		sum += times*((long long)(numbers[i]*1000.0));
	}

	printf("%.2lf", sum/1000.0);
	//getchar();getchar();
	return 0;
}