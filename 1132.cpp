#include <cstdio>

bool isInteresting(int z) {
	long long temp = z;
	int mod = 1;
	int digits=0;
	while(z > 0){
		digits ++;
		z /= 10;
	} 
	for(int i=0; i<digits/2; i++) mod *= 10;
	long long a = temp / mod;
	long long b = temp % mod;
	long long ab = a * b;
	if (ab == 0) return false;
	if (temp % ab == 0) return true;
	else return false;
}

int _1132() {
	int n;
	scanf("%d", &n);
	int z;
	for(int i=0; i<n; i++) {
		scanf("%d", &z);
		if (isInteresting(z)) printf("Yes\n");
		else printf("No\n");
	}
	//getchar();getchar();
	return 0;
}