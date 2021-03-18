#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

struct PathSeg{
	int line, start, stop;
	PathSeg(){}
	PathSeg(int _line, int _start, int _stop):line(_line), start(_start),stop(_stop){}
};

unordered_map<int, vector<int> > subwayAdj;
unordered_map<int, int> linemap;
unordered_map<int, bool> visitmap;

int hashline(int start, int stop){
	return start*10000+stop;
}

int maxstops = 100000;
vector<PathSeg> ans;

void transToPath(vector<int> &path, vector<PathSeg> &ans) {
	int pre = path[0], now = path[1];
	int line, lastline= linemap[hashline(pre, now)];
	PathSeg seg(lastline, pre, now);
	if (path.size() == 2) {
		ans.push_back(seg);
		return;
	}
	pre = now;
	for (int i=2; i<path.size(); i++) {
		now = path[i];
		int line = linemap[hashline(pre, now)];
		if (line != lastline) {// switch line
			lastline = line;
			ans.push_back(seg);
			seg = PathSeg(line, pre, now);
		} else { // keep in this line
			seg.stop = now;
		}
		if (i == path.size()-1) { // final stop
			ans.push_back(seg);
		}
		pre = now;
	}
}

void dfs_subway(int now, int stop, int len, vector<int> &path) {
	if (now == stop) {
		path.push_back(now);
		if (len < maxstops) {
			maxstops = len;
			ans.clear();
			transToPath(path, ans);
		} else if (len == maxstops) {
			vector<PathSeg> res;
			transToPath(path, res);
			if (res.size() < ans.size()) {
				ans = res;
			}
		}
		path.pop_back();
		return;
	}
	visitmap[now] = true;
	path.push_back(now);

	for (int i=0; i<subwayAdj[now].size(); i++) {
		int next = subwayAdj[now][i];
		if (!visitmap[next]) {
			dfs_subway(next, stop, len+1, path);
		}
	}

	visitmap[now] = false;
	path.pop_back();
}

void printLines(int start, int stop){
	maxstops = 100000;
	ans.clear();
	visitmap.clear();
	vector<int> path;
	dfs_subway(start, stop, 0, path);
	printf("%d\n", maxstops);
	for (int i=0; i<ans.size(); i++) {
		printf("Take Line#%d from %04d to %04d.\n", ans[i].line, ans[i].start, ans[i].stop);
	}
}

int _1131() {
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		int m, pre, now;
		scanf("%d", &m);
		scanf("%d", &pre);
		for (int j=1; j<m; j++) {
			scanf("%d", &now);
			subwayAdj[pre].push_back(now);
			subwayAdj[now].push_back(pre);
			linemap[hashline(pre, now)] = i;
			linemap[hashline(now, pre)] = i;
			pre = now;
		}
	}
	int k;
	scanf("%d", &k);
	for(int i=0; i<k; i++) {
		int start, stop;
		scanf("%d%d", &start, &stop);
		printLines(start, stop);
	}
	//getchar();getchar();
	return 0;
}