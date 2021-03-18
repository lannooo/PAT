#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


char mars1[13][5] = {
	{"tret"},
	{"jan"}, {"feb"}, {"mar"}, {"apr"}, {"may"}, {"jun"}, 
	{"jly"}, {"aug"}, {"sep"}, {"oct"}, {"nov"}, {"dec"}
};

char mars2[13][5] = {
	{""},
	{"tam"}, {"hel"}, {"maa"}, {"huh"}, {"tou"}, {"kes"}, 
	{"hei"}, {"elo"}, {"syy"}, {"lok"}, {"mer"}, {"jou"}
};

int marstonum(char str[]) {
	for(int i=1; i<=12; i++) {
		if (strcmp(str, mars1[i])==0) return i;
	}
	
	for(int i=1; i<=12; i++) {
		if (strcmp(str, mars2[i]) ==0) return i*13;
	}
	
	return 0;
}

int _1100() {
	int n;
	char buf[11];
	scanf("%d", &n);
	cin.get();
	for (int i=0; i<n; i++) {
		cin.getline(buf, 11);
		if(buf[0]>='0' && buf[0]<='9') { // Earth to Mars
			int num;
			sscanf(buf, "%d", &num);
			if (num > 12) {
				if (num % 13 != 0)
					printf("%s %s", mars2[num/13], mars1[num%13]);
				else
					printf("%s", mars2[num/13]);
			} else {
				printf("%s", mars1[num]);
			}
		} else { // Mars to earth
			char first[5];
			char second[5];
			if(strlen(buf)>4) {
				sscanf(buf, "%s %s", first, second);
				printf("%d",marstonum(first) + marstonum(second));
			} else {
				sscanf(buf, "%s", first);
				printf("%d",marstonum(first));
			}
		}
		if(i!=n-1) printf("\n");

	}

	return 0;
}