#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct mapnode{
	int index;
	int length;
	int time;
	mapnode(){}
	mapnode(int _index, int _length, int _time):index(_index),length(_length),time(_time){}
};

const int MAX_N = 500;
const int INF = 10000000;
vector<mapnode> mapadj[MAX_N];
int d[MAX_N];//min distance from source to i
int t[MAX_N];//min time from source to i
int cnt[MAX_N];//min count of intersection
bool visit[MAX_N];
int path_d[MAX_N]; // min path to i
int path_t[MAX_N];

void dijkstra_time(int source, int n) {
	fill(visit, visit+MAX_N, false);
	fill(t, t+MAX_N, INF);
	fill(cnt, cnt+MAX_N, INF);
	t[source] = 0;
	cnt[source] = 1;
	path_t[source] = -1;
	for (int i=0; i<n; i++) {
		int minTime = INF;
		int minIndex = -1;
		for (int j=0; j<n; j++) {
			if (!visit[j] && t[j] < minTime) {
				minTime = t[j];
				minIndex = j;
			}
		}
		visit[minIndex] = true;
		for(int j=0; j<mapadj[minIndex].size(); j++){
			mapnode node = mapadj[minIndex][j];
			if (t[minIndex]+node.time < t[node.index]) {
				t[node.index] = t[minIndex]+node.time;
				cnt[node.index] = cnt[minIndex]+1;
				path_t[node.index] = minIndex;
			} else if (t[minIndex]+node.time == t[node.index]) {
				if (cnt[minIndex]+1 < cnt[node.index]) {
					cnt[node.index] = cnt[minIndex]+1;
					path_t[node.index] = minIndex;
				}
			}
		}
	}
}

void dijkstra_dist(int source, int n) {
	fill(visit, visit+MAX_N, false);
	fill(d, d+MAX_N, INF);
	fill(t, t+MAX_N, INF);
	d[source] = 0;
	t[source] = 0;
	path_d[source] = -1;
	for (int i=0; i<n; i++) { // repeat n times
		int minDist = INF;
		int minIndex= -1;
		for (int j=0; j<n; j++) {
			if (!visit[j] && d[j] < minDist) {
				minDist = d[j];
				minIndex = j;
			}
		}
		visit[minIndex] = true;
		for(int j=0; j<mapadj[minIndex].size(); j++) {
			mapnode node = mapadj[minIndex][j];
			if (d[minIndex]+node.length < d[node.index]) {
				d[node.index] = d[minIndex]+node.length;
				t[node.index] = t[minIndex]+node.time;
				path_d[node.index]=minIndex;
			} else if (d[minIndex]+node.length == d[node.index]) {
				if(t[minIndex]+node.time < t[node.index]){
					t[node.index] = t[minIndex]+node.time;
					path_d[node.index]=minIndex;
				}
			}
		}
	}
}

void getPath(vector<int> &path, int p[], int destination) {
	if (p[destination]==-1) { // it is source
		path.push_back(destination);
		return;
	}
	getPath(path, p, p[destination]);
	path.push_back(destination);
}

int _1111() {
	int n, m;
	scanf("%d%d", &n, &m);
	int v1, v2, oneway, length, time;
	for (int i=0; i<m; i++) {
		scanf("%d%d%d%d%d", &v1, &v2, &oneway, &length, &time);
		mapnode node = mapnode(v2, length, time);
		mapadj[v1].push_back(node);
		if (oneway == 0){
			node.index = v1;
			mapadj[v2].push_back(node);
		}
	}
	int source, destination;
	vector<int> paths1, paths2;
	scanf("%d%d", &source, &destination);

	dijkstra_dist(source, n);
	getPath(paths1, path_d, destination);
	dijkstra_time(source, n);
	getPath(paths2, path_t, destination);

	if (paths1 != paths2) {
		printf("Distance = %d:", d[destination]);
		for (int i=0; i<paths1.size(); i++) {
			if (i != 0) printf(" ->");
			printf(" %d", paths1[i]);
		}
		printf("\n");
		printf("Time = %d:", t[destination]);
		for (int i=0; i<paths2.size(); i++) {
			if (i != 0) printf(" ->");
			printf(" %d", paths2[i]);
		}
		printf("\n");
	} else {
		printf("Distance = %d; Time = %d:", d[destination], t[destination]);
		for (int i=0; i<paths1.size(); i++) {
			if (i != 0) printf(" ->");
			printf(" %d", paths1[i]);
		}
		printf("\n");
	}

	//getchar();getchar();
	return 0;
}