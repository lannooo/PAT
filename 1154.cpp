#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coloradj[10000];
bool colorvisit[10000];

int coloring(vector<int> seq, int n) {
	unordered_set<int> colors;
	for (int v1 = 0; v1 < n; v1++) {
		int c = seq[v1]; // color of vertex-i
		colors.insert(c);
		for (int j=0; j<coloradj[v1].size(); j++) {
			int v2 = coloradj[v1][j];
			if (seq[v2] == c) return -1; // same color return result early
		}
	}
	return colors.size();
}

int _1154() {
	int N, M;
	int v1, v2;
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d%d", &v1, &v2);
		coloradj[v1].push_back(v2);
		coloradj[v2].push_back(v1);
	}
	int K, d;
	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		vector<int> v;
		for (int j=0; j<N; j++) {
			scanf("%d", &d);
			v.push_back(d);
		}
		int colors = coloring(v, N);
		if (colors == -1) {
			printf("No\n");
		} else {
			printf("%d-coloring\n", colors);
		}
	}
	//getchar();getchar();
	return 0;
}