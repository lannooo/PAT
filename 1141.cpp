#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct InstiGrade{
	int rank;
	string school;
	int ns;
	int tws;
	int scoreA;
	int scoreB;
	int scoreT;
	InstiGrade(){}
	InstiGrade(string _s){
		rank = -1;
		school = _s;
		ns = 0;
		tws = -1;
		scoreA = scoreB = scoreT = 0;
	}
};

unordered_map<string, InstiGrade> instiGrades;

string tolowercase(string str) {
	for (int i=0; i<str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i]-'A'+'a';
	}
	return str;
}

int tws(int scoreA, int scoreB, int scoreT) {
	float sum = 1.0*scoreA+1.0*scoreB/1.5+1.5*scoreT;
	return (int)sum;
}

bool cmp_1141(InstiGrade a, InstiGrade b) {
	if (a.tws != b.tws) return a.tws > b.tws;
	if (a.ns != b.ns) return a.ns < b.ns;
	return a.school < b.school;
}

int _1141() {
	int n;
	cin >> n;
	string id;
	int score;
	string school;
	for (int i=0; i<n; i++) {
		cin >> id >> score >> school;
		school = tolowercase(school);
		if (instiGrades.count(school)==0) {
			instiGrades[school] = InstiGrade(school);
		}
		if (id[0]=='A') {
			instiGrades[school].ns++;
			instiGrades[school].scoreA+=score;
		} else if (id[0]=='B') {
			instiGrades[school].ns++;
			instiGrades[school].scoreB+=score;
		} else {
			instiGrades[school].ns++;
			instiGrades[school].scoreT+=score;
		}
	}
	vector<InstiGrade> v;
	for (unordered_map<string, InstiGrade>::iterator it=instiGrades.begin(); it!=instiGrades.end(); it++) {
		InstiGrade grade = it->second;
		grade.tws = tws(grade.scoreA, grade.scoreB, grade.scoreT);
		v.push_back(grade);
	}
	sort(v.begin(), v.end(), cmp_1141);
	int last = -1;
	for (int i=0; i<v.size(); i++) {
		if (v[i].tws != last) {
			v[i].rank = i+1;
			last = v[i].tws;
		}
		else v[i].rank = v[i-1].rank;
	}
	cout << v.size()<<endl;
	for (int i=0; i<v.size(); i++) {
		cout <<v[i].rank <<" "<<v[i].school << " "<<v[i].tws<<" "<<v[i].ns<<endl;
	}
	return 0;
}