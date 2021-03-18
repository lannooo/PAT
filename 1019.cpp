#include <cstdio>

int _1019() {
	long long n, b;

	scanf("%lld %lld", &n, &b);

	// for case that n is smaller than b, there is only 1 digit in this numeral system
	if (n < b) {
		printf("Yes\n%lld", n);
		//getchar();getchar();
		return 0;
	}

	long long digits[100];
	int count = 0;
	while (n > 0) {
		digits[count++] = n % b;
		n /= b;
	}

	int i;
	bool palindromic = true;
	for (i=0; i < count/2; i++) {
		if (digits[i] != digits[count-i-1]){
			palindromic = false;
			break;
		}
	}
	if (palindromic) printf("Yes\n");
	else printf("No\n");

	for(i=count-1; i>=0; i--) {
		if (i!=count-1) printf(" ");
		printf("%lld", digits[i]);
	}
	//getchar();getchar();
	return 0;
}