#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
	int month;
	int day;
	int hour;
	int minute;
	bool pairflag;//true for on-line, false for off-line
};
int tolls[25] = {0};

int getTime(int day, int hour, int minute) {
	return 1440 * day + 60 * hour + minute;
}

bool cmp(Record r1, Record r2) {
	return getTime(r1.day, r1.hour, r1.minute) < getTime(r2.day, r2.hour, r2.minute);
}

double getbillfromzero(int day, int hour, int minute) {
	long long cents = tolls[hour] * minute + tolls[24] * 60 * day;
	for(int i=0; i<hour; i++) {
		cents += (tolls[i] * 60);
	}
	return cents/100.0;
}

double getbill(int d1, int h1, int m1, int d2, int h2, int m2) {
	return getbillfromzero(d2,h2,m2) - getbillfromzero(d1,h1,m1);
}

int _1016() {
	map<string, vector<Record> > bills;
	// read tolls
	for(int i=0; i<24; i++) {
		scanf("%d", &tolls[i]);
		tolls[24] += tolls[i];
	}
	// read records
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		char namebuf[25];
		char pairbuf[10];
		int month, day, hour, minute;
		scanf("%s %02d:%02d:%02d:%02d %s", namebuf, &month, &day, &hour, &minute, pairbuf);
		string pair(pairbuf);
		bool flag = (pair == "on-line");
		Record r = {month, day, hour, minute, flag};
		string name(namebuf);
		if (bills.count(name) == 0) {
			vector<Record> v;
			v.push_back(r);
			bills[name] = v;
		} else {
			bills[name].push_back(r);
		}
	}

	for(map<string, vector<Record> >::iterator it = bills.begin(); it != bills.end(); it++) {
		string name = it->first;
		vector<Record> v = it->second;
		sort(v.begin(), v.end(), cmp);
		double totalbill=0.0;
		int size = v.size();
		int month = v[0].month;
		vector<Record> vv;
		for(int i=1; i<size; i++) {
			if (v[i].pairflag == false && v[i-1].pairflag == true) {
				vv.push_back(v[i-1]);
				vv.push_back(v[i]);
			}
		}
		if (vv.size() == 0) continue;// no valid records, did not print bills

		printf("%s %02d\n", name.c_str(), month);// print name and month
		for(int i=1; i<vv.size(); i+=2) {
			int total_minute = getTime(vv[i].day, vv[i].hour, vv[i].minute)
					-getTime(vv[i-1].day, vv[i-1].hour, vv[i-1].minute); 
			double abill = getbill(vv[i-1].day, vv[i-1].hour, vv[i-1].minute,
					vv[i].day, vv[i].hour, vv[i].minute);
			totalbill += abill;
			// print a bill
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", 
					vv[i-1].day, vv[i-1].hour, vv[i-1].minute, vv[i].day, vv[i].hour, vv[i].minute,
					total_minute,abill);
		}
		printf("Total amount: $%.2f\n", totalbill);// print total bill
	}

	//getchar();getchar();

	return 0;
}