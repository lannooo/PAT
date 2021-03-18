#include <cstdio>

const char cards[55][4] = {
	{""}, // 0
	{"S1"},{"S2"},{"S3"},{"S4"},{"S5"},{"S6"},{"S7"},{"S8"},{"S9"},{"S10"},{"S11"},{"S12"},{"S13"}, // 1-13
	{"H1"},{"H2"},{"H3"},{"H4"},{"H5"},{"H6"},{"H7"},{"H8"},{"H9"},{"H10"},{"H11"},{"H12"},{"H13"},
	{"C1"},{"C2"},{"C3"},{"C4"},{"C5"},{"C6"},{"C7"},{"C8"},{"C9"},{"C10"},{"C11"},{"C12"},{"C13"},
	{"D1"},{"D2"},{"D3"},{"D4"},{"D5"},{"D6"},{"D7"},{"D8"},{"D9"},{"D10"},{"D11"},{"D12"},{"D13"},
	{"J1"},{"J2"}
};

int  cnumbers[55];// a card-number means the index of the card corresponding to cards[][] (used to print card name)

void init() {
	int i;
	for (i=1; i<=54; i++) {
		cnumbers[i] = i;
	}
}


int _1042() {
	int  moves[55];// start from moves[1]
	int  k, i, j;// repeat times
	// init cnumbers and moved
	init();
	// read test case
	scanf("%d", &k);
	for (i=1; i<=54; i++) {
		scanf("%d", &moves[i]);
	}
	int cnumbers2[55];
	// start shuffling
	for (i=0; i<k; i++) {
		for(j=1; j<=54; j++) {
			cnumbers2[moves[j]] = cnumbers[j];
		}
		for (j=0;j<=54;j++) {
			cnumbers[j] = cnumbers2[j];
		}
	}
	for (i=1; i<=54; i++) {
		if (i != 1) printf(" ");
		printf("%s", cards[cnumbers[i]]);
	}

	return 0;
}