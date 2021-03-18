#include <cstdio>
#include <cstring>

const int MAX = 100000;
bool guessWinners[MAX] = {false};
char nicknames[1001][21];

int hash_1124(char buf[], int len) {
	int reallen = strlen(buf);
	if(reallen < len) len = reallen; 
	long long ans=0;
	for(int i=0; i<len; i++) {
		ans = ans * 127 + (int) buf[i];
	}
	return ans % MAX;
}

int _1124() {
	int total, skip, first;
	int winners = 0;
	scanf("%d %d %d", &total, &skip, &first);
	for(int i=1; i<=total; i++) {
		scanf("%s", nicknames[i]);
	}
	if (first > total) printf("Keep going...");
	else {
		for(int i=first; i<=total;) {
			int h = hash_1124(nicknames[i], 5);
			if(guessWinners[h]) {
				// already winner
				i++;
			}else {
				printf("%s\n", nicknames[i]);
				guessWinners[h] = true;
				i += skip;
			}
		}
	}
	//getchar();getchar();
	return 0;
}