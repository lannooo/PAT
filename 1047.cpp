#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<int> courseMap[2501];
map<int, string> students;

int hash_1047(char name[]) {
	int h = 0;
	h = h * 36 + name[0]-'A'+1;
	h = h * 36 + name[1]-'A'+1;
	h = h * 36 + name[2]-'A'+1;
	h = h * 10 + name[3] -'0';
	return h;
}

int _1047() {
	int n,k;
	char buf[5];
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; i++) {
		int cnt, cid;
		scanf("%s%d", buf, &cnt);
		int h = hash_1047(buf);
		students[h] = string(buf);
		for(int j=0;j<cnt; j++) {
			scanf("%d", &cid);
			courseMap[cid].push_back(h);
		}
	}

	for (int cid = 1; cid <= k; cid++){
		vector<int> hs = courseMap[cid];
		sort(hs.begin(), hs.end());
		printf("%d %d\n", cid, hs.size());
		for(vector<int>::iterator it = hs.begin(); it != hs.end(); it++) {
			printf("%s\n", students[(*it)].c_str());
		}
	}
	//getchar();getchar();
	return 0;
}