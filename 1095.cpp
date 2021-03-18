#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct GateRecord {
	string plate;
	int time; //hh:mm:ss  -> ss+mm*60+hh*3600
	int type; //1 for in, 2 for out
	GateRecord(){}
	GateRecord(string _p, int _time, int _type):plate(_p), time(_time), type(_type){}
};

struct TimePair{
	int h, m, s;
	TimePair(int time) {
		h = time/3600;time%=3600;
		m = time/60;time%=60;
		s = time;
	}
};

vector<GateRecord*> records;

bool cmpbytime(GateRecord *a, GateRecord *b) {
	return a->time < b->time;
}

bool cmpbyplate(GateRecord *a, GateRecord *b) {
	if (a->plate != b->plate)
		return a->plate < b->plate;
	return a->time < b->time;
}

int toTime(string timeStr) {
	int h = (timeStr[0]-'0')*10+(timeStr[1]-'0');
	int m = (timeStr[3]-'0')*10+(timeStr[4]-'0');
	int s = (timeStr[6]-'0')*10+(timeStr[7]-'0');
	return s+m*60+h*3600;
}

int toType(string type) {
	if (type == "in") return 1;
	else return 2;
}

map<string, int> parkrecords;
void updateParkRecord(string plate, int period) {
	parkrecords[plate]+=period;
}

int _1095() {
	vector<GateRecord*> temp;
	int n, k;
	cin>>n>>k;
	string plateNum;
	string timeStr;
	string type;
	for (int i=0; i<n; i++) {
		cin >> plateNum >> timeStr >> type;
		temp.push_back(new GateRecord(plateNum, toTime(timeStr), toType(type)));
	}
	// filter invalid records
	sort(temp.begin(), temp.end(), cmpbyplate);
	for (int i=0; i<temp.size()-1; i++) {
		if (temp[i]->plate == temp[i+1]->plate) {
			if (temp[i]->type == 1 && temp[i+1]->type == 2) {
				records.push_back(temp[i]);
				records.push_back(temp[i+1]);
				updateParkRecord(temp[i]->plate, temp[i+1]->time - temp[i]->time);
			}
		}
	}
	sort(records.begin(), records.end(), cmpbytime);
	int h, m, s, time;
	int index = 0, cnt=0;
	for (int i=0; i<k; i++) {
		scanf("%d:%d:%d", &h, &m, &s);
		time = s+m*60+h*3600;
		while (index < records.size()) {
			if (records[index]->time <= time) {
				if (records[index]->type == 1) cnt++;
				else cnt--;
				index++;
			} else break;
		}
		printf("%d\n", cnt);
	}
	set<string> plates;
	int maxperiod = -1;
	for (map<string, int>::iterator it = parkrecords.begin(); it!=parkrecords.end(); it++) {
		if (it->second > maxperiod) {
			maxperiod = it->second;
			plates.clear();
			plates.insert(it->first);
		} else if (it->second == maxperiod) {
			plates.insert(it->first);
		}
	}
	TimePair tp(maxperiod);
	for (set<string>::iterator it = plates.begin(); it != plates.end(); it++) {
		cout << *it << " ";
	}
	printf("%02d:%02d:%02d", tp.h, tp.m, tp.s);
	//cin.get();cin.get();
	return 0;
}