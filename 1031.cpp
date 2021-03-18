#include <cstdio>
#include <cstring>

void drawU(char inputs[], int h, int w) {
	int space = w-2;
	int n = 2*h+w;
	int i, j;
	for (i=0; i<h; i++) {
		printf("%c", inputs[i]);
		for (j=0; j<space; j++) printf(" ");
		printf("%c", inputs[n-i-1]);
		printf("\n");
	}
	for (i=h; i<w+h; i++) {
		printf("%c", inputs[i]);
	}
}

int _1031() {
	char inputs[81];
	scanf("%s", inputs);
	int n = strlen(inputs);

	int w = n/3;
	if (w<3) w=3; // to make w start from 3
	while((n-w)%2 != 0 || (n-w)/2+1 > w) // ajust w to a proper value (which is as small as possible)
		w++;
	int h = (n-w)/2;

	drawU(inputs, h, w);
	getchar();
	getchar();

	return 0;
}