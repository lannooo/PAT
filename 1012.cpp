#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Grade {
	string id;
	int c_grade;
	int m_grade;
	int e_grade;
	float a_grade;
};

const int AVERAGE = 0;
const int CPROGRAM = 1;
const int MATH = 2;
const int ENGLISH = 3;

struct Rank {
	//store the rank of 'average', 'c-program','math','english', 
	//with its priority decrease.
	int ranks[4];
};

bool cmp_c(Grade a, Grade b) {
	return a.c_grade > b.c_grade;
}

bool cmp_m(Grade a, Grade b) {
	return a.m_grade > b.m_grade;
}

bool cmp_e(Grade a, Grade b) {
	return a.e_grade > b.e_grade;
}

bool cmp_a(Grade a, Grade b) {
	return a.a_grade > b.a_grade;
}

Grade newGrade(string id, int c, int m, int e, float a) {
	Grade g;
	g.id = id;
	g.c_grade = c;
	g.m_grade = m;
	g.e_grade = e;
	g.a_grade = a;
	return g;
}

Rank newRank() {
	return *(new Rank);
}

char course(int i) {
	switch(i) {
	case 0:return 'A';
	case 1:return 'C';
	case 2:return 'M';
	case 3:return 'E';
	default:return 'x';
	}
}

int _1012() {
	vector<Grade> gradeList;
	map<string, Rank> rankMap;
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		string id;
		int grade_c,grade_m,grade_e;
		float grade_a;
		cin >> id >> grade_c >> grade_m >> grade_e;
		grade_a = (grade_c+grade_m+grade_e)/3.0;

		Grade g = newGrade(id, grade_c, grade_m, grade_e, grade_a);
		Rank  r = newRank();
		gradeList.push_back(g);
		rankMap[id] = r;
	}

	int size = gradeList.size();
	int previous = -1;
	float previousf = -1;

	sort(gradeList.begin(), gradeList.end(), cmp_a);
	for(int i=0; i< size; i++) {
		string curid = gradeList[i].id;
		if (gradeList[i].a_grade != previous) {
			rankMap[curid].ranks[AVERAGE] = i+1;
			previousf = gradeList[i].a_grade;
		} else {
			rankMap[curid].ranks[AVERAGE] = rankMap[gradeList[i-1].id].ranks[AVERAGE];
		}
	}
	previous = -1;
	sort(gradeList.begin(), gradeList.end(), cmp_c);
	for(int i=0; i< size; i++) {
		string curid = gradeList[i].id;
		if (gradeList[i].c_grade != previous) {
			rankMap[curid].ranks[CPROGRAM] = i+1;
			previous = gradeList[i].c_grade;
		} else {
			rankMap[curid].ranks[CPROGRAM] = rankMap[gradeList[i-1].id].ranks[CPROGRAM];
		}
	}
	previous = -1;
	sort(gradeList.begin(), gradeList.end(), cmp_m);
	for(int i=0; i< size; i++) {
		string curid = gradeList[i].id;
		if (gradeList[i].m_grade != previous) {
			rankMap[curid].ranks[MATH] = i+1;
			previous = gradeList[i].m_grade;
		} else {
			rankMap[curid].ranks[MATH] = rankMap[gradeList[i-1].id].ranks[MATH];
		}
	}
	previous = -1;
	sort(gradeList.begin(), gradeList.end(), cmp_e);
	for(int i=0; i< size; i++) {
		string curid = gradeList[i].id;
		if (gradeList[i].e_grade != previous) {
			rankMap[curid].ranks[ENGLISH] = i+1;
			previous = gradeList[i].e_grade;
		} else {
			rankMap[curid].ranks[ENGLISH] = rankMap[gradeList[i-1].id].ranks[ENGLISH];
		}
	}

	for (int i=0; i<m; i++) {
		string id;
		cin>>id;
		if (rankMap.count(id) != 0) {
			Rank r = rankMap[id];
			int bestrank = r.ranks[0];
			int best = 0;
			for (int j=1; j<4; j++) {
				if (r.ranks[j] < bestrank)  {
					bestrank = r.ranks[j];
					best = j;
				}
			}
			printf("%d %c", bestrank, course(best));
		} else {
			printf("N/A");
		}
		if (i!=m-1) printf("\n");
	}
	//getchar();getchar();
	return 0;
}