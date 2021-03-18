#include <cstdio>
#include <queue>
using namespace std;

int minPart, maxPart;
int D = 0;
int maxServers = 1;
void dfs_partition(priority_queue<int> pq) {
	int nowmax = pq.top();pq.pop();
	int temp = nowmax/2;
	if (!pq.empty() && temp*2 <= pq.top()) {
		int min;
		int cnt=1;
		while(!pq.empty()) {
			min = pq.top();pq.pop();
			cnt++;
		}
		if (cnt > maxServers) {
			maxServers = cnt;
			D = nowmax-min;
		} else if (cnt == maxServers) {
			if (nowmax-min < D) {
				D = nowmax-min;
			}
		}
		return;
	}
	
	while(pq.empty() || temp*2 > pq.top()) {
		int part1 = temp;
		int part2 = nowmax-temp;
		if (part1*2 <= part2) break;
		priority_queue<int> tempq = pq;
		tempq.push(part1);
		tempq.push(part2);
		dfs_partition(tempq);
		temp--;
	}
}

int _004() {
	int s;
	scanf("%d", &s);
	priority_queue<int> pq;
	pq.push(s);
	minPart = maxPart = s;
	dfs_partition(pq);
	printf("%d %d", maxServers, D);
	//getchar();getchar();
	return 0;
}