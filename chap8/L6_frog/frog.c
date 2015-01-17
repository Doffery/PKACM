#include<stdio.h>

typedef struct {
	int x, y;
}PLANT;

int cmp(const void *a, const void *b) {
	PLANT * pa = (PLANT *) a;
	PLANT * pb = (PLANT *) b;
	return pa->x == pb->x ? pa->y - pb->y : pa->x - pb->x;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int r, l;
	scanf("%d %d", &l, &r);

	PLANT plants[5000];
	PLANT p; int n = 0;
	while (scanf("%d %d", &p.x, &p.y) != EOF) {
		plants[n++] = p;
	}

	qsort(plants, n, sizeof(PLANT), cmp);

	int i, j;
	int maxLen = 0;
	for(i = 0; i < n; ++i) {
		for(j = i + 1; j < n; ++j) {
			int dx = plants[j].x - plants[i].x;
			int dy = plants[j].y - plants[i].y;

			int px = plants[i].x - dx;
			int py = plants[i].y - dy;
			if(px >= 1 && px <= l && py >= 1 && py <= r)
				continue;
			PLANT s;
			s.x = plants[j].x + dx;
			s.y = plants[j].y + dy;

			int len = 2;
			while(s.x <= l && s.x > 0 && s.y <= r && s.y > 0) {	
				if(bsearch(&s, plants, n, sizeof(PLANT), cmp)) {
					++len;
					s.x += dx;
					s.y += dy;
				} else {
					len = 0;
					break;
				}
					
			}
			if(maxLen < len)
				maxLen = len;
		}
	}

	printf("%d", maxLen);
	return 0;
}
