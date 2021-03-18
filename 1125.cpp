#include <cstdio>
#include <queue>
using namespace std;

int _1125() {
	priority_queue<float, vector<float>, greater<float>> pq;
	int n;
	float d;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%f", &d);
		pq.push(d);
	}
	while(pq.size() > 1) {
		float rope1 = pq.top();pq.pop();
		float rope2 = pq.top();pq.pop();
		pq.push((rope1+rope2)/2);
	}
	printf("%d", (int)pq.top());
	//getchar();getchar();
	return 0;
}