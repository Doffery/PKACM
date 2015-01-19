#include<stdio.h>
#include<stdbool.h>
int num[4];
int order[3];
bool divideZero = false;
float Caculate(int n) {
	if(n == 3)
		return num[3];
	float c = Caculate(n + 1);
	switch (order[n]) {
		case 1:
			return num[n] + c;
		case 2:
			return num[n] - c;
		case 3:
			return num[n] * c;
		case 4:
			if(!c) {
				divideZero = true;
				return 0;
			} else return num[n] / c;
	}

}


bool ReOrder2(int n) {
	if(n == 3) {
		if((int)Caculate(0) == 24 && !divideZero) {
			divideZero = false;
			return true;
		}
		divideZero = false;
		return false;
	}
	int i;
	for(i = 1; i < 5; ++i) {
		order[n] = i;
		if(ReOrder2(n + 1))
			return true;
	}
	return false;
}


bool ReOrder(int n) {
	if(n == 3) {
		return ReOrder2(0);
	}
	int i;
	for(i = n; i < 4; ++i) {
		int t = num[n];
		num[n] = num[i];
		num[i] = t;
		if(ReOrder(n + 1))
			return true;
		num[i] = num[n];
		num[n] = t;
	}
	return false;
}


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3])
			&& (num[0] != 0 || num[1] != 0 || num[2] != 0 || num[3] != 0)) {
		if(ReOrder(0))
			printf("YES\n");
		else printf("NO\n");
	}
}
