#include <cstdio>
#include <string.h>
#include <math.h>

struct rationalNumber {
	long long numerator;
	long long denominator;
	rationalNumber(long long _n, long long _d) {
		numerator = _n;
		denominator = _d;
	}
};

typedef rationalNumber rationalnum;
typedef rationalNumber *rational;

void parse(char str[], long long &numerator, long long &denominator) {
	int len = strlen(str);
	int i=0;
	long long sign = 1;
	if (str[0] == '-') {
		i++;
		sign = -1;
	}
	numerator = 0;
	for (;i<len;i++) {
		if (str[i]!='/')
			numerator = numerator*10 + (str[i]-'0');
		else break;
	}
	numerator = numerator*sign;

	denominator = 0;
	for (i=i+1; i<len; i++) {
		denominator = denominator*10 + (str[i]-'0');
	}
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	if (a == 0) return b;
	if (a < b) return gcd(b-a, a);
	else return gcd(a-b, b);
}

// ans = ans + r
void add(rational ans, rational r) {
	long long n = ans->numerator * r->denominator + ans->denominator*r->numerator;
	long long d = ans->denominator * r->denominator;
	if (n==0) {
		ans->denominator = 1;
		ans->numerator = 0;
	} else {
		long long g = gcd( (n>0)?n:-n, d);
		ans->numerator = n/g;
		ans->denominator = d/g;
	}
}

int _1081() {
	rational ans = new rationalnum(0,1);// 0/1=0
	int n;
	char inputs[100];
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		scanf("%s", inputs);
		long long _n, _d;
		parse(inputs, _n, _d);
		rational r = new rationalnum(_n, _d);
		add(ans, r);
	}
	if (ans->numerator > 0) {
		if (ans->denominator ==1) printf("%lld", ans->numerator);
		else if (ans->denominator > ans->numerator) printf("%lld/%lld", ans->numerator, ans->denominator);
		else printf("%lld %lld/%lld", ans->numerator/ans->denominator, ans->numerator%ans->denominator, ans->denominator);
	} else if (ans->numerator < 0) {
		// what is interesting is that this case does not happen in PAT...T_T
	} else {
		printf("0");
	}

	return 0;
}