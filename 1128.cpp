#include <cstdio>
#include <cmath>
using namespace std;

bool isThreaten(int row1, int col1, int row2, int col2) {
	if (row1 == row2) return true;
	if (abs(row1-row2) == abs(col1-col2)) return true;
	return false;
}

bool judge(int n, int config[]) {
	// start from col2, to compare with col1
	for (int col=2; col<=n; col++) {
		int row = config[col];
		for(int i=1; i<col; i++) {
			int j = config[i];
			if(isThreaten(row, col, j, i)) return false;
		}
	}
	return true;
}

int _1128() {
	int k;
	int config[1001];
	scanf("%d", &k);
	for (int i=0; i<k; i++) {
		int n;
		scanf("%d", &n);
		for(int j=1; j<=n; j++) {
			scanf("%d", &config[j]);
		}
		if(judge(n, config)) printf("YES\n");
		else printf("NO\n");
	}
	//getchar();getchar();
	return 0;
}