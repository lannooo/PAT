#include <cstdio>

struct rationalNumber {
	long long n;//numerator
	long long d;//denominator
	rationalNumber(long long _n, long long _d) {
		n = _n;
		d = _d;
	}
};

typedef rationalNumber rational;
typedef rationalNumber *rp;

long long abs(long long d) {
	return d < 0 ? (-d) : d;
}

long long gcd2(long long a, long long b) {
	return (!b)?a:gcd2(b, a%b);// In this way is fastest...
	//if (b == 0) return a;
	//if (b > a) return gcd2(b-a, a);
	//else return gcd2(a-b, b);
}

void simplize(rp r) {
	if (r->d == 0) {
		r->n = 0;
	} else {
		if (r->n == 0) r->d = 1;
		else {
			if (r->d < 0) {
				r->d = -r->d;
				r->n = -r->n;
			}
			long long g = gcd2(abs(r->n), abs(r->d));
			r->n = r->n/g;
			r->d = r->d/g;
		}
	}
}

rational add(rational r1, rational r2) {
	long long _d = r1.d * r2.d;
	long long _n = r1.n * r2.d + r1.d * r2.n;
	rational r3(_n, _d);
	simplize(&r3);
	return r3;
}

rational minus(rational r1, rational r2) {
	long long _d = r1.d * r2.d;
	long long _n = r1.n * r2.d - r1.d * r2.n;
	rational r3(_n, _d);
	simplize(&r3);
	return r3;
}

rational multiply(rational r1, rational r2) {
	long long _d = r1.d * r2.d;
	long long _n = r1.n * r2.n;
	rational r3(_n, _d);
	simplize(&r3);
	return r3;
}

rational divide(rational r1, rational r2) {
	long long _d = r1.d * r2.n;
	long long _n = r1.n * r2.d;
	if (_d < 0) {
		if (_n != 0) {
			_n = -_n;
			_d = -_d;
		} 
	} 
	rational r3(_n, _d);
	simplize(&r3);
	return r3;
}

void print_rational(rational r) {
	if (r.d == 0) printf("Inf");
	else if (r.n == 0) printf("0");
	else {
		bool isNeg = (r.n < 0);
		long long absn = isNeg?(-r.n):r.n;
		long long intpart = absn/r.d;
		if (isNeg) printf("(-");
		if (intpart != 0) printf("%lld", intpart);
		if ((absn%r.d) != 0) {
			if (intpart != 0) printf(" ");
			printf("%lld/%lld", absn%r.d, r.d);
		}
		if (isNeg) printf(")");
	}
}

void print_arithmetic(rational r1, char op, rational r2, rational res, bool moreLine) {
	print_rational(r1);
	printf(" %c ", op);
	print_rational(r2);
	printf(" = ");
	print_rational(res);
	if (moreLine) printf("\n");
}

int _1088() {
	long long n1, d1, n2, d2;
	scanf("%lld/%lld", &n1, &d1);
	scanf("%lld/%lld", &n2, &d2);
	rational r1(n1, d1), r2(n2, d2);
	simplize(&r1);
	simplize(&r2);
	print_arithmetic(r1, '+', r2, add(r1, r2), true);
	print_arithmetic(r1, '-', r2, minus(r1, r2), true);
	print_arithmetic(r1, '*', r2, multiply(r1, r2), true);
	print_arithmetic(r1, '/', r2, divide(r1, r2), false);
	//getchar();getchar();
	return 0;
}