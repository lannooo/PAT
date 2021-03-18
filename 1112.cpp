#include <cstdio>
#include <cstring>

bool maystucked[128];
bool hasprinted[128];

int _1112() {
	for(int i=0; i<128; i++) {
		maystucked[i] = true;
		hasprinted[i] = false;
	}
	int k;
	char buf[1001];
	scanf("%d", &k);
	scanf("%s", buf);
	int len = strlen(buf);
	// check which characters are not possible to be stucked
	char last = buf[0];
	int count = 1;
	for(int i=1; i<len; i++) {
		if (buf[i] != last) {
			if(count % k != 0) {
				maystucked[last] = false;
			}
			last = buf[i];
			count = 1;
		} else {
			count++;
		}
	}
	if (count%k != 0) maystucked[last] = false;
	// build origin string and print stucked keys
	char origin[1001];
	int index = 0;
	for(int i=0; i<len;) {
		if(maystucked[buf[i]]) {
			if(!hasprinted[buf[i]]) {
				printf("%c", buf[i]);
				hasprinted[buf[i]] = true;
			}
			origin[index++] = buf[i];
			i+=k;
		} else {
			origin[index++] = buf[i];
			i++;
		}
	}
	origin[index++] = 0;
	printf("\n%s", origin);

	//getchar();getchar();

	return 0;
}