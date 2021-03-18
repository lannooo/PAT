#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

typedef bool sex;

const sex Boy = true;
const sex Girl = false;
bool gender[10000];

unordered_map<int, set<int> > friends;

vector<pair<int,int> > findRelations(int id1, int id2) {
	vector<pair<int,int> > ans;
	sex s1 = gender[id1];
	sex s2 = gender[id2];
	set<int> filters;
	filters.insert(id1);
	filters.insert(id2);
	for (set<int>::iterator it = friends[id1].begin(); it != friends[id1].end(); it++) {
		int f1 = *it;
		if (gender[f1] == s1 && filters.count(f1) == 0) {
			filters.insert(f1);
			for (set<int>::iterator it2=friends[f1].begin(); it2!=friends[f1].end(); it2++) {
				int f2 = *it2;
				if (gender[f2] == s2 && filters.count(f2) == 0 && friends[f2].count(id2) != 0) {
					// find a path, store f1 and f2
					ans.push_back(pair<int,int>(f1, f2));
				}
			}
			filters.erase(filters.find(f1));
		}
	}
	return ans;
}

void storeRelation(int id1, int id2) {
	friends[id1].insert(id2);
	friends[id2].insert(id1);
}

int changeToInt(string id) {
	bool isMale = true;
	int index = 0;
	if (id[0] == '-') {
		isMale = false;
		index++;
	}
	int ans=0;
	for (int i=index; i<index+4; i++) {
		ans = ans*10 + (id[i]-'0');
	}
	if (isMale) gender[ans] = Boy;
	else gender[ans] = Girl;
	return ans;
}

int _1139() {
	int N, M, K;
	cin >> N >> M;
	string id1, id2;
	for (int i=0; i<M; i++) {
		cin >> id1 >> id2;
		storeRelation(changeToInt(id1), changeToInt(id2));
	}
	cin>>K;
	for (int i=0; i<K; i++) {
		cin >> id1 >> id2;
		vector<pair<int, int> > rls = findRelations(changeToInt(id1), changeToInt(id2));
		cout << rls.size() <<endl;
		for (int j=0; j<rls.size(); j++) printf("%04d %04d\n", rls[j].first, rls[j].second);
	}
	//cin.get();cin.get();
	return 0;
}