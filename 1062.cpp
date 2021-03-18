#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Person{
	int id;
	int virtue;
	int talent;
	int total;
}person;

bool cmp_1062(Person a, Person b) {
	if (a.total != b.total) return a.total > b.total;
	if (a.virtue != b.virtue) return a.virtue > b.virtue;
	return a.id < b.id;
}
void printPersonInfo(vector<Person> &v) {
	for (int i=0; i<v.size(); i++) {
		printf("%08d %d %d\n", v[i].id, v[i].virtue, v[i].talent);
	}
}
int _1062() {
	vector<Person> sage;
	vector<Person> nobleman;
	vector<Person> foolman;
	vector<Person> smallman;
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	for(int i=0; i<N; i++) {
		scanf("%d%d%d", &person.id, &person.virtue, &person.talent);
		person.total = person.virtue + person.talent;
		if (person.virtue >= H) {
			if (person.talent >= H) sage.push_back(person);
			else if (person.talent >= L) nobleman.push_back(person);
		} else if (person.virtue >= L && person.talent >= L) {
			if (person.talent <= person.virtue) foolman.push_back(person);
			else smallman.push_back(person);
		}
	}
	sort(sage.begin(), sage.end(), cmp_1062);
	sort(nobleman.begin(), nobleman.end(), cmp_1062);
	sort(foolman.begin(), foolman.end(), cmp_1062);
	sort(smallman.begin(), smallman.end(), cmp_1062);
	int total = sage.size()+nobleman.size()+foolman.size()+smallman.size();
	printf("%d\n", total);
	printPersonInfo(sage);
	printPersonInfo(nobleman);
	printPersonInfo(foolman);
	printPersonInfo(smallman);
	
	return 0;
}