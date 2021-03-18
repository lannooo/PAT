#include <cstdio>
#include <algorithm>
using namespace std;

const int NO_PATH = (1<<30)-1;
int teams[500] = {0};
int adj[500][500] = {0};

int maxhands = 0;
int shortestlength = NO_PATH;// a very big number to mark un-reachable
int shortestpathcount = 0;

bool visited[500] = {false};
int n = 0, m = 0, c1=0, c2=0;

// use dfs to find all the possible paths and compare to find the best paths
void dfs_1003(int city, int dest, int lengthsum, int handssum){
	if(city == dest) {
		if (lengthsum < shortestlength) { // a more quick path
			maxhands = handssum;
			shortestlength = lengthsum;
			shortestpathcount = 1;
		} else if (lengthsum == shortestlength) {
			shortestpathcount++;
			if (handssum > maxhands) maxhands = handssum;
		}
		// do some common work
		return;
	}
	// recurse here
	for (int i=0; i<n; i++) {
		if (!visited[i] && adj[city][i] != NO_PATH) {
			visited[i] = true;
			dfs_1003(i, dest, lengthsum+adj[city][i], handssum+teams[i]);
			visited[i] = false;
		}
	}
}

int _1003() {
	// read all the info of cities and roads
	scanf("%d%d%d%d", &n,&m,&c1,&c2);
	for (int i=0; i<n; i++) {
		scanf("%d", &teams[i]);	
		fill(adj[i], adj[i]+n, NO_PATH);
		adj[i][i] = 0;
	}
	int from, to, length;
	for (int i=0; i<m; i++) {
		scanf("%d%d%d", &from, &to, &length);
		adj[from][to] = adj[to][from] = length;
	}
	visited[c1] = true;
	dfs_1003(c1, c2, 0, teams[c1]);
	printf("%d %d", shortestpathcount, maxhands);
	//getchar();getchar();
	return 0;
}