#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string getNext(string str) {
	string origin(str);
	reverse(str.begin(), str.end());

	char * cp = new char[origin.length() + 2];
	int carry = 0;
	int index = 0;
	for(int i=origin.length()-1; i >=0; i--) {
		int sum = (str[i]-'0')+(origin[i]-'0') + carry;
		if (sum > 9) {
			carry = sum /10;
			sum = sum % 10;
		} else {
			carry = 0;
		}
		cp[index++] = sum+'0';
	}
	if (carry!=0) cp[index++] = carry + '0';
	reverse(cp, cp + index);
	cp[index] = 0;
	return string(cp);
}

bool isPalindromic(string str) {
	int len = str.length();
	if (len <= 1) return true;
	for(int i=0; i<len/2; i++) {
		if (str[i] != str[len-1-i]) return false;
	}
	return true;
}

int _1024() {
	string number;
	int k;
	cin >> number >> k;
	int i=0;
	while(!isPalindromic(number) && i < k) {
		number = getNext(number);
		i++;
	}

	cout<< number<<endl;
	cout<<i;

	return 0;
}