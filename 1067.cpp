#include <cstdio>

int pos[100000];
bool visit[100000] = {false};
/*
This process of swap(0, *) is like to visit all the nodes in linked lists. 
once a node is visited, it is swapped to its right place.
*/
int _1067(){
	int n,d;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &d);
		pos[d] = i;
	}
	int cnt = 0;
	for(int i=0; i<n; i++) {
		// already visited, number i is in its right place
		if (visit[i]) continue;
		// number i should be swapped
		if (pos[i] != i) {
			int stop = 0;
			int next = pos[i];
			if (i != 0) {
				stop = pos[i];
				cnt++;
			}
			do{
				visit[next] = true;
				next = pos[next];
				cnt++;
			} while(next != stop);
	
		} else {
			visit[i] = true;
		}
	}
	printf("%d", cnt);
	//getchar();getchar();
	return 0;
}