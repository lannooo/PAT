#include <cstdio>
#include <cstring>

char format(char ch) {
	if (ch >='a' && ch<='z') return 'A'+ (ch-'a');
	return ch;
}

int hash(char ch) {
	return format(ch);
}

int _1084() {
	char origin[81];
	char typed[81];
	bool printed[256] = {false};
	scanf("%s", origin);
	scanf("%s", typed);
	int origin_len = strlen(origin);
	int typed_len = strlen(typed);
	int i=0,j=0;
	while(i<origin_len && j <typed_len) {
		if (origin[i] != typed[j]) {
			int h = hash(origin[i]);
			if (!printed[h]) {
				printf("%c", format(origin[i]));
				printed[h] = true;
			}
			i++;
		} else {
			i++;
			j++;
		}
	}
	// tail characters of origin string
	while(i<origin_len) {
		int h = hash(origin[i]);
		if (!printed[h]) {
			printf("%c", format(origin[i]));
			printed[h] = true;
		}
		i++;
	}

	return 0;
}