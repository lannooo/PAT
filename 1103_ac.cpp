#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int K, N;
int facPow[401] = {0};
vector<int> ans, tempans;
int maxFacSum = -1;

void dfs_fac(int facIndex, int tempK, int tempSum, int tempFacSum) {
	if (tempK == K) {
		if (tempSum == N && tempFacSum > maxFacSum) {
			maxFacSum = tempFacSum;
			ans = tempans;
		}
		return;
	}
	while(facIndex >= 1) {
		if(tempSum + facPow[facIndex] <= N) {
			tempans[tempK] = facIndex;
			dfs_fac(facIndex, tempK+1, tempSum+facPow[facIndex], tempFacSum+facIndex);
		}
		facIndex--;
	}
}

int initFacPowArr(int n, int p) {
	int index = 0;
	int temp;
	do {
		index++;
		temp = (int)pow((double)index, p);
		facPow[index]=temp;
	} while(temp <= n);
	return index;
}

int _1103() {
	int p;
	scanf("%d%d%d", &N,&K, &p);
	int maxindex = initFacPowArr(N, p);
	tempans.resize(K);
	dfs_fac(maxindex, 0, 0, 0);
	if(maxFacSum == -1) {
		printf("Impossible");
	} else {
		printf("%d =", N);
		for (int i=0; i<ans.size(); i++) {
			if (i!=0) printf(" +");
			printf(" %d^%d", ans[i], p);
		}
	}
	//getchar();getchar();
	return 0;
}