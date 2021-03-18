#include <stdio.h>

// 6 seconds to move up, 4 seconds to move down, 5 seconds stay
int _1008() {
	int n, i;
	int req[101];
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		scanf("%d", &req[i]);
	}

	int stop = 0;
	int cost = 0;
	for (i=0; i<n; i++) {
		if (req[i] > stop) {
			cost += 6*(req[i]-stop);
		} else if (req[i] < stop){
			cost += 4*(stop-req[i]);
		} else {
			// still stay at same floor?
		}
		cost += 5;
		stop = req[i];
	}
	printf("%d", cost);

	return 0;
}