#include <cstdio>

char best_bet(float odds[], float &best) {
	int i, bestIndex=0;
	best = odds[0];
	for (i=1; i<3; i++) {
		if (odds[i]>best) {
			best = odds[i];
			bestIndex = i;
		}
	}
	if (bestIndex==0) return 'W';
	if (bestIndex==1) return 'T';
	if (bestIndex==2) return 'L';
}

int _1011() {
	int i;
	float odds[3][3];
	char bets[3];
	float bestOdd;
	float ans = 1;
	for (i=0; i<3; i++) scanf("%f %f %f", &odds[i][0], &odds[i][1], &odds[i][2]);
	for (i=0; i<3; i++) {
		char c = best_bet(odds[i], bestOdd);
		ans *= bestOdd;
		printf("%c ", c);
	}
	ans = (ans * 65 / 100 - 1) * 2;
	printf("%.2f", ans);

	return 0;
}