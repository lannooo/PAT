#include <cstdio>
#include <algorithm>
using namespace std;

const int NOT_CONNECTED = -1;
const int CONNECTED = 1;
const int VISITED = 1;
const int NOT_VISITED = 0;
const int OCCUPIED = -1;


int adj2[1010][1010];// connected or not-connected
int visit[1010]; // three status: visited, not-visited, occupied

void dfs_1013(int n, int city) {
	visit[city] = VISITED;
	for (int i=1; i<=n; i++) {
		if (adj2[city][i] == CONNECTED && visit[i] == NOT_VISITED) {
			dfs_1013(n, i);
		}
	}
}

int occupy(int n, int city) {
	fill(visit, visit+1010, NOT_VISITED);
	visit[city] = OCCUPIED;
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		if(visit[i] == NOT_VISITED) {
			dfs_1013(n, i);
			cnt++;
		}
	}
	return cnt-1;
}

int _1013() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) 
			adj2[i][j] = NOT_CONNECTED;
	}
	// read highways information
	int c1, c2;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &c1, &c2);
		adj2[c1][c2] = adj2[c2][c1] = CONNECTED;
	}
	int c;
	for (int i=0; i<k; i++) {
		scanf("%d", &c);
		// query if city c-th are occupied, how many highways need to be repaird
		printf("%d", occupy(n, c));
		if (i != k-1) printf("\n");
	}
	//getchar();getchar();

	return 0;
}