#include <cstdio>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

bool judgeCompatible(unordered_map<int, vector<int> > &adj, vector<int> &v) {
	unordered_set<int> vertices(v.begin(), v.end());
	for (int i=0; i<v.size(); i++) {
		int v1 = v[i];
		if (adj.count(v1)!=0) {
			for (int v2=0; v2<adj[v1].size(); v2++) {
				if (vertices.count(adj[v1][v2]) != 0) return false;
			}
		}
	}
	return true;
}

int _1149() {
	unordered_map<int, vector<int> > adj;
	int N, M;
	int v1, v2;
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
		scanf("%d%d", &v1, &v2);
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	for (int i=0; i<M; i++) {
		vector<int> v;
		int K, d;
		scanf("%d", &K);
		for (int j=0;j<K; j++) {
			scanf("%d", &d);
			v.push_back(d);
		}
		if (judgeCompatible(adj, v)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	//getchar();getchar();
	return 0;
}