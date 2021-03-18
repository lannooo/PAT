#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct GradeInfo {
	string id;
	int assign;
	int mid_term;
	int final_term;
	int final_grade;
	GradeInfo(){}
	GradeInfo(string _id, int _assign, int _mid, int _final) {
		id = _id;
		assign = _assign;
		mid_term = _mid;
		final_term = _final;
		final_grade = -1;
	}

};
map<string, GradeInfo> stugrades;


bool cmp_1137(GradeInfo a, GradeInfo b) {
	if (a.final_grade != b.final_grade) return a.final_grade > b.final_grade;
	return a.id < b.id;
}

int finalgrade(float mid, float final) {
	if (mid > 0 && mid > final) return (int)floor(final*0.6+mid*0.4+0.5);
	else return final;
}

int _1137() {
	int P, M, N;
	cin >> P >> M >> N;
	string id;
	int score;
	for(int i=0; i<P; i++) {
		cin >> id >> score;
		if (score >= 200 && score <= 900)
			stugrades[id] = GradeInfo(id, score, -1, -1);
		// ignore assignment score which is less than 200
	}
	for (int i=0; i<M; i++) {
		cin >> id >> score;
		if (stugrades.count(id) != 0) {
			stugrades[id].mid_term = score;
		}
	}
	vector<GradeInfo> v;
	for (int i=0; i<N; i++) {
		cin >> id >> score;
		if (stugrades.count(id) != 0) {
			stugrades[id].final_term = score;
			stugrades[id].final_grade = finalgrade((float)stugrades[id].mid_term, (float)score);
			if (stugrades[id].final_grade >= 60)
				v.push_back(stugrades[id]);
		}
	}
	sort(v.begin(), v.end(), cmp_1137);
	for (int i=0; i<v.size(); i++) {
		cout << v[i].id <<" "<<v[i].assign<<" "<<v[i].mid_term<<" "<<v[i].final_term<<" "<<v[i].final_grade;
		if (i != v.size()-1) cout<<endl;
	}
	return 0;
}