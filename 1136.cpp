#include <cstdio>
#include <cstring>

void copy_palin(int a[], int c[], int len) {
	for (int i=0; i<len; i++) {
		a[i] = c[i];
	}
}

void reverse_palin(int a[], int b[], int len) {
	int j=0;
	for(int i=len-1; i>=0; i--) {
		b[j++] = a[i];
	}
}

int add_palin(int a[], int b[], int len, int c[]) {
	int carry = 0;
	int i;
	for (i=0; i<len; i++) {
		c[i] = a[i]+b[i]+carry;
		carry = 0;
		if (c[i] > 9) {
			carry = c[i]/10;
			c[i] = c[i] % 10;
		}
	}
	if (carry != 0) {
		c[i] = carry;
		return len+1;
	} else {
		return len;
	}
}

bool palindromic(int c[], int len) {
	for (int i=0; i<len/2; i++) {
		if (c[i] != c[len-i-1]) return false;
	}
	return true;
}

void print_single_palin(int n[], int len) {
	for(int i=len-1;i>=0; i--)
		printf("%d", n[i]);
}

void print_result_palin(int c[], int clen) {
	print_single_palin(c, clen);
	printf(" is a palindromic number.");
}

void print_step_palin(int a[], int b[], int len, int c[], int clen) {
	print_single_palin(a, len);
	printf(" + ");
	print_single_palin(b, len);
	printf(" = ");
	print_single_palin(c, clen);
	printf("\n");
}

int _1136() {
	int a[1020], b[1020], c[1020];
	char buf[1001];
	scanf("%s", buf);
	int len = strlen(buf);
	int index=0;
	for(int i=len-1; i>=0; i--) {
		a[index++]=buf[i]-'0';
	}
	if(palindromic(a, len)) {
		print_result_palin(a, len);
		//getchar();getchar();
		return 0;
	}
	int clen;
	int itertimes=0;
	do {
		reverse_palin(a, b, len);
		clen = add_palin(a, b, len, c);
		print_step_palin(a, b, len, c, clen);
		if (palindromic(c, clen)) {
			print_result_palin(c, clen);
			break;
		} else {
			copy_palin(a, c, clen);
			len = clen;
		}
		itertimes++;
	} while (itertimes < 10);
	if(itertimes >= 10) 
		printf("Not found in 10 iterations.");
	//getchar();getchar();

	return 0;
}