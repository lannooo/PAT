#include <stdio.h>
#include <string.h>

const char words[10][10] = {
	{"zero"},
	{"one"},
	{"two"},
	{"three"},
	{"four"},
	{"five"},
	{"six"},
	{"seven"},
	{"eight"},
	{"nine"}
};

void spell(int sum) {
	if (sum == 0) printf("zero");
	else {
		int digits[10];
		int count=0, i;
		while(sum > 0) {
			digits[count++] = sum % 10;
			sum /= 10;
		}
		for (i=count-1; i>=0; i--) {
			printf("%s", words[digits[i]]);
			if (i != 0) printf(" ");
		}
	}
}

int _1005(){
	char inputs[101];

	scanf("%s", inputs);

	int len = strlen(inputs);
	int i, sum = 0;
	for(i = 0; i<len; i++) {
		sum += (inputs[i]-'0');
	}
	spell(sum);

	return 0;
}