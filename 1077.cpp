#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int _1077() {
	char spokenlines[100][300];
	int length[100];
	int minlen = 999;
	int n;
	cin >> n;
	cin.get();

	for (int i=0; i<n; i++) {
		cin.getline(spokenlines[i], 300);
		length[i] = strlen(spokenlines[i]);
		if (minlen>length[i]) minlen = length[i];
	}
	// look from line[len-1] to line[0] to find Kuchiguse
	int sameCount=0;
	for (int i=1; i<=minlen; i++) {
		char ch = spokenlines[0][length[0]-i];
		bool diff = false;
		for (int j=1; j<n; j++) {
			if (spokenlines[j][length[j]-i] != ch) {
				diff = true;
				break;
			}
		}
		if (diff) {
			break;
		} else {
			sameCount++;
		}
	}

	if(sameCount==0) printf("nai");
	else {
		printf("%s", spokenlines[0] + (length[0]-sameCount));
	}

	return 0;
}