#include <cstdio>
#include <cstring>

int _1073() {
	char notation[10000] = {0};
	char fraction[10000] = {0};
	scanf("%s", notation);
	int len = strlen(notation);
	
	// get different part of the scientific notation number
	bool positive = (notation[0] == '+');
	int integerPortion = notation[1]-'0';
	int i;
	for (i=3; i<len; i++) {
		if (notation[i]!='E')
			fraction[i-3] = notation[i];
		else break;
	}
	bool expPositive = (notation[++i]=='+');

	int exp=0;
	for (i=i+1; i<len; i++) {
		exp = exp*10 + (notation[i]-'0');
	}

	// print its conventional expression
	if (!positive) printf("-");
	if (exp == 0) {
		printf("%d.%s", integerPortion, fraction);
	} else {
		if (!expPositive){
			printf("0.");
			for (int j=1; j<exp; j++) printf("0");
			printf("%d%s",integerPortion, fraction);
		} else {
			printf("%d", integerPortion);
			int flen = strlen(fraction);
			if (exp < flen) {
				int j;
				for (j=0; j<exp; j++) printf("%c", fraction[j]);
				printf(".");
				printf("%s", fraction+j);
			} else {
				printf("%s", fraction);
				for (int j=0; j<exp-flen; j++) printf("0");
			}
		}
	}

	return 0;
}