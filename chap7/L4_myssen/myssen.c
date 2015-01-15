#include<stdio.h>
#include<string.h>
#include<math.h>

#define LEN 125

void Mutiply(int *a, int *b) {
	int i, j;
	int nCarry;
	int nTmp;
	int c[LEN];
	memset(c, 0, sizeof(int)*LEN);
	for(i = 0; i < LEN; ++i) {
		nCarry = 0;
		for(j = 0; j < LEN-i; ++j) {
			nTmp = c[i+j] + a[j]*b[i] + nCarry;
			c[i+j] = nTmp % 10000;
			nCarry = nTmp / 10000;
		}
	}
	memcpy(a, c, LEN*sizeof(int));
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int num;
	scanf("%d", &num);

	int i;
	printf("%d\n", (int)(num*log10(2))+1);

	int anPow[LEN];
	int aResult[LEN];

	anPow[0] = 2;
	aResult[0] = 1;

	//memset(anPow + 1, 0, sizeof(int) * (LEN - 1));
	//memset(aResult + 1, 0, sizeof(int) * (LEN - 1));
	for(i = 1; i < LEN; ++i) {
		anPow[i] = 0;
	aResult[i] = 0;
	}


	while(num > 0) {
		if(num & 1)
			Mutiply(aResult, anPow);
		num >>= 1;
		Mutiply(anPow, anPow);
	}
	
	--(aResult[0]);

	for(i = LEN-1; i >= 0; --i) {
		if(i % 25 == 12)
			printf("%02d\n%02d", aResult[i]/100, aResult[i]%100);
		else {
			printf("%04d", aResult[i]);
			if(i % 25 == 0)
				printf("\n");
		}
	}
	
	return 0;
}
