#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct patuser {
	int uid;
	int solved;//perfect solved problems
	int total_score;
	int rank;
	int scores[6];
	int subtimes[6];
	bool show;
};

patuser* newUser(int uid) {
	patuser *user = new patuser;
	user->uid = uid;
	user->solved = 0;
	user->total_score = 0;
	user->rank = -1;
	user->show = false;
	fill(user->scores, (user->scores) + 6, -1);
	fill(user->subtimes, (user->subtimes) + 6, 0);
	return user;
}

bool cmppatuser(patuser* a, patuser* b){
	if(a->total_score != b->total_score) return a->total_score > b->total_score;
	if (a->solved != b->solved) return a->solved > b->solved;
	return a->uid < b->uid;
}

int _1075() {
	// user id from 00001 to N, and problem id from 1 to K
	int n, k, m;
	int mark;
	scanf("%d%d%d", &n, &k, &m);
	vector<int> fullmarks(k+1);
	vector<patuser*> ranklists;
	map<int, patuser* > users;

	for (int i=1; i<=k; i++) {
		scanf("%d", &mark);
		fullmarks[i] = mark;
	}
	int uid, pid, score;
	for (int i=0; i<m; i++) {
		scanf("%d%d%d", &uid, &pid, &score);
		if (users.count(uid) == 0) {
			users[uid] = newUser(uid);
		}
		(users[uid]->subtimes[pid])++;
		if(score >=0 ) users[uid]->show = true;
		if (score > (users[uid]->scores[pid])) 
			users[uid]->scores[pid] = score;
		
	}
	for(map<int,patuser*>::iterator it = users.begin(); it != users.end(); it++) {
		patuser* user = it->second;
		int total = 0;
		for(int p=1; p<=k; p++) {
			if (user->scores[p] >= 0) {
				if (user->scores[p] == fullmarks[p]) (user->solved)++;
				total+= user->scores[p];
			}
		}
		user->total_score = total;
		if (user->show) ranklists.push_back(user);
	}
	sort(ranklists.begin(), ranklists.end(), cmppatuser);
	int lastscore = -1;
	for(int i=0; i<ranklists.size(); i++) {
		if (ranklists[i]->total_score != lastscore) {
			lastscore = ranklists[i]->total_score;
			ranklists[i]->rank = i+1;
		} else {
			ranklists[i]->rank = ranklists[i-1]->rank;
		}
	}
	for(int i=0; i<ranklists.size(); i++) {
		patuser* u = ranklists[i];
		printf("%d %05d %d", u->rank, u->uid, u->total_score);
		for(int p=1; p<=k; p++) {
			int s = ranklists[i]->scores[p];
			if (s == -1){
				if (ranklists[i]->subtimes[p] > 0) printf(" 0");
				else printf(" -");
			}
			else printf(" %d", s);
		}
		printf("\n");
	}
	//getchar();getchar();
	return 0;
}