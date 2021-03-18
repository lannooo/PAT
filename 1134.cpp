#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

bool isVertexCover(unordered_set<int> vertices, vector<int> adj[], int n) {
	for (int i=0; i<n; i++) {
		if (adj[i].empty()) continue;
		if (vertices.count(i) == 0) {
			for (int j=0; j<adj[i].size(); j++) {
				if (vertices.count(adj[i][j]) == 0) return false;
			}
		}
	}
	return true;
}
int _1134() {
	int N, M;
	vector<int> adj[10000];
	scanf("%d%d", &N, &M);
	for (int i=0; i<M; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int k, Nv, v;
	unordered_set<int> vertices;
	scanf("%d", &k);
	for (int i=0; i<k; i++ ) {
		scanf("%d", &Nv);
		for (int j=0; j< Nv;j++) {
			scanf("%d", &v);
			vertices.insert(v);
		}
		if (isVertexCover(vertices, adj, N)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		vertices.clear();
	}
	//getchar();getchar();
	return 0;
}