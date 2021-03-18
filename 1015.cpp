#include <cstdio>
#include <cmath>

bool isPrime(int d) {
	if (d == 1) return false;
	int n = (int)sqrt((double)d);
	int i;
	for(i=2; i<=n; i++) {
		if (d % i == 0) return false;
	}
	return true;
}

int getIntArray(int n, int radix, int nums[]) {
	int count=0;
	while (n > 0) {
		nums[count++] = n % radix;
		n /= radix;
	}
	return count;
}

int getInverseInt(int nums[], int radix, int length) {
	int ans=nums[0];
	int i;
	for (i=1; i< length; i++) {
		ans = ans * radix + nums[i];
	}
	return ans;
}

int _1015() {
	int n, d;
	int count=0;
	while(true) {
		scanf("%d", &n);
		if (n < 0) break;
		scanf("%d", &d);
		//if (count != 0) printf("\n");
		if (isPrime(n)) {
			int nums[100];
			int length = getIntArray(n, d, nums);
			int reversed = getInverseInt(nums, d, length);
			if (isPrime(reversed)) printf("Yes\n");
			else printf("No\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}