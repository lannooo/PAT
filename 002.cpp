#include <cstdio>
#include <vector>
using namespace std;

const int NOT_KNOW = -1;
const int OUTSIDE = 1;
const int INSIDE = 0;

bool isValidOutSeq(vector<int> out, vector<int> in) {
	int leftout = -1;
	int rightout = -1;
	vector<int> state(in.size(), NOT_KNOW);// state of number, whether in seq
	for (int i=0; i<out.size(); i++) {
		int now = out[i];
		int index;
		for (int j=0; j<in.size(); j++) {
			if (in[j] == now) {
				index = j; break;
			}
		}
		if (index > rightout) {
			for (int j=leftout+1; j<=index; j++) {
				if (state[j]==NOT_KNOW) state[j] = INSIDE;
			}
			state[index] = OUTSIDE;
			rightout = index;
		} else if (index < rightout) {
			bool lin = false,rin = false;
			for (int j=index+1; j< rightout; j++) {
				if (state[j] == INSIDE){
					rin = true;
				}
			}
			for (int j=leftout+1; j<index; j++) {
				if (state[j] == INSIDE){
					lin = true;
				}
			}
			if (lin && rin) return false;
			else {
				state[index] = OUTSIDE;
			}
		}
	}
	return true;
}

int _002() {
	vector<int> inseq;
	int N, K, d;
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++) {
		scanf("%d", &d);
		inseq.push_back(d);
	}
	for (int i=0; i<K; i++) {
		vector<int> outseq;
		for(int j=0; j<N; j++) {
			scanf("%d", &d);
			outseq.push_back(d);
		}
		if (isValidOutSeq(outseq, inseq)) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	//getchar();getchar();
	return 0;
}