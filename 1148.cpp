#include <cstdio>

const int WEREWOLF = -101;
const int HUMAN = 101;
const int ROLE = 0;
const int REF = 1;

int statement[110][2];// statement[i][0] means identity of index of player #statement[i][1]

void readStatements(int n) {
	char sign;
	int ref;
	for(int i=1; i<=n; i++) {
		getchar();// absorb newline character
		scanf("%c%d", &sign, &ref);
		if (sign == '+') {
			statement[i][ROLE] = HUMAN;
		} else {
			statement[i][ROLE] = WEREWOLF;
		}
		statement[i][REF] = ref;		
	}
}

int roles[110];// index from 1-n
//bool liars[110];// index from 1-n

bool judgeStatement(int wolf1, int wolf2, int n) {
	// init judge arrays
	for (int i=1; i<=n; i++){
		roles[i] = HUMAN;
		//liars[i] = false;
	}
	roles[wolf1] = WEREWOLF;
	roles[wolf2] = WEREWOLF;
	int wolfliars = 1;
	int manliars = 1;
	for (int i=1; i<=n; i++) {
		// player #i says that player #ref_id is a 'ref_role'
		int ref_role = statement[i][ROLE];
		int ref_id = statement[i][REF];
		// compare with roles to see if this player is lying
		if (ref_role != roles[ref_id]) {
			// he is lying!
			if (roles[i] == WEREWOLF) {
				if (wolfliars > 0) wolfliars--;
				else return false;
			} else {
				if (manliars > 0) manliars --;
				else return false;
			}
		}
	}
	// it is supposed that there is exactly one wolf liar and one human liar
	if(wolfliars != 0 || manliars != 0) return false;
	return true;
}

int _1148() {
	int n;
	scanf("%d", &n);
	readStatements(n);
	for (int first = 1; first <= n-1; first++) {
		for(int second = first+1; second <=n; second++) {
			if (judgeStatement(first, second, n)) {
				printf("%d %d", first, second);
				//getchar();getchar();
				return 0;
			}
		}
	}
	printf("No Solution");
	//getchar();getchar();
	return 0;
}