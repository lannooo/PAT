#include <cstdio>
#include <cstring>

int _1023() {
	char str[25];//store input number string
	int digits[25];// translate to digits
	int len1, len2;// mark digits number
	int counts[10] = {0};// count for 0-9

	scanf("%s", str);
	len1 = len2 = strlen(str);

	int i,j;
	for(i=len1-1, j=0; i>=0; i--,j++) {
		digits[j] = str[i]-'0';
		counts[digits[j]]++;
	}

	// double it
	int carry = 0;
	int temp;
	for (i=0; i<len1; i++) {
		temp = digits[i] * 2 + carry;
		if (temp >= 10) {
			digits[i]=temp%10;
			carry = temp/10;
		} else {
			digits[i] = temp;
			carry = 0;
		}
	}
	if (carry != 0) {
		digits[i] = carry;
		len2++;
	}

	for(i=0; i<len2; i++) {
		counts[digits[i]]--;
	}

	bool ans = true;
	for(i=0; i < 10; i++) {
		if (counts[i]!=0){
			ans = false;
			break;
		}
	}
	if (ans) printf("Yes\n");
	else printf("No\n");
	for (i=len2-1;i>=0;i--) {
		printf("%d", digits[i]);
	}

	return 0;
}