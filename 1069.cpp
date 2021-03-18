#include <cstdio>
#include <algorithm>
using namespace std;


// sort in decreasing order
bool cmp(int a, int b) {
	return a>b;
}

int array_to_int(int digits[]) {
	int i;
	int ans = 0;
	for(i=3; i>=0; i--) {
		ans = ans*10 + digits[i];
	}
	return ans;
}

void int_to_array(int d, int digits[]) {
	int i=0;
	while(d > 0) {
		digits[i++] = d % 10;
		d /= 10;
	}
	while (i<4) digits[i++] = 0;
}

bool isSame(int digits[]) {
	int d = digits[0];
	for (int i=1; i<4; i++) {
		if (digits[i] != d) return false;
	}
	return true;
}

int _1069() {
	int digits[4];
	int n;
	scanf("%d", &n);
	int_to_array(n, digits);
	if (isSame(digits)) {
		printf("%04d - %04d = 0000", n, n);
	} else {
		bool firstIn = true;
		do {
			if (firstIn) {
				firstIn = false;
			} else {
				printf("\n");
			}
			// sort in increasing order
			sort(digits, digits+4);
			int upper = array_to_int(digits);
			// sort in decreasing order
			sort(digits, digits+4, cmp);
			int lower = array_to_int(digits);
			n = upper-lower;
			int_to_array(n, digits);
			printf("%04d - %04d = %04d", upper, lower, n);
		} while(n != 6174);
	}
	return 0;
}