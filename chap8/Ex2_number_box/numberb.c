#include<stdio.h>
int GetResult(int m) {

	int i, j, k;
	j = 3 * m / 5;
	while(j != 0) {
		for(k = 0; k <= m; ++k)
			for(i = 0; i <= m*2/3; ++i) {
				int a1 = 5*j - 3*i;
				int a2 = 3*i + 2*k - 5*j;
				int a3 = 5*j - 2*k;
				if(a2 >= 0 && a1 >= 0 && a3 >= 0
						&& a2 <= m && a3 <= m && a1 <= m)
					return 5*j;
			}
		--j;
	}
	return 0;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	while(n--) {
		int m;
		scanf("%d", &m);
		printf("%d\n", GetResult(m));
	}
}
