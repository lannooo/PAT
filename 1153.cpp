#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct PatCard{
	string cardNumber;
	int score;
}cards[10000];

struct Cite{
	int cnt;
	int score;
	Cite(){}
	Cite(int _cnt, int _score):cnt(_cnt), score(_score){}
};

vector<PatCard*> tlevel;
vector<PatCard*> alevel;
vector<PatCard*> blevel;

unordered_map<int, Cite*> cites;

unordered_map<int, unordered_map<int, int> > dates_cites;

void addToDate(int date, int cite) {
	dates_cites[date][cite]++;
}

void addToCite(int citeid, int score) {
	if (cites.count(citeid) != 0) {
		(cites[citeid]->cnt)++;
		(cites[citeid]->score)+=score;
	} else {
		cites[citeid] = new Cite(1, score);
	}
}

void addToLevel(PatCard *ptr, char level) {
	if (level == 'A') alevel.push_back(ptr);
	else if (level == 'T') tlevel.push_back(ptr);
	else blevel.push_back(ptr);
}

bool cmpScore(PatCard *a, PatCard *b) {
	if (a->score != b->score) return a->score > b->score;
	return a->cardNumber < b->cardNumber;
}

bool cmpCnt(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

void sortLevels() {
	sort(tlevel.begin(), tlevel.end(), cmpScore);
	sort(alevel.begin(), alevel.end(), cmpScore);
	sort(blevel.begin(), blevel.end(), cmpScore);
}

void printDate(int term) {
	if (dates_cites.count(term) == 0){
		printf("NA\n");
	} else {
		unordered_map<int, int> citecnt = dates_cites[term];
		vector<pair<int, int> > list;
		for (unordered_map<int, int>::iterator it = citecnt.begin(); it != citecnt.end(); it++) {
			list.push_back(pair<int, int>(it->first, it->second));
		}
		sort(list.begin(), list.end(), cmpCnt);
		for (int i=0; i<list.size(); i++) {
			printf("%d %d\n", list[i].first, list[i].second);
		}
	}
}

void printCite(int term) {
	if (cites.count(term)==0) {
		printf("NA\n");
	} else {
		printf("%d %d\n",  cites[term]->cnt, cites[term]->score);
	}
}

void printLevels(char term) {
	if(term == 'A') {
		if (alevel.empty()) printf("NA\n");
		for (int i=0; i<alevel.size(); i++)
			printf("%s %d\n", alevel[i]->cardNumber.c_str(), alevel[i]->score);
	} else if (term == 'B') {
		if (blevel.empty()) printf("NA\n");
		for (int i=0; i<blevel.size(); i++) 
			printf("%s %d\n", blevel[i]->cardNumber.c_str(), blevel[i]->score);
	} else {
		if (tlevel.empty()) printf("NA\n");
		for (int i=0; i<tlevel.size(); i++) 
			printf("%s %d\n", tlevel[i]->cardNumber.c_str(), tlevel[i]->score);
	}
}

int readInt(char buf[], int from, int len) {
	int ans = 0;
	for (int i=from; i<from+len; i++) {
		ans = ans*10 + (buf[i]-'0');
	}
	return ans;
}

int _1153() {
	int N, M, d;
	scanf("%d%d", &N, &M);
	char buf[100];
	for (int i=0; i<N; i++) {
		scanf("%s%d", buf, &d);
		cards[i].cardNumber = string(buf);
		cards[i].score = d;
		PatCard *ptr = &cards[i];
		// todo something 
		int cite = readInt(buf, 1, 3);
		int date = readInt(buf, 4, 6);
		addToLevel(ptr, buf[0]);
		addToCite(cite, cards[i].score);
		addToDate(date, cite);
	}

	// sort level
	sortLevels();
	
	int type;
	int term;
	char buf2[2];
	for (int i=1; i<=M; i++) {
		scanf("%d", &type);
		if (type == 1) { // query by level
			scanf("%s", buf2);
			printf("Case %d: %d %s\n", i, type, buf2);
			printLevels(buf2[0]);
		} else if (type == 2) { // query by cite
			scanf("%d", &term);
			printf("Case %d: %d %03d\n", i, type, term);
			printCite(term);
		} else {// query by date
			scanf("%d", &term);
			printf("Case %d: %d %06d\n", i, type, term);
			printDate(term);
		}
	}
	//getchar();getchar();
	return 0;
}