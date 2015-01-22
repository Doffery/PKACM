#include<stdio.h>
#include<string.h>
#include<math.h>
#include<memory.h>

//1000 per entry
int result[21];
void Multiply125() {
	int i;
	int carry = 0;
	for(i = 0; i < 20; ++i) {
		result[i] *= 125;
		result[i] += carry;
		carry = result[i] / 1000;
		if(carry) {
			result[i] = result[i] % 1000;
		}
	}
}

int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	char oin[16];

	while(scanf("%s", oin) != EOF) {
		memset(result, 0, sizeof(result));

		int len = strlen(oin);
		result[0] = (oin[len - 1] - '0') * 125;
		int i = len - 2;
		for(; i >= 2; --i) {
			int j = oin[i] - '0';
			int t = 3*(len - i - 1);
			result[len - i - 1] += j;
			Multiply125();
			
		}
		printf("%s [8] = 0.", oin);
		for(i = len - 3; i >= 0; --i) {
			printf("%03d", result[i]);
		}
		printf(" [10]\n");
	}
	return 0;
}
