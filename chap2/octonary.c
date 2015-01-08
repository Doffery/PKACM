#include<stdio.h>
#include<string.h>
#include<math.h>


int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	char oin[16], dout[44]; dout[0] = '0'; dout[1] = '.';
	long long res;
	while(scanf("%s", oin) != EOF) {
		res = 0;
		int len = strlen(oin);
		res = (oin[len - 1] - '0') * 125;
		int i = len - 2;
		for(; i >= 2; --i) {
			int j = oin[i] - '0';
			int t = 3*(len - i - 1);
			//res += j * (pow(10.0, t)) * 125;
			res = (res + j * (pow(10.0, t))) * 125;
		}
		long long rt = res;
		int x = res % 10;
		int doutIndex = 2 + 3 * (len - 2);
		dout[doutIndex--] = '\0';
		while (rt != 0) {
			rt = rt / 10;
			dout[doutIndex--] = x + '0';
			x = rt % 10;
		}
		while(doutIndex > 1)
			dout[doutIndex--] = '0';
		printf("%s\n", dout);
	}
	return 0;
}
