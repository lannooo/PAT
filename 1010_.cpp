#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

long long changebyradix(string str, long long radix) {
	int length = str.length();
	long long ans = 0;
	for (int i=0; i<length; i++) {
		if(str[i]>='0' && str[i] <='9') ans = ans * radix + (str[i] - '0');
		else ans = ans * radix + (str[i]-'a'+10);
		// test whether ans overflow, if did, return -1 immediately
		if (ans < 0) return -1;
	}
	return ans;
}

long long findMinRadix(string str) {
	int r = 1;
	int size = str.length();
	for (int i=0; i<size; i++) {
		int rc;
		if(str[i]>='0' && str[i] <='9') rc = str[i]-'0';
		else rc = str[i]-'a'+10;
		if (rc > r) r = rc;
	}
	return r+1;
}

int _1010() {
	
	string n1, n2, other;
	int tag;
	long long radix;
	cin >> n1 >> n2 >> tag >> radix;
	long long v, vo;
	long long lr, hr, r;
	if (tag == 1){
		v = changebyradix(n1, radix);
		other = n2;
	} else {
		v = changebyradix(n2, radix);
		other = n1;
	}
	lr = findMinRadix(other);
	hr = v > lr ? v : lr;
	while(lr <= hr) {
		r = (lr + hr)/2;
		vo = changebyradix(other, r);
		if (vo == v) {
			break;
		} else if(vo > v||vo < 0) { //radix is too big, the vo can be overflow
			hr = r-1;
		} else {
			lr = r+1;
		}
	}
	
	if (lr > hr) printf("Impossible");
	else printf("%lld", r);
	//getchar();getchar();
	return 0;
}