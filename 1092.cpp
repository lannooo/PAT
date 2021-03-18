#include <cstdio>
#include <cstring>

int hash2(char ch) {
	//0-9,a-z, A-Z is mapped to 0-9 10-35 36...
	if (ch >='0' && ch <= '9') return ch -'0';
	else if (ch >='a' && ch <= 'z') return ch -'a'+10;
	else if (ch >= 'A' && ch <= 'Z') return ch -'A'+36;
	else return -1;
}

int _1092() {
	char beadStr[1001];
	char needStr[1001];
	int beadsCount[80] = {0};
	int needsCount[80] = {0};

	scanf("%s %s", beadStr, needStr);

	int beadlen = strlen(beadStr);
	int needlen = strlen(needStr);

	for(int i=0; i<beadlen; i++) {
		beadsCount[hash2(beadStr[i])]++;
	}

	int miss = 0;
	for (int i=0; i<needlen; i++) {
		int h = hash2(needStr[i]);
		if (beadsCount[h] > 0) beadsCount[h]--;
		else {
			miss++;
		}
	}
	if (miss > 0) printf("No %d", miss);
	else printf("Yes %d", (beadlen - needlen));

	return 0;
}