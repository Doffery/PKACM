#include<stdio.h>

int time[11];
int value[11];
int vs[11][1010];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t, m;
	scanf("%d %d", &t, &m);

	int i;
	int j;
	for(i = 1; i < m + 1; ++i) {
		scanf("%d %d", &time[i], &value[i]);
	}
	for(i = 0; i <= m; ++i)
		for(j = 0; j <= t; ++j)
			vs[i][j] = 0;
	for(i = 1; i < m + 1; ++i) {
		for(j = 1; j < t + 1; ++j) {
			if(j < time[i])
				vs[i][j] = vs[i - 1][j];
			else {
				if(vs[i - 1][j] > vs[i - 1][j - time[i]] + value[i])
					vs[i][j] = vs[i - 1][j];
				else vs[i][j] = vs[i - 1][j - time[i]] + value[i];
			}
		}
	}
	printf("%d\n",  vs[m][t]);
}
