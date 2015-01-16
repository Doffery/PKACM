#include<stdio.h>

struct PLANT {
	int x, y;
};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int r, l;
	scanf("%d %d", &r, &l);

	PLANT plants[5000];
	PLANT p; int n = 0;
	while (scanf("%d %d", &p.x, &p.y) != EOF) {
		plants[n++] = p;
	}

	int i, j;
	for(i = 0; i < n; ++i) {
		for(j = i + 1; j < n; ++j) {

		}
	}

	
}
