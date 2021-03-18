#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Property {
	int estate;
	float area;
	Property(){}
	Property(int _estate, float _area):estate(_estate),area(_area){}
};

struct FamilyInfo{
	int id;
	int members;
	float avg_estate;
	float avg_area;
	FamilyInfo(){}
	FamilyInfo(int _id, int _members, float _estate, float _area){
		id = _id;
		members = _members;
		avg_estate = _estate;
		avg_area = _area;
	}
};

set<int> relations[10000];//adj
map<int, Property> properties;
vector<FamilyInfo> infos;
bool psvisit[10000]; // ID->visited

void dfs_estate(int id, int &minId, int &members, int &estatecnt, float &areacnt) {
	psvisit[id] = true;
	members++;
	if (id < minId) minId = id;
	if (properties.find(id) != properties.end()) {
		// has estate , sum up
		estatecnt += properties[id].estate;
		areacnt += properties[id].area;
	}
	set<int> rs = relations[id];
	for (set<int>::iterator it = rs.begin(); it != rs.end(); it++) {
		if (psvisit[(*it)] == false) {
			dfs_estate(*it, minId, members, estatecnt, areacnt);
		}
	}
}

bool cmp_1114(FamilyInfo a, FamilyInfo b) {
	if (a.avg_area != b.avg_area) return a.avg_area > b.avg_area;
	return a.id < b.id;
}

int _1114() {
	fill(psvisit, psvisit+10000, true);
	int n;
	scanf("%d", &n);
	int id, father, mother, k;
	for (int i=0; i<n; i++) {
		scanf("%d%d%d%d", &id, &father, &mother, &k);
		psvisit[id] = false;
		if (father != -1) {
			relations[id].insert(father);
			relations[father].insert(id);
			psvisit[father] = false;
		}
		if (mother != -1) {
			relations[id].insert(mother);
			relations[mother].insert(id);
			psvisit[mother] = false;
		}
		int child;
		for (int j=0; j<k; j++) {
			scanf("%d", &child);
			relations[id].insert(child);
			relations[child].insert(id);
			psvisit[child] = false;
		}
		int estate;
		float area;
		scanf("%d%f", &estate, &area);
		properties[id] = Property(estate, area);
	}
	for (int i=0; i<10000; i++) {
		if (psvisit[i]==false) {
			int cnt = 0;
			int minId = i;
			int estatecnt=0;
			float areacnt = 0.0;
			dfs_estate(i, minId, cnt, estatecnt, areacnt);
			infos.push_back(FamilyInfo(minId, cnt, estatecnt*1.0/cnt, areacnt/cnt));
		}
	}
	// sort info and print
	sort(infos.begin(), infos.end(), cmp_1114);
	printf("%d", infos.size());
	for(int i=0; i<infos.size(); i++) {
		printf("\n%04d %d %.3f %.3f", infos[i].id, infos[i].members, infos[i].avg_estate, infos[i].avg_area);
	}
	//getchar();getchar();
	return 0;
}