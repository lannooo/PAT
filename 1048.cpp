#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int coincnt[1001] = {0};

int _1048() {
	int n, m, c;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++) {
		scanf("%d", &c);
		coincnt[c]++;
	}
	int v1, v2;
	bool found=false;

	for (v1=1; v1 <= m/2; v1++) {
		if (coincnt[v1] > 0) {
			coincnt[v1]--;// take v1-face coin
			if (coincnt[m-v1] > 0) {
				found = true;
				v2 = m-v1;
				break;
			} else {
				coincnt[v1]++;
			}
		}
	}

	
	if (found) {
		printf("%d %d", v1, v2);
	} else {
		printf("No Solution");
	}
	//getchar();getchar();
	return 0;
}