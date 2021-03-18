#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

bool visit[10001] = {false};
int max_depth = 0;
void dfs_1021(vector<vector<int> > &adj, int start) {
	visit[start] = true;
	vector<int> v = adj[start];
	int size = v.size();
	for(int i=0; i<size; i++) {
		if (!visit[v[i]]) {
			dfs_1021(adj, v[i]);
		}
	}
}

void DFS_1021(set<int> &droots, int depth, vector<vector<int> > &adj, int now) {
	depth++;
	if (depth > max_depth){
		max_depth = depth;
		droots.clear();
		droots.insert(now);
	} else if (depth == max_depth) {
		droots.insert(now);
	}
	visit[now] = true;
	vector<int> v = adj[now];
	for(int i=0; i<v.size(); i++) {
		if (!visit[v[i]]) {
			DFS_1021(droots, depth, adj, v[i]);
		}
	}
}


int _1021() {
	int n;
	scanf("%d", &n);
	vector<vector<int> > adj(n+1);
	
	int from, to;
	for(int i=0; i<n-1; i++) {
		scanf("%d%d", &from, &to);
		if (from != to) {
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
	}
	// get components, if components is 1, it is a tree, else it is not connected
	//fill(visit+1, visit+n+1, false);
	int components = 0;
	for(int i=1; i<=n; i++){
		if (!visit[i]) {
			components++;
			dfs_1021(adj, i);
		}
	}
	// not a tree
	if (components > 1) {
		printf("Error: %d components", components);
		//getchar();getchar();
		return 0;
	}

	set<int> roots1;
	set<int> roots2;

	fill(visit+1, visit+n+1, false);
	DFS_1021(roots1, 0, adj, 1);
	fill(visit+1, visit+n+1, false);
	DFS_1021(roots2, 0, adj, *(roots1.begin()));
	roots1.insert(roots2.begin(), roots2.end());

	bool firstIn = true;
	for(set<int>::iterator it = roots1.begin(); it != roots1.end(); it++) {
		if (firstIn) {
			firstIn = false;
			printf("%d", *it);
		} else {
			printf("\n%d", *it);
		}
	}
	//getchar();getchar();
	return 0;
}