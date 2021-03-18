#include <cstdio>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct RecItem {
	int index;
	int freq;
	RecItem(){}
	RecItem(int _index, int _freq):index(_index),freq(_freq){}
};

RecItem* recItems[10];
int freq_max=0, freq_min=0;
RecItem* moreItems[50000];
map<int, int> itemPosition;// id->index in moreItems
map<int, int> recPosition;// id->index in recItems
int maxRec;
int nowRec = 0;

bool cmpRecItem(RecItem *a, RecItem *b) {
	if (a->freq != b->freq) return a->freq > b->freq;
	return a->index < b->index;
}

void updateRecInfo() {
	sort(recItems, recItems+nowRec, cmpRecItem);//there could be better sort method...
	freq_max = recItems[0]->freq;
	freq_min = recItems[nowRec-1]->freq;
	for (int i=0; i<nowRec; i++) recPosition[recItems[i]->index] = i; // update recItem's position map
}

void addItem(RecItem * item) {
	if (nowRec >= maxRec){
		// Whether there are frec change in recItems?
		// or if there are more frequently accessed item needed to swap into recItems
		if (freq_min == 1 && cmpRecItem(item, recItems[nowRec-1])) {
			// swap out
			RecItem *item1 = recItems[nowRec-1];
			recPosition.erase(recPosition.find(item1->index));
			int pos = itemPosition.size();
			moreItems[pos] = item1;
			itemPosition[item1->index] = pos;
			// insert in new Item
			recItems[nowRec-1] = item;
			recPosition[item->index] = nowRec-1;
			updateRecInfo();
		} else {
			int pos = itemPosition.size();
			moreItems[pos] = item;
			itemPosition[item->index] = pos;
		}
	} else {
		// insert at last
		recItems[nowRec++] = item;
		recPosition[item->index] = nowRec-1;
		updateRecInfo();
	}
}

void addFreq(int index) {
	if (recPosition.count(index) != 0) {
		int pos = recPosition[index];
		recItems[pos]->freq++;
		updateRecInfo();
	} else {
		int pos = itemPosition[index];
		int freq = ++(moreItems[pos]->freq);
		if (freq >= freq_min && cmpRecItem(moreItems[pos], recItems[nowRec-1])) {
			// swap 
			RecItem *item1 = recItems[nowRec-1];
			RecItem *item2 = moreItems[pos];
			recPosition.erase(recPosition.find(item1->index));
			itemPosition.erase(itemPosition.find(item2->index));
			moreItems[pos] = item1;
			recItems[nowRec-1] = item2;
			itemPosition[item1->index] = pos;
			recPosition[item2->index] = nowRec-1;
			updateRecInfo();
		}
	}
}

void printRec(int id) {
	int cnt = maxRec;
	if (nowRec < maxRec) cnt = nowRec;
	printf("%d:", id);
	for (int i=0; i<cnt; i++) {
		printf(" %d", recItems[i]->index);
	}
	printf("\n");
}

set<int> itemIds;
int _1129() {
	int N, id;
	scanf("%d%d", &N, &maxRec);
	for (int i=1; i<=N; i++) {
		scanf("%d", &id);
		if (i!=1) printRec(id);
		if (itemIds.count(id)==0) {
			itemIds.insert(id);
			addItem(new RecItem(id, 1));
		} else {
			addFreq(id);
		}
	}
	
	//getchar();getchar();
	return 0;
}