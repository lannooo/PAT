#include <cstdio>
#include <cstring>

bool isNumber2(char ch){
	return ch >= '0' && ch <='9';
}

bool parseRealNumber(char buf[], double &number) {
	int len = strlen(buf);
	bool isPositive = true;
	bool isIntPart = true;
	//bool firstintpart = true;
	int intpart = 0;
	int decimal = 0;
	int decimalpart = 0;
	for (int i=0; i<len; i++) {
		if(i==0 && !isNumber2(buf[0])) {
			if(buf[0] != '-') return false;
			isPositive = false;
			continue;
		}
		if (isIntPart) {
			if (buf[i]=='.') isIntPart = false;
			//else if(buf[i]=='0' && firstintpart) return false;
			else if(buf[i]>='0' && buf[i]<='9') {
				intpart = intpart * 10 + (buf[i]-'0');
			}
			else return false;
		} else {
			if (buf[i]>='0' && buf[i]<='9' && decimalpart<2){
				decimal = decimal * 10 + (buf[i]-'0');
				decimalpart++;
			} else { 
				return false;
			}
		}
	}
	if (decimalpart == 0) number = (double)intpart;
	else if (decimalpart == 1) number = ((double)intpart) + decimal /10.0;
	else if (decimalpart == 2) number = ((double)intpart) + decimal /100.0;

	if (!isPositive) number = -number;
	if (number<-1000.0 || number > 1000.0) return false;
	return true;
}

int _1108() {
	char buf[100];
	int n;
	scanf("%d", &n);
	double sum=0, p;
	int count=0;
	for (int i=0; i<n; i++) {
		scanf("%s", buf);
		if (parseRealNumber(buf, p)) {
			sum += p;
			count++;
		} else {
			printf("ERROR: %s is not a legal number\n", buf);
		}
	}
	if (count==0)
		printf("The average of 0 numbers is Undefined");
	else if (count == 1)
		printf("The average of 1 number is %.2f", sum);
	else 
		printf("The average of %d numbers is %.2f", count, sum/count);
	//getchar();getchar();
	return 0;
}