#include <cstdio>
#include <cstring>



bool isBetween(char ch, char from, char to) {
	return ch >=from && ch <= to;
}

bool isLetter(char ch) {
	return ch >= 'a' && ch<='z' || ch >='A' && ch<='Z';
}

bool isCapitalLetter(char ch) {
	return ch >='A' && ch<='Z';
}

bool isNumber(char ch) {
	return ch >='0' && ch <='9';
}

int findCommon(char a[], char b[], int start, int end) {
	int i;
	for (i=start; i <= end; i++) {
		if (a[i]==b[i]) return i;
	}
	return -1;
}

int decodeHour(char ch) {
	if (isNumber(ch)) {
		return ch-'0';
	} else {
		return ch-'A'+10;
	}
}

char week[8][4] = {
	{""},{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"},{"SUN"}
};

int _1061() {
	char A[61], B[61];
	char a[61], b[61];

	scanf("%s", A);
	scanf("%s", B);
	scanf("%s", a);
	scanf("%s", b);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int end = lenA < lenB ? lenA-1 : lenB-1;
	int first = findCommon(A, B, 0, end);
	while(!isBetween(A[first], 'A','G')) {
		first = findCommon(A, B, first+1, end);
	}
	int second = findCommon(A, B, first+1, end);
	while((!isNumber(A[second])) && (!isBetween(A[second], 'A','N'))) {
		second = findCommon(A, B, second+1, end);
	}

	lenA = strlen(a);
	lenB = strlen(b);
	end = lenA < lenB ? lenA-1 : lenB-1;
	int third = findCommon(a, b, 0, end);
	while(!isLetter(a[third])) {
		third = findCommon(a, b, third+1, end);
	}
	int dayIndex = A[first]-'A'+1;
	int hour = decodeHour(A[second]);
	int minute = third;

	printf("%s %02d:%02d", week[dayIndex], hour, minute);
		
	return 0;
}