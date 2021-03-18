#include <cstdio>
#include <cstring>

struct BigNumber {
	int length;
	int digits[64];
	bool positive;
	BigNumber(){}
	BigNumber(char str[]) {
		length = strlen(str);
		if (str[0]=='-') {
			positive = false;
		} else {
			positive = true;
		}
		int i, count=0;
		int start = positive ? 0:1;
		for(i=length-1; i>=start; i--) 
			digits[count++] = str[i]-'0';
		if (!positive) length--;
	}
};

typedef struct BigNumber BiNum;

BiNum ZERO("0");

int cmpIntArray(int a[], int lenA, int b[], int lenB) {
	if (lenA < lenB) return -1;
	if (lenA > lenB) return 1;
	// lenA == lenB
	int i;
	for (i=lenA-1; i>= 0; i--) {
		if (a[i]>b[i]) return 1;
		if (a[i]<b[i]) return -1;
	}
	return 0;
}

int cmp(BiNum a, BiNum b) {
	if (a.positive) {// a is positive(+)
		if (!b.positive) return 1;//b is negtive(-)
		else return cmpIntArray(a.digits, a.length, b.digits, b.length);
	} else {
		if (b.positive) return -1;
		else return cmpIntArray(b.digits, b.length, a.digits, a.length);
	}
}

// be sure that a is bigger than b
int minus(int a[], int lenA, int b[], int lenB, int c[]){
	int i;
	for(i=lenB; i<lenA; i++) b[i] = 0;//add '0' to high position
	for (i=0; i<lenA; i++) c[i] = a[i];//copy a to c
	for(i=0; i<lenA; i++) {
		if (c[i]<b[i]) {
			c[i+1]--;
			c[i] = 10+c[i]-b[i];
		} else {
			c[i] = c[i]-b[i];
		}
	}
	while (c[i-1]==0 && i>1) i--;
	return i;
}

int add(int a[], int lenA, int b[], int lenB, int c[]) {
	int carry=0;
	int i;
	for (i=0; i<lenA && i<lenB; i++) {
		c[i] = a[i]+b[i]+carry;
		if (c[i] > 9) {
			carry = c[i]/10;
			c[i] = c[i] % 10;
		} else {
			carry = 0;
		}
	}
	
	for(;i<lenA;i++) {
		c[i]=a[i]+carry;
		if (c[i] > 9) {
			carry = c[i]/10;
			c[i] = c[i] % 10;
		} else {
			carry = 0;
		}
	}
	
	for(;i<lenB;i++) {
		c[i]=b[i]+carry;
		if (c[i] > 9) {
			carry = c[i]/10;
			c[i] = c[i] % 10;
		} else {
			carry = 0;
		}
	}
	
	if(carry != 0) c[i++] = carry;
	return i;
}

BiNum add(BiNum a, BiNum b) {
	BiNum c;
	// a+ b+ or a- b-
	if (a.positive && b.positive || !a.positive && !b.positive) {
		c.length = add(a.digits, a.length, b.digits, b.length, c.digits);
		c.positive = a.positive;
	} else { // a- b+ or a+ b-
		int sign = cmpIntArray(a.digits, a.length, b.digits, b.length);
		if (sign==0) return ZERO;// same value of abs(a) and abs(b)
		else if(sign > 0) { // value abs(a) is bigger than abs(b)
			c.length = minus(a.digits, a.length, b.digits, b.length, c.digits);
			c.positive = a.positive;
		} else {
			c.length = minus(b.digits, b.length, a.digits, a.length, c.digits);
			c.positive = b.positive;
		}
	}
	return c;
}

int _1065() {
	int t;
	scanf("%d", &t);
	int i;
	char str1[100], str2[100], str3[100];
	for(i=1; i<=t; i++) {
		scanf("%s %s %s", str1, str2, str3);
		BiNum a(str1);
		BiNum b(str2);
		BiNum c(str3);
		if (cmp(add(a, b), c) > 0) printf("Case #%d: true", i);
		else printf("Case #%d: false", i);
		if (i!=t) printf("\n");
	}
	return 0;
}