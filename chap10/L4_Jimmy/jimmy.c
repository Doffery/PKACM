#include<stdio.h>
#include<memory.h>
#include<stdbool.h>

#define INFINITE 20000000

typedef struct {
	int x1, x2, h;
} Platform;

Platform platforms[1010];
unsigned leftMinTime[1010];
unsigned rightMinTime[1010];

int cmp(const void *a, const void *b) {
	return ((Platform *) b)-> h - ((Platform *) a)->h;
}

int n, x, y, max;

int MinTime() {
}


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &n, &x, &y, &max);
		int i;
		for(i = 1; i < n + 1; ++i) {
			Platform p;
			scanf("%d %d %d", &p.x1, &p.x2, &p.h);

			platforms[i] = p;
		}
		platforms[0].x1 = x;
		platforms[0].x2 = x;
		platforms[0].h = y;
		//platforms[i].x1 = 0;
		//platforms[i].x2 = 20000;
		//platforms[i].h = 0;

		qsort(platforms, n, sizeof(Platform), cmp);

		unsigned min = (unsigned)(-1);
		int platIndex = 1;

		memset(leftMinTime, -1, sizeof(leftMinTime));
		memset(rightMinTime, -1, sizeof(rightMinTime));
		leftMinTime[0] = 0;
		rightMinTime[0] = 0;
		for(i = 0; i < n + 1; ++i) {
			if(leftMinTime[i] == (unsigned)-1)
				continue;
			int j;
			bool getLeft = false;
			bool getRight = false;
			for(j = platIndex; j < n + 2; ++j) {
				if(i == j)
					continue;
				if(platforms[i].h - platforms[j].h > max)
					break;

				if(getLeft && getRight)
					break;

				int px1 = platforms[i].x1;
				int px2 = platforms[i].x2;
				int ph = platforms[i].h;
				int dh = ph - platforms[j].h;
				if(j == n + 1) {
					if(dh + leftMinTime[i] < min) min = dh + leftMinTime[i];
					if(dh + rightMinTime[i] < min) min = dh + rightMinTime[i];
					continue;
				}
				if(!getLeft && platforms[j].x1 <= px1 && platforms[j].x2 >= px1) {
					getLeft = true;
					int tl = px1 - platforms[j].x1;
					int tr = platforms[j].x2 - px2;
					if(tl + leftMinTime[i] < leftMinTime[j]) leftMinTime[j] = tl + leftMinTime[i] + dh;
					if(tr + leftMinTime[i] < rightMinTime[j]) rightMinTime[j] = tr + leftMinTime[i] + dh;
				}
				
				if(!getRight && platforms[j].x1 <= px2 && platforms[j].x2 >= px2) {
					getRight = true;
					int tl = dh + px1 - platforms[j].x1;
					int tr = dh + platforms[j].x2 - px2;
					if(tl + rightMinTime[i] < leftMinTime[j]) leftMinTime[j] = tl + rightMinTime[i];
					if(tr + rightMinTime[i] < rightMinTime[j]) rightMinTime[j] = tr + rightMinTime[i];
				}
			}
			platIndex = j - 1;
		}
		printf("%d\n", min);
	}


}
