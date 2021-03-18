#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct customer {
	int arrive;// arrive time, in seconds
	int cost;// need to process, in seconds
};

int toSeconds(int hour, int minute, int second) {
	return hour * 60 * 60 + minute * 60 + second;
}

const int OPEN_TIME = toSeconds(8,0,0);
const int CLOSE_TIME = toSeconds(17,0,1);

bool cmp(customer a, customer b) {
	return a.arrive < b.arrive;
}

int _1017() {
	int n, k;
	priority_queue<int, vector<int>, greater<int>> windows;
	vector<customer> vc;
	scanf("%d%d", &n, &k);
	for(int i=0; i<k; i++) {
		windows.push(OPEN_TIME);
	}
	for(int i=0; i<n; i++) {
		int h,m,s,p;
		customer c;
		scanf("%02d:%02d:%02d %d", &h, &m, &s, &p);
		c.arrive = toSeconds(h, m, s);
		c.cost = p*60;
		if(c.arrive < CLOSE_TIME)
			vc.push_back(c);
	}
	// sort with the arrive time increase
	sort(vc.begin(), vc.end(), cmp);
	long long totalwait = 0;
	int size = vc.size();
	for(int i=0; i<size; i++) {
		if(vc[i].arrive < OPEN_TIME) {
			totalwait += (OPEN_TIME-vc[i].arrive);
			vc[i].arrive = OPEN_TIME;
		}
		// check if service window available
		int nextTime = windows.top();
		windows.pop();
		if(nextTime <= vc[i].arrive) {
			// no need to wait, just arrive and take his turn
			nextTime = vc[i].arrive + vc[i].cost;
		} else {
			// arrive time is earlier than the most recent available window
			// need to wait a while
			totalwait += (nextTime-vc[i].arrive);
			nextTime += vc[i].cost;
		}
		windows.push(nextTime);// push-back to resort the priority queue
	}
	double average = 1.0 * totalwait / (60 * size);
	printf("%.1f", average);

	//getchar();getchar();

	return 0;
}