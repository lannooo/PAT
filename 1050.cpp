#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int _1050() {
	bool deletes[260] = {false};
	char s1[10001], s2[10001];
	char ans[10001];
	// The second parameter need be greater than the real string length by 1,
	// to give space to end-mark '\0' 
	cin.getline(s1, 10001);
	cin.getline(s2, 10001);
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);

	int i;
	for (i = 0; i<len_s2; i++) {
		deletes[s2[i]] = true;
	}
	int count = 0;
	for(i=0; i<len_s1; i++) {
		if (!deletes[s1[i]]) {
			ans[count++] = s1[i];
		}
	}
	ans[count++] = 0;
	printf("%s", ans);
	getchar();getchar();
	return 0;
}