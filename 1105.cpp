#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int RIGHT = 1;
const int DOWN  = 2;
const int LEFT  = 3;
const int UP    = 4;

void putMatrix(vector<int> &nums, vector<vector<int> > &matrix, int m, int n) {
	int row = 0, col = -1, direction = RIGHT;
	while(!nums.empty()) {
		if (direction == RIGHT || direction == LEFT) {
			for (int i=0; i<n; i++) {
				int d = nums.back(); nums.pop_back();
				if(direction == RIGHT) col++;
				else col--;
				matrix[row][col] = d;
			}
			m--;
			if (direction == RIGHT) direction = DOWN;
			else direction = UP;
		} else {
			for (int i=0; i<m; i++) {
				int d = nums.back(); nums.pop_back();
				if (direction == DOWN) row++;
				else row--;
				matrix[row][col] = d;
			}
			n--;
			if (direction == DOWN) direction = LEFT;
			else direction = RIGHT;
		}
	}
}

int _1105() {
	vector<int> nums;
	vector<vector<int> > matrix;
	int N, d, m, n;
	scanf("%d", &N);
	m = (int)sqrt((double)N);
	n = N/m;
	while (m < n || N % m != 0) {
		m++;
		n = N/m;
	}
	for (int i=0; i<m; i++) matrix.push_back(vector<int>(n));
	for (int i=0; i<N; i++) {
		scanf("%d", &d);
		nums.push_back(d);
	}
	sort(nums.begin(), nums.end());
	putMatrix(nums, matrix, m, n);
	for (int i=0; i<matrix.size(); i++) {
		for (int j=0; j<matrix[i].size(); j++) {
			if (j != 0) printf(" %d", matrix[i][j]);
			else printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	//getchar();getchar();
	return 0;
}