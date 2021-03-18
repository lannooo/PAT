#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

bool isSymmetric(char str[], int begin ,int end) {
	int n = begin + end;
	int mid = n / 2;
	for (int i=begin; i<= mid; i++) {
		if (str[i] != str[n-i]) return false;
	}
	return true;
}

int _1040() {
	char buf[1010];
	cin.getline(buf, 1010);
	int length = strlen(buf);
	bool found = false;
	int max = 1;
	for (int range = length; range > 1; range--) {
		for (int from = 0; from + range <= length; from ++) {
			if (isSymmetric(buf, from, from+range-1)) {
				max = range;
				found = true;
				break;
			}
		}
		if (found) break;
	}
	if (found) printf("%d", max);
	else printf("1");
	//getchar();
	return 0;
}