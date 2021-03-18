#include <stdio.h>
#include <math.h>

void print_format(int num, bool positive) {
	int prints[5];
	int count = 0, i;
	while(num > 0) {
		prints[count++] = num % 1000;
		num /= 1000;
	}
	if (!positive) printf("-");
	for (i=count-1; i>=0; i--) {
		if (i != count-1 && prints[i] <= 99)
			printf("%03d", prints[i]);
		else
			printf("%d", prints[i]);
		if (i != 0) printf(",");
	}
}

int _1001(){
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = a+b;

	if (sum == 0) printf("0");
	else {
		bool positive = sum > 0 ? true : false;
		print_format(abs(sum), positive);
	}
	getchar();getchar();
	return 0;
}