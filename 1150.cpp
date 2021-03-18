#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 10000000;
const int MAXV = 201;
int G[MAXV][MAXV];
int visit_cnt[MAXV];

int minSolution;
int minDist=INF;
void updateBestSolution(int x, int dist) {
	if (dist < minDist) {
		minDist = dist;
		minSolution = x;
	}
}

void answerSolution(vector<int> v, int N, int x) {
	if (v.size() <= 1) {
		printf("Path %d: NA (Not a TS cycle)\n", x);
		return;
	}
	fill(visit_cnt, visit_cnt+MAXV, 0);
	int now = v[0], next;
	int path = 0;
	visit_cnt[now]++;
	for (int i=1; i<v.size()-1; i++) {
		next = v[i];
		if (G[now][next] != INF) {
			path += G[now][next];
			visit_cnt[next]++;
		} else {
			printf("Path %d: NA (Not a TS cycle)\n", x);
			return;
		}
		now = next;
	}
	now = next;
	next = v[v.size()-1];
	if (G[now][next] == INF) {
		printf("Path %d: NA (Not a TS cycle)\n", x);
		return;
	}
	path += G[now][next];
	if (next == v[0]) {
		// test if it is a simple ts or not simple
		int min=INF, max=0;
		for (int i=1; i<=N; i++) {
			if (visit_cnt[i] < min) min = visit_cnt[i];
			if (visit_cnt[i] > max) max = visit_cnt[i];
		}
		if (min == max && min == 1) {
			printf("Path %d: %d (TS simple cycle)\n", x, path);
			updateBestSolution(x, path);
		} else if (min == max && min > 1) {
			printf("Path %d: %d (TS cycle)\n", x, path);
			updateBestSolution(x, path);
		} else if (min != max && min >= 1) {
			printf("Path %d: %d (TS cycle)\n", x, path);
			updateBestSolution(x, path);
		} else {
			printf("Path %d: %d (Not a TS cycle)\n", x, path);
		}
	} else {
		printf("Path %d: %d (Not a TS cycle)\n", x, path);
	}
}

int _1150() {
	fill(G[0], G[0]+MAXV*MAXV, INF);
	int N, M, K;
	scanf("%d%d", &N, &M);
	int c1, c2, dist;
	for (int i=0; i<M; i++) {
		scanf("%d%d%d", &c1, &c2, &dist);
		G[c1][c2] = G[c2][c1] = dist;
	}
	scanf("%d", &K);
	int n, c;
	for(int i=1; i<=K; i++) {
		scanf("%d", &n);
		vector<int> v(n);
		for (int j=0;j<n;j++) {
			scanf("%d", &c);
			v[j] = c;
		}
		answerSolution(v, N, i);
	}
	// best solution
	printf("Shortest Dist(%d) = %d", minSolution, minDist);
	//getchar();getchar();
	return 0;
}