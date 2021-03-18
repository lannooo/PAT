#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct MiceNode {
	int index;
	int score;
	int rank;
}node;
vector<MiceNode> players;
int weights[1010] = {0};
int scores[1010] = {0};

bool cmp_1056(MiceNode a, MiceNode b) {
	return a.score > b.score;
}
bool cmpbyid_1056(MiceNode a, MiceNode b){
	return a.index < b.index;
}
int _1056() {
	int np, ng;
	int w;
	scanf("%d%d", &np, &ng);
	for(int i=0; i<np; i++) {
		scanf("%d", &w);
		weights[i] = w;
	}
	vector<int> matchpids;
	vector<int> nextpids;
	for (int i=0; i<np; i++) {
		scanf("%d", &node.index);
		players.push_back(node);
		matchpids.push_back(node.index);
	}
	//int matchplayers = np;
	do {
		for (int start = 0; start < matchpids.size(); start += ng) {
			int maxw = -1;
			int maxi = -1;
			for (int i=start; i<start+ng && i < matchpids.size(); i++) {
				if (weights[matchpids[i]] > maxw) {
					maxw = weights[matchpids[i]];
					maxi = matchpids[i];
				}
			}
			scores[maxi] ++;
			nextpids.push_back(maxi);
		}
		matchpids.clear();
		matchpids.insert(matchpids.begin(), nextpids.begin(), nextpids.end());
		nextpids.clear();
	} while(matchpids.size() > 1);
	// give score and rank
	for (int i=0; i<np; i++) players[i].score = scores[players[i].index];
	sort(players.begin(), players.end(), cmp_1056);
	int lastscore = -1;
	for (int i=0; i<np; i++) {
		if (players[i].score != lastscore) {
			players[i].rank = i+1;
			lastscore = players[i].score;
		} else {
			players[i].rank = players[i-1].rank;
		}
	}
	// print rank by id
	sort(players.begin(), players.end(), cmpbyid_1056);
	for (int i=0; i<np; i++) {
		if (i!=0) printf(" %d", players[i].rank);
		else printf("%d", players[i].rank);
	}
	//getchar();getchar();
	return 0;
}