#include <cstdio>
#include <algorithm>
using namespace std;

int fmembers[100] = {0};
int fgen[100];

int generationOf(int i) {
	if (i == -1) return 0;
	if (fgen[i] != -1) return fgen[i];
	fgen[i] = 1 + generationOf(fmembers[i]);
	return fgen[i];
}

int _1094() {
	int n, m, k;
	fmembers[1] = -1;//1 is root
	fill(fgen, fgen+100, -1);// -1 means not calculated
	scanf("%d%d", &n, &m);
	int parent, child;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &parent, &k);
		for (int j=0; j<k; j++) {
			scanf("%d", &child);
			fmembers[child] = parent;
		}
	}
	int population[100];// population[i] means the numbers of generation-i
	fill(population, population+100, 0);
	for (int i=1; i<=n; i++) {
		population[generationOf(i)]++;
	}
	int max = population[1];
	int maxi = 1;
	for (int i=2; i<=n; i++) {
		if (population[i] > max) {
			max = population[i];
			maxi = i;
		}
	}
	printf("%d %d", max, maxi);
	//getchar();getchar();
	return 0;
}