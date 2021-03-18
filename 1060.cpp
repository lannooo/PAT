#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void trim(string &str) {
	while(str.size() > 1 && str[0] == '0') str.erase(str.begin());
}

int getZero(char sig[], int n) {
	int index = 0;
	while (index < n) sig[index++] = '0';
	sig[index] = 0;
	return 0;
}

int parseK(string str, char sig[], int n) {
	if (str == "0") {
		return getZero(sig, n);
	}
	if (str[0] == '.') { // number like '.000xxx' 
		int cnt = 0;
		str.erase(str.begin()); // remove '.'
		while (str.size() > 0 && str[0] == '0') {//translate to xxx
			cnt--;
			str.erase(str.begin());
		}
		if (str.length() == 0) return getZero(sig, n); // original str is like '.0000'
		int i = 0;
		// copy 'xxx' to sig , if not enough, append more '0' at the end 
		while(i < n && i < str.length()) { 
			sig[i] = str[i];
			i++;
		}
		while(i < n) sig[i++] = '0';
		sig[i] = 0;
		return cnt;
	} else { // number like 'xxx.xx'
		int cnt = 0;
		while(cnt < str.length() && str[cnt] != '.') cnt++;
		if (cnt < str.length()) {
			str.erase(str.begin()+cnt);//remove '.'
		}
		int i=0;
		while(i<n && i<str.length()) {
			sig[i] = str[i];
			i++;
		}
		while(i<n) sig[i++] = '0';
		sig[i] = 0;
		return cnt;
	}
}

int _1060(){
	string a, b;
	int n;
	cin >> n >> a >> b;
	// remove the zero before '.' or other digit
	trim(a);
	trim(b);
	// if it is smaller than 1, start with '.'
	char siga[101], sigb[101];
	int ka = parseK(a, siga, n);
	int kb = parseK(b, sigb, n);
	if (ka == kb && string(siga) == string(sigb)) {
		printf("YES 0.%s*10^%d", siga, ka);
	} else {
		printf("NO 0.%s*10^%d 0.%s*10^%d", siga, ka, sigb, kb);
	}

	//getchar();getchar();
	return 0;
}