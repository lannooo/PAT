#include <cstdio>

bool presents[100001] = {false};

int _1144(){
	int n, d;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &d);
		if (d >=0 && d <=100000) {
			presents[d] = true;
		}
	}
	int miss = n+1;
	for(int i=1; i<=n; i++) {
		if (presents[i] == false) {
			miss = i;
			break;
		}
	}
	printf("%d", miss);
	//getchar();getchar();
	return 0;
}