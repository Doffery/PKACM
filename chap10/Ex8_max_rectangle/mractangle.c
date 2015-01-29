#include<stdio.h>

int data[100][100];

int value[100];


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	int i, j, max = -127;
	value[0] = -1;
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
			scanf("%d", &data[i][j]);
	for(i = 0; i < n - 1; ++i)
		for(j = i + 1; j < n; ++j) {
			int m;
			for(m = 0; m < n; ++m) {
				int p = i, st = 0;
				for(; p <= j; ++p)
					st += data[m][p];
				value[m + 1] = (value[m] > 0 ? value[m] : 0) + st;
				if(max < value[m + 1])
					max = value[m + 1];
			}

		}
	printf("%d\n", max);
}
