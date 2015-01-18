#include<stdio.h>
#include<stdbool.h>

int sticks[100];
bool sticksB[100];
int sn;
int cmp(const void * a, const void * b) {
	return * ((int *)a) - * ((int *)b);
}

bool check() {
	int i;
	for(i = 0; i < sn; ++i) {
		if(!sticksB[i])
			return false;
	}
	return true;
}

void reset() {
	int i;
	for(i = 0; i < sn; ++i) {
		sticksB[i] = true;
	}
}

/*
   *params no: number original
 */
bool test(int len, int no) {
	if(len == 0)
		return true;
	if(no ==  0 && check()) {
		return true;
	}
	if(no == 1) {
		
		int i = sn;
		while (sticks[--i] > len);
		for(i; i >= 0 ; --i) {
			if(sticksB[i]) {
				if(test(len - sticks[i], 1)) {
					sticksB[i] = false;
					return true;
				}
			}
		}
		return false;
	}
	else {
		if(test(len, 1) && test(len, no - 1))
			return true;
		return false;
	}
}


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (scanf("%d", &sn) != EOF) {
		int i;
		int lenSum = 0;
		for (i = 0; i < sn; ++i) {
			scanf("%d", &sticks[i]);
			lenSum += sticks[i];
			sticksB[i] = true;
		}
		qsort(sticks, sn, sizeof(int), cmp);

		int len = sticks[sn - 1];
		while (len < 51) {
			if(lenSum % len != 0) {
				++len;
				continue;
			}
			if(test(len, lenSum/len))
				break;
			reset();
		}
		printf("%d\n", len);
	}
}
