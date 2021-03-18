#include <cstdio>

// lsseq[i] means the (i+1)-st number 
int seq[41][100000];
// means the digits number of (i+1)-st number in sequence
int digitlen[41];
int _1140() {
	int d, n;
	scanf("%d %d", &d, &n);
	// init first number in sequence
	seq[0][0] = d;
	digitlen[0] = 1;

	for(int i=1; i<n; i++) {
		int len = digitlen[i-1];
		int digit = seq[i-1][0];
		int count=1;
		int index=0;
		for(int j=1; j<len;j++) {
			if (digit == seq[i-1][j]) {
				count++;
			} else {
				// generate new digit in seq[i]
				seq[i][index++] = digit;
				seq[i][index++] = count;
				digit = seq[i-1][j];
				count = 1;
			}
		}
		seq[i][index++] = digit;
		seq[i][index++] = count;
		digitlen[i] = index;
	}

	for(int i=0; i<digitlen[n-1]; i++) {
		printf("%d", seq[n-1][i]);
	}
	//getchar();getchar();

	return 0;
}