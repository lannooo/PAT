#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void dfs_1126(vector<int> adj[], bool visit[], int now) {
	visit[now] = true;
	int size = adj[now].size();
	for (int i=0; i<size; i++) {
		if (visit[adj[now][i]] == false) {
			dfs_1126(adj, visit, adj[now][i]);
		}
	}
}

bool testConnect(vector<int> adj[], int n) {
	bool visit[501] = {false};
	dfs_1126(adj, visit, 1);
	for (int i=1; i<=n; i++) {
		if (visit[i] == false) return false;
	}
	return true;
}

int _1126() {
	int n,m;
	int degree[501] = {0};
	vector<int> adj[501];
	scanf("%d%d", &n, &m);
	int v1, v2;
	for (int i=0; i<m; i++) {
		scanf("%d%d", &v1, &v2);
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
		degree[v1]++;
		degree[v2]++;
	}
	bool isConnected = testConnect(adj, n);
	int odds = 0;
	for (int i=1; i<=n; i++) {
		if (i!=1) printf(" %d", degree[i]);
		else printf("%d", degree[i]);
		if (degree[i] % 2 != 0) odds++;
	}
	printf("\n");
	if (!isConnected) {
		printf("Non-Eulerian");
	}else{
		if (odds == 2) printf("Semi-Eulerian");
		else if (odds == 0) printf("Eulerian");
		else printf("Non-Eulerian");
	}
	//getchar();getchar();
	return 0;
}